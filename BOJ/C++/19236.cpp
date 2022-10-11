#include <iostream>
#include <cstring> // memset, memcpy

using namespace std;

struct INFO{
  int x; int y;
  int dir;
  bool live;
};

int A[4][4]; // 물고기 번호 저장, -1은 상어
INFO fish[17]; // 물고기 정보 저장 - 인덱스가 물고기 번호
int ans = 0;

int a, b; // 물고기 번호, 방향

// ↑, ↖, ←, ↙, ↓, ↘, →, ↗ - 반시계 45도 회전 : % 계산 위해서 -1 해서 인덱스사용
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void moveFish(){
  // 1번 ~ 16번 물고기 이동시키기
  for(int i = 1; i <= 16; i++){
    // 죽은 물고기라면 이동 X
    if(!fish[i].live){
      continue;
    }
    
    int x = fish[i].x; int y = fish[i].y;
    int dir = fish[i].dir;

    // 물고기 본인의 방향으로만 이동 가능
    int nx = x + dx[dir]; int ny = y + dy[dir];
    bool flag = false; // 물고기 이동 여부 체크

    // 맵 범위 넘어설 경우
    // continue 쓰면 그냥 조건 넘어버림, for문으로 돌아감 = 다음 물고기 이동시킨다는 뜻
    if(nx >= 0 && ny >= 0 && nx < 4 && ny < 4){
      // 이동할 수 있는 칸은 빈 칸
      if(A[ny][nx] == 0){
        flag = true; // 물고기 움직임
        fish[i].x = nx; fish[i].y = ny; // 물고기 벡터 좌표 바꾸기
        A[ny][nx] = i; A[y][x] = 0; // 물고기 맵에서 인덱스 바꾸기
      } else if(A[ny][nx] != -1){
        // 빈 칸도 아니고 상어가 있는 칸도 아님 = 다른 물고기 있는 칸 : 이동 가능
        flag= true;
        // 물고기 서로 바꾸기 현재 물고기와 그 물고기가 향하는 방향에 있는 물고기
        // 맵 값 서로 swap (함수로 가능)
        swap(fish[i].x, fish[A[ny][nx]].x);
        swap(fish[i].y, fish[A[ny][nx]].y);
        swap(A[ny][nx], A[y][x]);
      }
    }

    // 물고기 움직이지 않은 경우 - 45도 반시계방향 이동 필요
    // flag 따로 써서 체크해야하는 이유 : 범위 벗어나면 방향 전환 해서 계속 탐색해야해서
    // flag 안쓰고 else문으로 붙이면 nx, ny 범위 넘어가면 다음 물고기 탐색
    if(!flag){
      int nd = (dir + 1) % 8; // 새로운 방향

      // 한 바퀴 돌면 종료 - 이동할 수 있는 칸이 없음
      while(nd != dir){
        // 물고기 본인의 방향으로만 이동 가능
        nx = x + dx[nd];
        ny = y + dy[nd];

        // 맵 범위 안에서 - continue 쓰면 반복문 넘어가버림
        if(nx >= 0 && ny >= 0 && nx < 4 && ny < 4){
          // 이동할 수 있는 칸은 빈 칸
          if(A[ny][nx] == 0){
            // true 체크 안 함. 그냥 이동하면 바로 끝내주면 됨.
            fish[i].x = nx; fish[i].y = ny; // 물고기 벡터 좌표 바꾸기
            A[ny][nx] = i; A[y][x] = 0; // 물고기 맵에서 인덱스 바꾸기
            fish[i].dir = nd; // 물고기 방향 바꿔주기
            break;
          } else if(A[ny][nx] != -1){
            // 빈 칸도 아니고 상어가 있는 칸도 아님 = 물고기 있는 칸

            // 물고기 서로 바꾸기 현재 물고기와 그 물고기가 향하는 방향에 있는 물고기
            // 맵 값 서로 swap (함수로 가능)
            swap(fish[i].x, fish[A[ny][nx]].x);
            swap(fish[i].y, fish[A[ny][nx]].y);
            swap(A[ny][nx], A[y][x]);
            fish[i].dir = nd; // 물고기 방향 바꿔주기
            break;
          }
        }

        // 물고기 이동 못했다면 반시계방향으로 돌기
        nd = (nd + 1) % 8;
      }
    }
  }
}

// 상어 움직임 체크를 위한 백트래킹 DFS
// 현재 상어 좌표와 방향, 백트래킹을 위한 물고기 번호 합 최댓값
void DFS(int y, int x, int dir, int sum){
  ans = max(ans, sum); // 합이 최댓값인 경우 갱신(DFS 백트래킹이므로)

  int tempA[4][4]; // 현재 물고기 위치 저장할 임시 배열
  INFO tempF[17]; // 현재 물고기 좌표 저장할 임시 배열

  // 백트래킹을 위한 기존 맵 정보와 물고기 정보 따로 저장
  memcpy(tempA, A, sizeof(A)); // dest, src, size
  memcpy(tempF, fish, sizeof(fish));

  moveFish(); // 물고기 움직이기

  // 상어 움직일 수 있는 칸 수 1 ~ 3칸
  for(int i = 1; i <= 3; i++){
    int nx = x + dx[dir] * i;
    int ny = y + dy[dir] * i;

    // 범위 벗어나는 경우
    if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4){
      continue;
    }

    // 잡아먹을 물고기 없음
    if(A[ny][nx] == 0){
      continue;
    }
    // 잡아먹을 물고기 있음
    int fishNum = A[ny][nx];
    int fishDir = fish[fishNum].dir;

    // 방문 체크
    A[y][x] = 0; A[ny][nx] = -1; // 상어 위치 변경
    fish[fishNum].live = false; // 물고기 잡아먹힘
    DFS(ny, nx, fishDir, sum + fishNum);
    // 방문 체크 해제
    A[y][x] = -1; A[ny][nx] = fishNum;
    fish[fishNum].live = true;
  }
  // 기존 맵 정보 다시 돌려두기
  memcpy(A, tempA, sizeof(A)); // dest, src, size
  memcpy(fish, tempF, sizeof(fish));
}

int main(){
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      scanf("%d %d", &a, &b);

      A[i][j] = a; // 맵에는 번호를 저장
      fish[a] = {j, i, b-1, true}; // x, y, dir, live
    }
  }

  // (0, 0)에 있는 물고기를 먹고, (0, 0)에 들어가게 된다
  int fishNum = A[0][0];
  int fishDir = fish[fishNum].dir;
  fish[fishNum].live = false; // 물고기 먹힘
  A[0][0] = -1; // 상어 저장
  // 상어의 방향은 (0, 0)에 있던 물고기의 방향과 같다
  DFS(0, 0, fishDir, fishNum);

  printf("%d\n", ans);

  return 0;
}