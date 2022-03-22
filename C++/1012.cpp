#include <iostream>

int map[51][51] = {0}; // 배추 있으면 1
bool visited[51][51] = {false}; // 방문 여부

// 상하좌우 탐색
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int T; // 테스트 케이스 개수
int M, N, K; // 가로, 세로, 배추 위치 개수
int X, Y; // 배추 위치

void DFS(int x, int y){
  visited[x][y] = true; // 방문처리

  //상하좌우 다 찾아야하면 반복문 사용
  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(map[nx][ny] == 1 && !visited[nx][ny]){ // 연결된 것이 있고 탐색된 적 없는 경우
      DFS(nx, ny); // 탐색
    }
  }
}

int main(int argc, char** argv){
  scanf("%d", &T);  
  for(int i = 0; i < T; i++){
    int cnt = 0;

    scanf("%d %d %d", &M, &N, &K);

    for(int j = 0; j < K; j++){
      scanf("%d %d", &X, &Y);
      map[X][Y] = 1; // 배추 있으면 1
    }

    for(int j = 0; j <= 50; j++){
      for(int k = 0; k <= 50; k++){
        if(map[j][k] == 1 && !visited[j][k]){
          DFS(j, k);
          cnt++;
        }
      }
    }

    printf("%d\n", cnt);

    //초기화
    cnt = 0;
    for(int j = 0; j <= 50; j++){
      for(int k = 0; k <= 50; k++){
        map[j][k] = 0;
      }
    }
  }

  return 0;
}