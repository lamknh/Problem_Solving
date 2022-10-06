#include <iostream>
#include <vector>
#include <queue> // BFS
#include <utility> // pair
#include <cstring> // memset

using namespace std;

int N, M, K;
int map[21][21] = {0};
bool visited[21][21] = {false};

vector<int> dice = {0, 1, 2, 3, 4, 5, 6};
int d = 0; // 현재 방향 동:0 서:1 남:2 북:3 (dx, dy 참고)

int r = 0, c = 0; // 다이스 현재 위치
int A, B, C;

int score = 0;

// 점수구하기 탐색
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue<pair<int, int> > q; // y, x

// 점수 구하기 BFS
void BFS(){
  int num = map[r][c];
  C = 1; // 연속해서 이동할 수 있는 칸 수 초기화 - 지금 서 있는 칸 1
  memset(visited, false, sizeof(visited)); // visited 배열 초기화
  q.push({r, c});
  visited[r][c] = true;

  while(!q.empty()){
    int y = q.front().first;
    int x = q.front().second;
    q.pop(); // 까먹지 말기

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 0 || ny < 0 || nx >= M || ny >= N){
        continue;
      }

      if(map[ny][nx] == num && !visited[ny][nx]){
        visited[ny][nx] = true;
        q.push({ny, nx});
        C++;
      }
    }
  }
}

void diceRoll(int d){
  // 값 이상하게 나오면 다이스를 잘 못 위치시킨 것 잘 확인하기
  switch(d){
    // 동
    case 0 : 
      dice = {0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3]};
      break;
    // 서
    case 1 :
      dice = {0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4]};
      break;
    // 남
    case 2 :
      dice = {0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5]};
      break;
    // 북
    case 3 : 
      dice = {0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2]};
      break;
  }
}

// 시계 방향
void rotate(){
  switch(d){
    case 0 : 
      d = 2;
      break;
    case 1 :
      d = 3;
      break;
    case 2 :
      d = 1;
      break;
    case 3 :
      d = 0;
      break;
  }
}

// 반시계 방향
void antiRotate(){
  switch(d){
    case 0 : 
      d = 3;
      break;
    case 1 :
      d = 2;
      break;
    case 2 :
      d = 0;
      break;
    case 3 :
      d = 1;
      break;
  }
}

// 주사위 굴리기
void roll(){
  // d 방향으로 이동
  int nx = c + dx[d];
  int ny = r + dy[d];

  if(nx < 0 || ny < 0 || nx >= M || ny >= N){
    // 이동 방향에 칸이 없다면, 이동 방향을 반대로 한 다음 한 칸 굴러간다
    switch(d){
      case 0 :
        d = 1;
        break;
      case 1 :
        d = 0;
        break;
      case 2 :
        d = 3;
        break;
      case 3 :
        d = 2;
        break;
    }

    nx = c + dx[d];
    ny = r + dy[d];
  }

  r = ny; c = nx;

  // 주사위가 도착한 칸 (x, y)에 대한 점수를 획득
  BFS(); // BFS 탐색으로 인접 칸 같은거 구함

  diceRoll(d); // 주사위 d 방향으로 굴리기 - 전개도 바꾸기

  // 주사위의 아랫면에 있는 정수 A와 주사위가 있는 칸 (x, y)에 있는 정수 B를 비교해 이동 방향을 결정
  A = dice[6]; // 주사위 아랫면
  B = map[r][c]; // 주사위가 있는 칸 정수

  score += B * C;

  if(A > B){
    rotate();
  } else if(A < B){
    antiRotate();
  }
  // A = B이면 방향 변화 없음
}

int main(){
  scanf("%d %d %d", &N, &M, &K);

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      scanf("%d", &map[i][j]);
    }
  }

  for(int i = 0; i < K; i++){
    roll(); // 주사위 이동방향으로 굴러감
  }

  printf("%d", score);

  return 0;
}