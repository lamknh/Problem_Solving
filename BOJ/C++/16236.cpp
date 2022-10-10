#include <iostream>
#include <cstring> // memset
#include <utility> // pair
#include <queue> // BFS
#include <algorithm> // sort

using namespace std;

struct INFO{
  int x;
  int y;
  int size; // 상어 크기
  int eat; // 먹은 물고기 수
};

int N, M;
int A[21][21];
int distCheck[21][21]; // 상어에서부터 거리 체크

INFO shark;
queue<pair<int, int> > q; // x, y
vector<pair<int, int> > fish; // 먹을 수 있는 물고기 좌표 - 상어가 먹을 수 있는 물고기 수 셈용
int sec = 0;

// 인접한 칸 이동 - 상하좌우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void BFS(){
  while(!q.empty()){
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      // 범위 넘어섰을 경우
      if(nx < 0 || ny < 0 || nx >= N || ny >= N){
        continue;
      }

      // 방문체크
      if(distCheck[ny][nx] != -1){
        continue;
      }

      // 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고
      if(A[ny][nx] > shark.size){
        continue;
      } else if(A[ny][nx] == shark.size || A[ny][nx] == 0){
        // 나머지 칸은 모두 지나갈 수 있다 -  크기가 같은 물고기는 먹을 수 없지만, 그 물고기가 있는 칸은 지나갈 수 있다.
        // 물고기 안 먹고 지나가는 경우
        distCheck[ny][nx] = distCheck[y][x] + 1; // 상어 이동 거리 구하기
        q.push({ny, nx}); // 상어 위치 저장
      } else if(A[ny][nx] < shark.size && A[ny][nx] > 0){
        // 아기 상어는 자신의 크기보다 작은 물고기만 먹을 수 있다
        // 물고기 먹고 지나가는 경우
        distCheck[ny][nx] = distCheck[y][x] + 1; // 상어 이동 거리 구하기
        fish.push_back({ny, nx}); // 먹은 물고기 좌표 벡터에 저장
        q.push({ny, nx}); // 상어 위치 저장
      }
    }
  }
}

int main(){
  scanf("%d", &N);

  // 0: 빈 칸 1, 2, 3, 4, 5, 6: 칸에 있는 물고기의 크기 9: 아기 상어의 위치
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      scanf("%d", &A[i][j]);

      // 아기 상어 위치
      if(A[i][j] == 9){
        shark.x = j;
        shark.y = i;
        shark.size = 2; // 아기상어 크기 처음에 2
        shark.eat = 0; // 먹은 물고기 수 0
      }
    }
  }

  while(1){
    // 아기 상어의 위치 0부터 시작이니까 -1로 초기화
    memset(distCheck, -1, sizeof(distCheck));
    fish.clear(); // 물고기 탐색 벡터 초기화

    distCheck[shark.y][shark.x] = 0; // 현재 상어 위치 거리 0으로 체크
    A[shark.y][shark.x] = 0; // 상어 위치 물고기 크기 0으로 세팅 - 잡아먹음

    q.push({shark.y, shark.x}); // BFS 탐색 위해 상어 큐에 넣기

    // 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가
    if(shark.eat >= shark.size){
      shark.eat -= shark.size; // 상어 크기만큼 물고기 감소 (0으로 초기화 아님)
      shark.size++; // 상어 크기 증가
    }

    // 물고기 먹으러 가기
    BFS();

    // 먹을 수 있는 물고기가 공간에 없다면 아기 상어는 엄마 상어에게 도움을 요청 - 종료
    if(fish.size() == 0){
      printf("%d", sec);
      return 0;
    } else if(fish.size() == 1){
      // 먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다.
      shark.y = fish[0].first;
      shark.x = fish[0].second;
      shark.eat++; // 먹은 물고기 수 체크
      sec += distCheck[shark.y][shark.x]; // 물고기를 먹으러 가는 시간 추가
    } else {
      // 먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다
      int minD = 99999999; // 가장 거리가 가까운 물고기 구하기
      for(int i = 0; i < fish.size(); i++){
        // minD에 다시 저장해줘야 함
        minD = min(minD, distCheck[fish[i].first][fish[i].second]); // 가장 작은 거리 구하기
      }

      vector<pair<int, int> > closest; // 가장 가까운 물고기 수 세기 위한 벡터

      for(int i = 0; i < fish.size(); i++){
        if(distCheck[fish[i].first][fish[i].second] == minD){
          closest.push_back({fish[i].first, fish[i].second}); // y 작은 것 부터 정렬할 필요
        }
      }

      // 거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.
      if(closest.size() > 1){
        sort(closest.begin(), closest.end());
      }
      shark.y = closest[0].first;
      shark.x = closest[0].second;
      shark.eat++; // 먹은 물고기 수 체크
      sec += distCheck[shark.y][shark.x]; // 물고기를 먹으러 가는 시간 추가
    }
  }
}