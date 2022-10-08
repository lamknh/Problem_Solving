#include <iostream>
#include <queue> // vector? queue? 구름 저장
#include <cstring> // memset

using namespace std;

int N, M;
int A[51][101];
bool visited[51][101] = {false};
int r, c; // r 행 c 열 - 너무 헷갈리게 문제에 써 둠
int d, s; // d 방향 s 칸

int ans = 0;

// ←, ↖, ↑, ↗, →, ↘, ↓, ↙
int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

struct INFO{
  int r; // 구름 좌표
  int c;
};

queue<INFO> q; // 비구름 저장

// 모든 구름이 di 방향으로 si칸 이동
void move(){
  memset(visited, false, sizeof(visited)); // 구름 초기화

  while(!q.empty()){
    int r = q.front().r;
    int c = q.front().c;
    q.pop(); // 구름이 모두 사라진다.

    // 구름 d방향으로 s만큼 이동
    for(int i = 0; i < s; i++){
      r += dy[d];
      c += dx[d];

      if(r < 1){
        r = N;
      }
      if(c < 1){
        c = N;
      }
      if(r > N){
        r = 1;
      }
      if(c > N){
        c = 1;
      }
    }

    // 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가
    A[r][c]++;
    visited[r][c] = true; // 구름 이동한 곳
  }

  // 물이 증가한 칸일 경우 - 물복사마법
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      if(visited[i][j]){
        // 대각선 방향으로 거리가 1인 칸 - 2, 4, 6, 8
        for(int k = 2; k <= 9; k+=2){
          int nny = i + dy[k];
          int nnx = j + dx[k];

          // 경계를 넘어가는 칸은 대각선 방향으로 거리가 1인 칸이 아니다
          if(nnx < 1 || nny < 1 || nnx > N || nny > N){
            continue;
          }
          
          // 대각선에 물이 있는 바구니의 수만큼 (r, c)에 있는 바구니의 물이 양이 증가
          if(A[nny][nnx]){
            A[i][j]++; // cnt 변수 쓸 필요 없음 굳이?
          }
        }
      }
    }
  }

  // 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다. 이때 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한다.
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      if(A[i][j] >= 2 && !visited[i][j]){
        q.push({i, j});
        A[i][j] -= 2;
      }
    }
  }
}

int main(){
  scanf("%d %d", &N, &M);

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      scanf("%d", &A[i][j]);
    }
  }

  // 비구름 생성 - Y, X
  q.push({N, 1});
  q.push({N, 2});
  q.push({N-1, 1});
  q.push({N-1, 2});

  for(int i = 0; i < M; i++){
    scanf("%d %d", &d, &s);
    move();
  }

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      ans += A[i][j];
    }
  }

  printf("%d", ans);

  return 0;
}