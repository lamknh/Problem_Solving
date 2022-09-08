#include <iostream>
#include <queue>

using namespace std;

struct INFO{
  int rx, ry;
  int bx, by;
  int cnt;
};

int N, M;

char board[11][11];
bool visited[11][11][11][11] = {false}; // 방문여부

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

queue<INFO> q;

void move(int& x, int& y, int& cnt, int& i){
  while(board[x + dx[i]][y + dy[i]] != '#' && board[x][y] != 'O'){
    x += dx[i];
    y += dy[i];
    cnt++;
  }
}

void BFS(){
  while(!q.empty()){
    int rx = q.front().rx;
    int ry = q.front().ry;
    int bx = q.front().bx;
    int by = q.front().by;
    int cnt = q.front().cnt;
    q.pop(); // 큐에서 항목을 빼 주면 pop 해줘야 함

    // 탐색 멈출 조건문
    if(cnt >= 10){
      break;
    }

    for(int i = 0; i < 4; i++){
      // 변수 이렇게 두는게 중요 - 포인터 써서 아예 값을 바꿔버리기 때문
      int nrx = rx, nry = ry;
      int nbx = bx, nby = by;
      int nrcnt = 0, nbcnt = 0; // 구슬 겹치는 경우 피하기 위해

      move(nrx, nry, nrcnt, i);
      move(nbx, nby, nbcnt, i);

      if(board[nbx][nby] == 'O'){
        continue;
      }

      if(board[nrx][nry] == 'O'){
        printf("1");
        return;
      }

      if(nrx == nbx && nry == nby){
        // 길게 굴러간 것을 한 칸 더 뒤로
        if(nrcnt < nbcnt){
          nbx -= dx[i];
          nby -= dy[i];
        } else {
          nrx -= dx[i];
          nry -= dy[i];
        }
      }

      if(!visited[nrx][nry][nbx][nby]){
        visited[nrx][nry][nbx][nby] = true;
        q.push({nrx, nry, nbx, nby, cnt + 1}); // cnt++ 하지 말고 함수에서 +1 그래야 여러 경우 체크 가능
        visited[nrx][nry][nbx][nby] = false;
      }
    }
  }
  printf("0");
}

int main(){
  scanf("%d %d", &N, &M);

  int rx, ry, bx, by;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> board[i][j];
      if(board[i][j] == 'R'){
        rx = i;
        ry = j;
      } else if(board[i][j] == 'B'){
        bx = i;
        by = j;
      }
    }
  }

  q.push({rx, ry, bx, by, 0}); // 큐는 push_back 아님
  visited[rx][ry][bx][by] = true; // 방문 체크 해줘야 함
  BFS();

  return 0;
}