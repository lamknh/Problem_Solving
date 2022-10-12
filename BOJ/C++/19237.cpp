#include <iostream>
#include <cstring> // memset, memcpy
#include <vector>

using namespace std;

int N, M, k;
int A[21][21]; // 상어 위치 표시
int temp[21][21] = {0}; // 상어 이동 후 임시 저장

struct MAP{
  int sharkNum; // 상어 번호
  int cnt; // 냄새 cnt
};

MAP check[21][21] = {0}; // 좌표에 따른 상어 냄새 정보

// 우선순위 1 2 3 4 위, 아래, 왼쪽, 오른쪽
struct SHARK {
  int y; int x;
  int dir; // 현재 방향
  int pri[5][4]; // 방향 우선순위
  bool live; // 상어 쫓겨남 여부
};
SHARK shark[401]= {0};

// 우선순위 1 2 3 4 위, 아래, 왼쪽, 오른쪽
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, -1, 1, 0, 0};

int rest; // 남은 상어 수

int sec = 0; // 1,000초가 넘어도 다른 상어가 격자에 남아 있으면 -1을 출력

void sharkMove(){  
  // 1초마다 모든 상어가 동시에 상하좌우로 인접한 칸 중 하나로 이동하고, 자신의 냄새를 그 칸에 뿌린다.
  sec++;

  for(int i = 1; i <= M; i++){
    int x = shark[i].x;
    int y = shark[i].y;
    int d = shark[i].dir;

    bool flag = false; // 냄새 없는 칸에서 이동했는지 여부 체크

    // 쫓겨난 상어면 탐색 x
    if(!shark[i].live){
      continue;
    }

    for(int j = 0; j < 4; j++){
      // 상어 i의 방향 d일 때 
      // 이때 가능한 칸이 여러 개일 수 있는데, 그 경우에는 특정한 우선순위를 따른다.
      // 우선순위에 따라서 탐색하게 했으니까 가능한 경우 바로 이동시키면 됨
      int nd = shark[i].pri[d][j];
      int nx = x + dx[nd];
      int ny = y + dy[nd];

      // 맵에서 벗어난 경우 패스
      if(nx < 0 || ny < 0 || nx >= N || ny >= N){
        continue;
      }

      // 상어가 이동 방향을 결정할 때는, 먼저 인접한 칸 중 아무 냄새가 없는 칸의 방향으로 잡는다.
      if(check[ny][nx].cnt == 0){
        // 모든 상어가 이동한 후 한 칸에 여러 마리의 상어가 남아 있으면,
        // 가장 작은 번호를 가진 상어를 제외하고 모두 격자 밖으로 쫓겨난다.
        flag = true;

        // 이미 이동한 상어 없는 경우 그냥 값 집어넣음
        if(temp[ny][nx] == 0){
          temp[ny][nx] = i;
          shark[i].x = nx; shark[i].y = ny; // 상어 위치 변경
          shark[i].dir = nd;
        } else {
          // 이미 더 강한 상어 존재하는 경우
          // 강한 상어부터 반복문 돌기 때문에 temp에 값 있으면 더 강한 상어이다
          rest--;
          shark[i].live = false; // 쫓겨남 표시
        }
        break;
      }
    }

    if(!flag){
      // 그런 칸이 없으면 자신의 냄새가 있는 칸의 방향으로 잡는다.
      for(int j = 0; j < 4; j++){
        int nd = shark[i].pri[d][j];
        int nx = x + dx[nd];
        int ny = y + dy[nd];

        if(nx < 0 || ny < 0 || nx >= N || ny >= N){
          continue;
        }

        if(check[ny][nx].sharkNum == i){
          if(temp[ny][nx] == 0){
            temp[ny][nx] = i;
            shark[i].x = nx; shark[i].y = ny; 
            shark[i].dir = nd;
          } else {
            rest--;
            shark[i].live = false;
          }
          break;
        }
      }
    }
  }

  // 냄새 -1 해주기 : 상어 이동 끝난 뒤에
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(check[i][j].cnt > 0){
        check[i][j].cnt--;
      }

      // 냄새 없어진 경우
      if(check[i][j].cnt == 0){
        check[i][j].sharkNum = 0; // 냄새 남긴 상어 정보도 삭제해주기
      }
    }
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      // 상어 있는 경우
      if(temp[i][j] != 0){
        check[i][j].sharkNum = temp[i][j];
        check[i][j].cnt = k;
      }
    }
  }

  memcpy(A, temp, sizeof(A)); // 이동 후 결과 맵에 저장
  memset(temp, 0, sizeof(temp)); // 이동 후 맵 초기화
}

int main(){
  scanf("%d %d %d", &N, &M, &k);

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      scanf("%d", &A[i][j]);

      if(A[i][j] != 0){
        // 상어 위치 저장
        shark[A[i][j]].x = j;
        shark[A[i][j]].y = i;
        shark[A[i][j]].live = true; // 상어 살아있음을 표시

        // 상어 냄새
        check[i][j].sharkNum = A[i][j];
        check[i][j].cnt = k; // 냄새 k번 이동하면 사라짐
      }
    }
  }

  // 각 상어의 방향이 차례대로 주어진다
  for(int i = 1; i <= M; i++){
    scanf("%d", &shark[i].dir);
  }

  // 각 상어의 방향 우선순위
  for(int i = 1; i <= M; i++){
    // 위 : 1부터 시작하기 때문에
    for(int j = 1; j <= 4; j++){
      for(int k = 0; k < 4; k++){
        scanf("%d", &shark[i].pri[j][k]);
      }
    }
  }

  rest = M;

  // 상어 1마리 초과 남아있는 경우
  while(rest > 1){
    sharkMove();

    // 1,000초가 넘어도 다른 상어가 격자에 남아 있으면 -1을 출력한다.
    if(sec > 1000){
      printf("-1");
      return 0;
    }
  }

  printf("%d", sec);

  return 0;
}