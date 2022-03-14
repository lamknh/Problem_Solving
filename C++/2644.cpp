#include <iostream>

int n, m;
int a, b;
int x, y;

int map[101][101]; // 최대 100명
bool visited[101] = {false}; // 방문여부

int cnt = -1; // 연결 촌수 없으면 -1
bool success = false;

void DFS(int a, int b, int tmp){
  visited[a] = true; // 방문 체크
  for(int i = 1; i <= n; i++){
    if(i == b && map[a][i] == 1){ // 촌수 있는 경우
      cnt = tmp + 1;
      success = true;
      return;
    }
    if(map[a][i] == 1 && !visited[i]){ // 연결 있고 방문되지 않은 경우
      DFS(i, b, tmp+1);
    }
  }
}
int main(int argc, char** argv){
  scanf("%d", &n);
  scanf("%d %d", &a, &b); // 촌수 계산

  scanf("%d", &m);
  for(int i = 0; i < m; i++){
    scanf("%d %d", &x, &y); // 부모 자식 관계 x : 부모, y : 자식
    map[x][y] = 1;
    map[y][x] = 1; // 그래프 간선 연결 (방향 x)
  }

  DFS(a, b, 0);

  if(success){
    printf("%d", cnt);
  } else {
    printf("-1");
  }

  return 0;
}