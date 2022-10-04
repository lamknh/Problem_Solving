#include <iostream>
#include <cmath>
#include <cstring> //memset

using namespace std;

int N, Q;
int r, c;
int A[65][65], temp[65][65]; // 2^6 - 맵, 시계방향회전 임시 저장 배열
bool visited[65][65] = {false}; // DFS 방문여부 저장
bool melt[65][65] = {false}; // 얼음 녹는 것 체크
int L;

int sum = 0; // 남아있는 얼음 A[r][c]의 합
int bigIce = 0; // 남아있는 얼음 중 가장 큰 덩어리가 차지하는 칸의 개수
int iceSize = 0; // 얼음 크기 세기

// 인접 칸
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 격자 시계방향 회전 - 외우기
void rotate(int y, int x, int L){
  for(int i = 0; i < L; i++){
    for(int j = 0; j < L; j++){
      // temp도 A 범위에 맞출 필요 x
      // 전체 N 아니고 L임 L 범위에서 회전이니까
      temp[j][L-i-1] = A[y+i][x+j]; // 회전시켜서 저장
    }
  }

  for(int i = 0; i < L; i++){
    for(int j = 0; j < L; j++){
      A[y+i][x+j] = temp[i][j]; // 저장된 값을 다시 옮기기
    }
  }
}

void fireStorm(){
  L = pow(2, L);

  // 2^L × 2^L 크기의 부분 격자 += L로 구함
  for(int i = 0; i < N; i+=L){
    for(int j = 0; j < N; j+=L){
      // 모든 부분 격자를 시계 방향으로 90도 회전 
      rotate(i, j, L);
    }
  }

  memset(melt, false, sizeof(melt)); // melt 배열 초기화

  // 얼음이 있는 칸 3개 또는 그 이상과 인접해있지 않은 칸은 얼음의 양이 1 줄어든다
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      int ice = 0; // 얼음 수 세기
      
      // 얼음 없는 칸이면 패스
      if(A[i][j] == 0){
        continue;
      }
      // 얼음 있으면
      for(int k = 0; k < 4; k++){
        int ny = i + dy[k];
        int nx = j + dx[k];

        // 항상 범위 체크하기
        if(ny < 0 || nx < 0 || ny >= N || nx >= N){
          continue;
        }

        // 얼음이 있는 칸
        if(A[ny][nx] > 0){
          ice++;
        }
      }

      // 얼음이 있는 칸 3개 또는 그 이상과 인접해있지 않은 칸은 얼음의 양이 1 줄어든다
      if(ice < 3){
        melt[i][j] = true; // 연쇄적으로 주는 것 아님! 한번에 얼음이 녹는 것.
      }
    }
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(melt[i][j]){
        A[i][j]--; // 얼음 1개 녹이기
      }
    }
  }
}

void DFS(int y, int x){
  // 얼음이 있는 칸이 얼음이 있는 칸과 인접해 있으면, 두 칸을 연결되어 있다고 한다
  iceSize++; // 얼음 덩어리 크기 세기
  
  for(int i = 0; i < 4; i++){
    int ny = y + dy[i];
    int nx = x + dx[i];

    if(nx < 0 || ny < 0 || nx >= N || ny >= N){
      continue;
    }

    // 인접 칸이 얼음이 있으면
    if(A[ny][nx] > 0 && !visited[ny][nx]){
      visited[ny][nx] = true; // 방문 체크
      DFS(ny, nx); // 다음 칸 탐색
    }
  }
}

int main(){
  scanf("%d %d", &N, &Q);

  N = pow(2, N); // 2^N (이런 경우는 pow 대신 비트 << 연산을 쓰는 것이 편하다)

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      scanf("%d", &A[i][j]);
    }
  }

  for(int i = 0; i < Q; i++){
    scanf("%d", &L);
    fireStorm();
  }

  // 남아있는 얼음 A[r][c]의 합
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      sum += A[i][j];
    }
  }

  // 남아있는 얼음 중 가장 큰 덩어리가 차지하는 칸의 개수 - DFS/BFS로 탐색
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(A[i][j] > 0 && !visited[i][j]){
        visited[i][j] = true;
        DFS(i, j); // 해당 칸 얼음 있음
        bigIce = max(bigIce, iceSize);
        iceSize = 0; // 얼음 크기 초기화
      }
    }
  }

  printf("%d\n", sum);
  printf("%d\n", bigIce);

  return 0;
}