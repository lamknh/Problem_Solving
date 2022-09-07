#include <iostream>
#include <queue>

using namespace std;

// 큐에 여러가지 정보를 넣어야할 때는 구조체를 사용해도 좋다.
struct INFO {
  int rx, ry;
  int bx, by;
  int cnt; // 움직임 횟수 카운트, 10번 이하면 -1 출력
}; // 구조체 마지막에 ; 붙이기

int N, M; // 세로, 가로 (3~10)
char board[11][11];
bool visited[11][11][11][11] = {false}; // 방문여부 체크 - 빨강/파랑
queue<INFO> q; // 위치 저장 BFS 큐

// 상하좌우 탐색 배열
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
 
// 포인터 사용??????
void move(int x, int y, int cnt, int i){
  // 구슬은 같은 방향으로 이동한다 - 헷갈리지 말기, 무조건 벽까지 굴러가는것이 아님
  // 하지만 같은 방향으로 계속 갈 수 있음 : 때문에 while문 사용
  // 벽에 닿거나 구멍에 들어가지 않을 경우까지 이동
  while(board[x + dx[i]][y + dy[i]] != '#' && board[x][y] != 'O'){
    // 좌표 이동
    x += dx[i];
    y += dy[i];
    cnt++;
  }
}

//BFS : 큐에 넣고 탐색
void BFS(){
  while(!q.empty()){
    int rx = q.front().rx;
    int ry = q.front().ry;
    int bx = q.front().bx;
    int by = q.front().by;
    int cnt = q.front().cnt;
    q.pop();

    if(cnt >= 10){
      break; // 10번 이상이면 더이상 탐색 X
    }

    // 상하좌우 탐색
    for(int i = 0; i < 4; i++){
      int nrx = rx; int nry = ry;
      int nbx = bx; int nby = by;
      int rcnt = 0, bcnt = 0, ncnt = cnt + 1;

      // 구슬 이동, 같은 방향이기에 i를 넘겨준다.
      move(nrx, nry, rcnt, i);
      move(nbx, nby, bcnt, i);

      // 파란 구슬이 들어가는 경우에는 그 경우 무시하기
      if(board[nbx][nby] == 'O'){
        continue;
      }
      // 구멍에 빨간 구슬 들어감
      if(board[nrx][nry] == 'O'){
        printf("%d", ncnt);
        return;
      }

      // 구슬이 겹쳤을 때 - 이런 예외 상황도 생각해야한다니...
      if(nrx == nbx && nry == nby){
        // 이동거리가 더 긴 구슬 위치를 한 칸 뒤로 옮김
        if(rcnt > bcnt){
          nrx -= dx[i];
          nry -= dy[i];
        } else {
          nbx -= dx[i];
          nby -= dy[i];
        }
      }

      // 방문여부 체크
      if(!visited[nrx][nry][nbx][nby]){
        visited[nrx][nry][nbx][nby] = true;
        q.push({nrx, nry, nbx, nby, ncnt});
        visited[nrx][nry][nbx][nby] = false;
      }
      
    }
  }
  // 모든 경우 탐색했을 때도 구멍에 들어가지 못했을 경우 -1 출력
  printf("-1");
}

int main(){
  int rx, ry, bx, by;

  scanf("%d %d", &N, &M);

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> board[i][j]; // 보드 입력받기 - 그냥 char 입력 받으면 엔터까지 입력받게됨

      if(board[i][j] == 'R'){
        rx = i;
        ry = j;
      } else if(board[i][j] == 'B'){
        bx = i;
        by = j;
      }
    }
  }

  q.push({rx, ry, bx, by, 0}); // BFS를 위해 큐에 첫 상태 넣기
  visited[rx][ry][bx][by] = true; // 방문 체크
  BFS(); // BFS 탐색 시작

  return 0;
}