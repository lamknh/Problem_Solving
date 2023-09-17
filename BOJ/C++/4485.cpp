#include <iostream>
#include <queue> // bfs
using namespace std;

int N, num = 0;
int map[126][126];
int cnt[126][126] = {0};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void BFS(int y, int x){
  // 여러번 BFS 수행으로 전역변수 사용 X
  queue<pair<int, int> > q; // bfs를 위한 큐 - BFS 함수는 탐색 끝나기 전까지 함수를 벗어나지 않음
  q.push({0, 0}); // 처음 탐색 좌표 큐에 넣기
  cnt[0][0] = map[0][0]; // 시작 좌표 넣기

  while(!q.empty()){
    int y = q.front().first;
    int x = q.front().second;
    q.pop(); // 큐 좌표 받으면 pop 해줘야 함

    for(int i = 0; i < 4; i++){
      int ny = dy[i] + y;
      int nx = dx[i] + x;

      // 좌표 범위 체크
      if(nx < 0 || ny < 0 || nx >= N || ny >= N){
        continue;
      }

      if(cnt[y][x] + map[ny][nx] < cnt[ny][nx]){
        cnt[ny][nx] = cnt[y][x] + map[ny][nx];
        q.push({ny, nx}); // 큐에 넣고 계속 탐색
      }
    }
  }
}

int main(){
  while(1){
    scanf("%d",&N);

    if(N == 0){
      return 0; // 0 입력받으면 종료
    }

    num++;

    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        scanf("%d ", &map[i][j]);
        cnt[i][j] = 9999999; // 초기화
      }
    }

    BFS(0, 0); // (0, 0)부터 가기 시작

    printf("Problem %d: %d\n", num, cnt[N-1][N-1]);
  }

  return 0;
}