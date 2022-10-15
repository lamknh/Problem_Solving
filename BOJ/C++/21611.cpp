#include <iostream>
#include <vector>
#include <cstring> // memset

using namespace std;

int N, M;
int A[50][50];

vector<int> v; // 재배열할 구슬들 저장

int d, s; // 방향, 거리
int sharkX, sharkY;

// 블리자드 마법 4가지 방향 ↑, ↓, ←, →
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

// 좌표평면 도는 방향 좌 하 우 상
int ddx[4] = {-1, 0, 1, 0};
int ddy[4] = {0, 1, 0, -1};

int score = 0;

void move(){
  // 구슬 넣어줄 벡터 초기화
  v.clear();

  int distance = 1;
  int nx = sharkX; int ny = sharkY;
  d = 0; // 왼쪽 방향부터 좌표 평면 돌기 시작
  int cnt = 0; int maxCnt = N * N - 1; // 격자 모든 칸 돌기

  // 격자 끝까지 탐색
  // 벡터를 이용해서 빈칸이 아닌 경우만 벡터에 저장해서 폭발 후 재배열 시켜줄 것임.
  // 13퍼 에러는 이거 에러
  while(1){
    for(int i = 0; i < 2; i++){
      for(int j = 0; j < distance; j++){
        nx += ddx[d];
        ny += ddy[d];

        cnt++;

        if(nx < 0 || ny < 0 || nx >= N || ny >= N){
          continue;
        }

        if(A[ny][nx] > 0){
          v.push_back(A[ny][nx]);
        }
      }
      if(cnt >= maxCnt){
        break;
      }
      d = (d + 1) % 4; // 다음 방향으로 이동
    }
    if(cnt >= maxCnt){
      break;
    }
    distance++; // 2번마다 길이 늘어남
  }
}

void explore(){
  // 벡터에 구슬 저장되어 있기 때문에 4개 이상 연속하는 구슬 찾기 쉬움.
  bool flag = true; // 폭발한 후에도 또 폭발할 것 있으면 폭발해야함

  while(flag){
    flag = false; // 아직 폭발한 것 없음
    vector<int> tmp; // 벡터 내의 구슬을 터뜨리지 말고 임시 배열에 안 터진 구슬을 저장시키기

    if(v.size() == 0){
      return;
    }
    
    for(int i = 0; i < v.size(); i++){
      int next = i; // 바로 다음 인덱스 x out of bound

      if(v[i] != v[next]){
        tmp.push_back(v[i]);
      } else {
        // 범위 안에서 같은 경우 모두 탐색
        while(v[i] == v[next] && next < v.size()){
          next++;
        }

        // 4개 이하인 경우 (next++ 라서 next - i + 1 아님)
        if(next - i < 4){
          for(int j = i; j < next; j++){
            tmp.push_back(v[j]); // 안터진 구슬 저장
          }
        } else {
          // 1×(폭발한 1번 구슬의 개수) + 2×(폭발한 2번 구슬의 개수) + 3×(폭발한 3번 구슬의 개수)
          score += v[i] * (next - i);
          flag = true; // 구슬 폭발함
        }
      }
      i = --next; // idx 업데이트
    }
    v = tmp; // 임시 배열 값 구슬 값으로 재저장 copy 그냥 이렇게
  }
}

void change(){
  vector<int> tmp;

  if(v.size() == 0){
    return;
  }

  for(int i = 0; i < v.size(); i++){
    int next = i; // 다음 인덱스 구할 것

    while(v[i] == v[next] && next < v.size()){
      next++;
    }
    // 개수
    tmp.push_back(next - i);
    // 그룹을 이루고 있는 구슬의 번호
    tmp.push_back(v[i]);

    // 구슬이 칸의 수보다 많아 칸에 들어가지 못하는 경우 그러한 구슬은 사라진다.
    // >=
    if(tmp.size() >= N * N){
      while(tmp.size() >= N * N){
        tmp.pop_back();
      }
    }
    i = --next;
  }
  v = tmp;
}

void mapSet(){
  memset(A, 0, sizeof(A));
  int nx = sharkX; int ny = sharkY;
  int d = 0; // 맵도는 방향부터 시작
  int distance = 1;
  int idx = 0; // vector idx

  if(v.size() == 0){
    return;
  }

  while(1){
    for(int i = 0; i < 2; i++){
      for(int j = 0; j < distance; j++){
        nx += ddx[d];
        ny += ddy[d];

        if(nx < 0 || ny < 0 || nx >= N || ny > N){
          continue;
        }

        A[ny][nx] = v[idx];
        idx++;

        if(idx == v.size()){
          return;
        }
      }
      d = (d + 1) % 4;
    }
    distance++;
  }
}

int main(){
  scanf("%d %d", &N, &M);

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      scanf("%d", &A[i][j]);
    }
  }

  // 상어 위치 저장 맵 (0, 0)부터 시작
  sharkX = N / 2; sharkY = N / 2;

  for(int i = 0; i < M; i++){
    scanf("%d %d", &d, &s);
    d--; // 방향 인덱스 0부터 시작하기 때문에

    // 구슬 파괴 - 블리자드 마법
    int nx = sharkX; int ny = sharkY;
    for(int j = 0; j < s; j++){
      nx += dx[d];
      ny += dy[d];
      if(nx < 0 || ny < 0 || nx >= N || ny >= N){
        continue;
      }
      A[ny][nx] = 0;
    }

    // 구슬 이동
    move();
    // 구슬 폭발
    explore();
    // 구슬 변화
    change();
    // 벡터에 저장된 값들 맵에 재저장
    mapSet();
  }

  printf("%d", score);

  return 0;
}