#include <iostream>
#include <queue>
#include <vector>
#include <utility> // pair
#include <cmath> // abs

using namespace std;

int N;
int r, c;
int A[51][51];
bool visited[51][51] = {0}; // 방문 체크
int L, R; // 인구차이 L명 이상 R명 이하 - 국경선 엶

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int ans = 0; // 인구 이동 며칠동안 발생하는지

queue<pair<int, int> > q; // 연합 확인용 Bfs 큐
vector<pair<int, int> > v; // 연합 저장 벡터
int sum = 0; // 연합 전체 값 저장

// BFS - 큐 사용
void BFS(){
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 0 || ny < 0 || nx >= N || ny >= N){
        continue;
      }

      if(!visited[nx][ny]){
        // 국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루 동안 연다.
        if(abs(A[nx][ny] - A[x][y]) >= L && abs(A[nx][ny] - A[x][y]) <= R){
          visited[nx][ny] = true; // 방문 체크
          q.push({nx, ny}); // 다음 연계된 좌표 찾기
          sum += A[nx][ny]; // 연합 값 합계
          v.push_back({nx, ny}); // 연합 리스트에 추가
        }
      }
    }
  }
}

void clear(){
  // 방문 여부 초기화
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      visited[i][j] = false;
    }
  }
}

int main(){
  scanf("%d %d %d", &N, &L, &R);

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      scanf("%d", &A[i][j]);
    }
  }

  bool flag = true;

  while(flag){
    flag = false; // 방문되지 않았다고 가정
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        if(!visited[i][j]){
          // 연합 생길 시
          v.clear(); // 연합 리스트 초기화
          v.push_back({i, j}); // 연합 리스트에 넣기
          sum = A[i][j]; // 첫 연합 값으로 sum 초기화
          q.push({i, j});
          visited[i][j] = true;
          BFS();
        }

        // 연합 존재할 경우
        if(v.size() >= 2){
          flag = true; // 연합 존재함 체크
          for(int n = 0; n < v.size(); n++){
            A[v[n].first][v[n].second] = sum / v.size(); // 연합 평균값 저장
          }
        }
      }
    }
    // 국경 열렸으면 하루 지남
    if(flag){
      ans++;
      clear(); // 맵 방문 여부 초기화
    }
  }
  printf("%d", ans);
  return 0;
}