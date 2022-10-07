#include <iostream>
#include <queue> // vector? queue? 구름 저장
#include <cstring> // memset

using namespace std;

int N, M;
int A[51][101];
int visited[51][101] = {false};
int r, c;
int d, s; // d 방향 s 칸

// ←, ↖, ↑, ↗, →, ↘, ↓, ↙
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

struct INFO{
  int x;
  int y; // 구름 좌표
};

queue<INFO> q; // 비구름 저장

// 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다.
// 이때 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한다.
void reduce(){
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= M; j++){
      if(!visited[i][j] && A[i][j] >= 2){
        q.push({j, i});
      }
    }
  }
}

// 모든 구름이 di 방향으로 si칸 이동
void move(){
  memset(visited, false, sizeof(visited));

  while(!q.empty()){
    int x = q.front().x;
    int y = q.front().y;
    q.pop();

    int nx = x;
    int ny = y;

    // 구름 d방향으로 s만큼 이동
    for(int i = 0; i < s; i++){
      nx += dx[d];
      ny += dy[d];

      if(nx < 1){
        nx = M;
      }
      if(ny < 1){
        ny = N;
      }
      if(nx > M){
        nx = 1;
      }
      if(ny > N){
        ny = 1;
      }
    }

    // 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가
    A[ny][nx]++;
    visited[ny][nx] = true; // 물이 증가한 칸 체크
  }

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= M; j++){
      // 물이 증가한 칸일 경우 - 물복사마법
      int cnt = 0;
      if(visited[i][j]){
        for(int k = 0; k < 4; k++){
          int nnx = j + dx[k];
          int nny = i + dy[k];

          // 대각선 방향으로 거리가 1인 칸에 물이 있는 바구니
          if(A[nny][nnx]){
            cnt++;
          }
        }
      }
    }
  }
}

int main(){
  scanf("%d %d", &N, &M);

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= M; j++){
      scanf("%d", &A[i][j]);
    }
  }

  for(int i = 0; i < M; i++){
    scanf("%d %d", &d, &s);

    q.push({N, 1});
    q.push({N, 2});
    q.push({N-1, 1});
    q.push({N-1, 2});

    move();
  }

  return 0;
}