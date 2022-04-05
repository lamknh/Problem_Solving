  #include <iostream>
  #include <algorithm> // max, copy
  #include <utility> // pair
  #include <queue> // bfs
  using namespace std;

  int map[9][9]; // 연구소 맵 0 : 빈 칸, 1 : 벽, 2 : 바이러스
  int tmp[9][9]; // 감염시킬 임시 값
  queue<pair<int, int> > q; // x, y

  int maxNum = -1; // 최대값 저장

  //상하좌우 탐색
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  int N, M; // 세로, 가로

  void BFS(){ // 인접한 곳부터 바이러스 퍼지기 때문에 BFS 사용
    //바이러스 탐색 계속 해줘야 함. main에서 처음 넣은 q 다 빠지면 탐색 못하기 때문에
    for(int i=1; i<=N; i++){
      for(int j=1; j<=M; j++){
        if(tmp[i][j] == 2){
          q.push({i, j}); // 바이러스 있는 경우 큐에 넣기
        }
      }
    }

    while(!q.empty()){ // 큐 빌 때까지 계속
      int x = q.front().first;
      int y = q.front().second;
      q.pop();

      for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx <= 0 || ny <= 0 || nx > N || ny > M){ // 맵 밖으로 나갈 경우
          continue;
        }

        if(tmp[nx][ny] == 0){ // 인접항에 빈 공간 있는 경우
          tmp[nx][ny] = 2; // 바이러스 감염
          q.push({nx, ny}); // 새 노드 큐에 넣기
        }
      }
    }

    int cnt = 0;

    //printf("*******\n");
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= M; j++){
        if(tmp[i][j] == 0){
          cnt++; // 안전지대 수 세기
        }
        //printf("%d ", tmp[i][j]);
      }
      //printf("\n");
    }

    maxNum = max(cnt, maxNum);
    return;
  }

  void DFS(int wall){ // 백트래킹 - 수 많은 경우 중 순열 찾는 것 처럼
    if(wall == 0){ // 벽 다 세워지면
      copy(&map[0][0], &map[0][0] + 81, &tmp[0][0]); //맵에 임시값 복사해넣기
      BFS(); // 바이러스 퍼뜨리기
      return;
    }

    for(int i=1; i<=N; i++){
      for(int j=1; j<=M; j++){ // 범위 조심 0~N-1까지인지 1~N까지인지
        if(map[i][j] == 0){ // 빈 공간 있으면
          map[i][j] = 4; // 벽세우기
          DFS(wall - 1); // 백트래킹으로 탐색
          map[i][j] = 0; // 초기화
        }
      }
    }
  }

  int main(int argc, char** argv){
    scanf("%d %d", &N, &M);

    for(int i=1; i<=N; i++){
      for(int j=1; j<=M; j++){
        scanf("%d", &map[i][j]); // 맵 입력받기
      }
    }

    DFS(3); // 벽 3개 세워야 함

    printf("%d", maxNum); //최대 안전 지대 수 출력

    return 0;
  }