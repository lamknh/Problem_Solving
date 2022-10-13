#include <iostream>
#include <queue> // BFS
#include <cstring> // memset
#include <utility> // pair

using namespace std;

int N, M;
int A[21][21]; // 0은 빈칸, 1은 벽
int temp[21][21] = {0}; // 거리 맵에 임시 저장 

struct INFO {
  int x, y;
  int destX, destY;
  bool moved = false; // 승객 목적지 도착 여부
};

INFO p[401]; // 승객 정보 저장

struct CAR {
  int x, y;
  int gas;
};

CAR car; // 자동차 정보 저장

queue<pair<int, int> > q; // BFS 탐색할 자동차 정보 저장 - CAR 정보 저장 x

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 택시에서부터 거리 구하는 BFS
void BFS(){
  memset(temp, -1, sizeof(temp)); // temp 초기화
  q.push({car.y, car.x}); // 자동차 좌표 저장
  temp[car.y][car.x] = 0; // 방문 못한 곳 체크 위해서 

  while(!q.empty()){
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      // 범위 벗어나는 경우
      if(nx < 1 || ny < 1 || nx > N || ny > N){
        continue;
      }

      // 방문되지 않았고 벽이 아니면
      if(temp[ny][nx] == -1 && A[ny][nx] != -1){
        temp[ny][nx] = temp[y][x] + 1; // cnt 변수 쓰지 않고 전 값 사용
        q.push({ny, nx});
      }
    }
  }
}

int main(){
  scanf("%d %d %d", &N, &M, &car.gas);

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      scanf("%d", &A[i][j]);

      // 손님 번호 맵에 저장 위해서 벽 -1로 변경
      if(A[i][j] == 1){
        A[i][j] = -1;
      }
    }
  }

  // 자동차, 행 / 렬 주어짐
  scanf("%d %d", &car.y, &car.x);

  for(int i = 1; i <= M; i++){
    // 각 승객의 출발지의 행과 열 번호, 그리고 목적지의 행과 열 번호
    scanf("%d %d %d %d", &p[i].y, &p[i].x, &p[i].destY, &p[i].destX);
    A[p[i].y][p[i].x] = i; // 현재 고객 위치 맵에 저장
  }

  // 승객 수만큼만 왔다갔다하면 됨
  for(int j = 1; j <= M; j++){
    // 자동차에서부터 맵 전체 거리 구하기
    BFS();
    // 가장 가까운 승객 구하기
    int minIdx = 0;
    int minDistance = 99999999;

    for(int i = 1; i <= M; i++){
      // 이미 도착지까지 이동된 손님이면 패스
      if(p[i].moved){
        continue;
      }

      int py = p[i].y;
      int px = p[i].x;

      // 승객 거리 가장 작은 것 구함
      if(temp[py][px] < minDistance){
        minIdx = i;
        minDistance = temp[py][px];
      } else if(temp[py][px] == minDistance){
        // 거리 같은 경우, 행번호 작은 승객 먼저, 그 다음에는 열번호 작은 승객
        if(p[minIdx].y > py){
          minIdx = i;
        } else if(p[minIdx].y == py && p[minIdx].x > px){
          minIdx = i;
        }
      }    
    }

    // 고객태우기
    int px = p[minIdx].x; // 고객 좌표
    int py = p[minIdx].y;
    int pdx = p[minIdx].destX;
    int pdy = p[minIdx].destY;

    car.x = px;
    car.y = py;

    // 승객에게 갈 수 없는 경우
    if(temp[py][px] == -1){
      printf("-1");
      return 0;
    }
    car.gas -= temp[py][px]; // 승객까지의 거리만큼 가스 없어짐

    // 연료 없는 경우
    if(car.gas < 0){
      printf("-1");
      return 0;
    }

    // 자동차로부터 모든 칸의 거리 구하기
    BFS();

    // 목적지로 갈 수 없는 경우
    if(temp[pdy][pdx] == -1){
      printf("-1");
      return 0;
    }

    // 자동차 목적지로 이동
    car.gas -= temp[pdy][pdx];

    // 자동차 연료 부족하면 끝
    if(car.gas < 0){
      printf("-1");
      return 0;
    }

    // 연료 부족하지 않은 경우
    car.x = pdx; car.y = pdy;
    car.gas += temp[pdy][pdx] * 2; // 연료 이동거리 2배 충전
    p[minIdx].moved = true; // 승객 이동 체크
  }
  printf("%d", car.gas);

  return 0;
}