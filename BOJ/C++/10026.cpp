#include <iostream>
using namespace std;

int map[101][101];
bool visited[101][101] = {false}; // 방문 여부 체크

int N;
char color;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int cnt = 0, rgcnt = 0;

void DFS(int y, int x){
  visited[y][x] = true; // 방문 체크

  for(int i = 0; i < 4; i++){
    int ny = y + dy[i];
    int nx = x + dx[i];

    if(nx < 0 || ny < 0 || nx >= N || ny >= N){
      continue; // 범위 체크
    }

    if(map[y][x] == map[ny][nx] && !visited[ny][nx]){
      DFS(ny, nx);
    }
  }
}

int main(){
  cin >> N;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> color;

      if(color == 'R'){
        map[i][j] = 0;
      } else if(color == 'G'){
        map[i][j] = 1;
      } else {
        map[i][j] = 2;
      }
    }
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(!visited[i][j]){
        cnt++; // 구역수 세기
        DFS(i, j);
      }
    }
  }

  // 적록색약 초기화
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      visited[i][j] = false;
      if(map[i][j] == 1){
        map[i][j] = 0; // R == G
      }
    }
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(!visited[i][j]){
        rgcnt++; // 구역수 세기
        DFS(i, j);
      }
    }
  }

  cout << cnt << " " << rgcnt;

  return 0;
}