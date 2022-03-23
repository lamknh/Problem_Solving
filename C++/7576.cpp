#include <iostream>
#include <queue> // bfs - 인접된 것 cnt 해야해서
#include <utility> // x, y 좌표 저장
using namespace std;

int M, N; //가로, 세로
int map[1001][1001]; // 상자 1 : 익은 토마토 0 : 안 익은 토마토 -1 : 토마토가 없음
bool visited[1001][1001] = {false}; // 방문 여부
queue<pair<int, int> > q; // x, y

// 상하좌우 체크
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool allTomato = false; // 처음부터 다 익은 경우
int cnt = 0; // 처음부터 모든 토마토 익어있으면 0, 모두 못 익으면 -1

void BFS(){
  while(!q.empty()){ // 인접 없을 때 까지 반복
    int x = q.front().first;
    int y = q.front().second; // 노드에서 좌표 꺼내기
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 1 || ny < 1 || nx > N || ny > M){ // 범위 체크 잘 하기
        continue;
      }

      if(map[nx][ny] == 0 && !visited[nx][ny]){ // 안익고 방문 안된 토마토
        map[nx][ny] = map[x][y] + 1; // 토마토 익는 순서
        q.push(make_pair(nx, ny)); // 큐에 넣기
        visited[nx][ny] = true; // 방문 체크
      }
    }
  }

}

int main(int argc, char** argv){
  scanf("%d %d", &M, &N);

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= M; j++){
      scanf("%d", &map[i][j]);
      if(map[i][j] == 0){
        allTomato = true; // 안 익은 토마토 있는 경우
      }
    }
  }

  if(!allTomato){ // 처음부터 모든 토마토 익은 경우
    printf("0");
    return 0;
  }
  
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= M; j++){
      if(map[i][j] == 1 && !visited[i][j]){
        q.push(make_pair(i,j)); // 토마토 큐에 넣기
        visited[i][j] = true; // 방문 체크
      }
    }
  }

  BFS();
  
  // for(int i = 1; i <= N; i++){
  //   for(int j = 1; j <= M; j++){
  //     printf("%d ", map[i][j]);
  //   }
  //   printf("\n");
  // }


  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= M; j++){
      if(map[i][j] == 0){
        printf("-1"); // 안 익은 토마토 있을 경우
        return 0;
      }
      if(cnt < map[i][j]){
        cnt = map[i][j];
      }
    }
  }

  printf("%d", cnt-1);

  return 0;
}