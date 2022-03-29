#include <iostream>
#include <algorithm> // max
using namespace std;

int map[501][501]; // 0부터 시작
bool visited[501][501] = {false}; // 테스토미노

// 상하좌우 탐색
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int Max = -1; // 최댓값

int N, M; // 세로, 가로

// ㅗㅜㅏㅓ는 DFS로 탐색 불가능
void testimony(int x, int y){ // x, y 는 가운데 좌표
  //세로 : x, 가로 : y, 조건문 잘 쓰기 모두 만족해야할 때는 &&

  //ㅗ
  if(x - 1 >= 0 && y - 1 >= 0 && y + 1 < M){
    Max = max(Max, map[x-1][y] + map[x][y-1] + map[x][y] + map[x][y+1]);
  }
  //ㅜ
  if(x + 1 < N && y - 1 >= 0 && y + 1 < M){
    Max = max(Max, map[x+1][y] + map[x][y] + map[x][y-1] + map[x][y+1]);
  }
  //ㅏ
  if(x - 1 >= 0 && x + 1 < N && y + 1 < M){
    Max = max(Max, map[x-1][y] + map[x+1][y] + map[x][y] + map[x][y+1]);
  }
  //ㅓ  
  if(x - 1 >= 0 && x + 1 < N && y - 1 >= 0){
    Max = max(Max, map[x-1][y] + map[x+1][y] + map[x][y] + map[x][y-1]);
  }

  return;
}

void DFS(int x, int y, int sum, int cnt){
  if(cnt == 4){ // 테스토미노 사각형 4개로 구성

    // printf("******\n");
    // for(int i=0; i<N; i++){
    //   for(int j=0; j<M; j++){
    //     printf("%d ", visited[i][j]);
    //   }
    //   printf("\n");
    // }
    
    // 시간 초과된 값 찾기 코드
    // int tmp = 0;
    // for(int i=0; i<N; i++){
    //   for(int j=0; j<M; j++){
    //     if(visited[i][j]){
    //       tmp += map[i][j]; // 테스토미노 값 찾기
    //     }
    //   }
    // }

    Max = max(Max, sum); // 최댓값 저장
    return;
  }

  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(nx < 0 || ny < 0 || nx >= N || ny >= M){
      continue; // 맵 초과시
    }

    if(!visited[nx][ny]){
      visited[nx][ny] = true;
      DFS(nx, ny, sum + map[nx][ny], cnt + 1);
      visited[nx][ny] = false; // 초기화
    }
  }
}

int main(){
  scanf("%d %d", &N, &M);

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      scanf("%d", &map[i][j]); // 맵 입력받기
    }
  }

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      visited[i][j] = true;
      DFS(i, j, map[i][j], 1); // 모든 시작점에 대해서 찾기
      testimony(i, j); // ㅗ 모양 찾기
      visited[i][j] = false; // 초기화
    }
  }

  printf("%d", Max); // 최댓값 출력

  return 0;
}