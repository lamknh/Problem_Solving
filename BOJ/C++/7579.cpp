#include <iostream>
#include <utility> //pair
#include <queue>
using namespace std;

int map[101][101][101]; // 1 : 익은 토마토, 0 : 익지 않은 토마토, -1 : 토마토 없음
queue<pair<pair<int, int>, int> > q; // h, y, x

// 상하좌우위아래 탐색
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};

bool allTomato = true; // 모든 토마토 익어있는 경우

int M, N, H; // 가로, 세로, 높이
int cnt = 0; // 토마토 모두 익을 때 까지 걸리는 시간

void BFS(){
  while(!q.empty()){
    int x = q.front().second; 
    int y = q.front().first.second;
    int h = q.front().first.first; // 노드의 좌표 구하기
    q.pop();

    for(int i = 0; i < 6; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      int nh = h + dh[i];

      if(nx < 1 || ny < 1 || nh < 1 || nx > M || ny > N || nh > H){
        continue;
      }

      if(map[nh][ny][nx] == 0){ // 안익은 토마토가 있을 때
        map[nh][ny][nx] = map[h][y][x] + 1; // 날짜 더하기
        q.push({{nh, ny}, nx});
      }
    }
  }
}

int main(int argc, char* argv[]){
  scanf("%d %d %d", &M, &N, &H);

  for(int i=1; i<=H; i++){
    for(int j=1; j<=N; j++){
      for(int k=1; k<=M; k++){
        scanf("%d", &map[i][j][k]); // 입력받기
        if(map[i][j][k] == 1){ // 익은 토마토일 때
          q.push({{i, j}, k});
        } else if(map[i][j][k] == 0){
          allTomato = false;
        }
      }
    }
  }

  if(allTomato){ // 처음부터 모든 토마토 익어있는 경우
    printf("0");
    return 0;
  }

  BFS();

  // for(int i=1; i<=H; i++){
  //   for(int j=1; j<=N; j++){
  //     for(int k=1; k<=M; k++){
  //       printf("%d ", map[i][j][k]);
  //     }
  //     printf("\n");
  //   }
  // }

  for(int i=1; i<=H; i++){
    for(int j=1; j<=N; j++){
      for(int k=1; k<=M; k++){
        if(map[i][j][k] == 0){ // 모두 익지 않았을 때
          printf("-1");
          return 0;
        }
        if(cnt < map[i][j][k]){ // 최대 일 수 구하기
          cnt = map[i][j][k];
        }
      }
    }
  }

  printf("%d", cnt-1); // 토마토 익은 것 1부터 시작

  return 0;
}