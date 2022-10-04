#include <iostream>
#include <queue> // BFS
#include <cstring> // memset
#include <vector>

using namespace std;

int N, M;
int map[51][51] = {0}; // 0은 빈 칸, 1은 벽, 2는 바이러스의 위치
int Time[51][51] = {0}; // 시간 저장 배열 - visit 체크 이걸로 대신 가능

int ans = 9999999; // 정답 저장
int emptyB = 0;

// 상하좌우 탐색
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct INFO{
  int y, x; // cnt 이렇게 셀 필요 없음 이건 백트래킹용인듯?
};

vector<INFO> v;
bool vvisited[10] = {false}; // 바이러스 선택 여부 체크

queue<INFO> q;

// BFS (인접 칸에 바이러스 감염 탐색)
void BFS(){
  int cnt = 0; // 감염 바이러스
  int maxTime = 0;

  while(!q.empty()){
    int x = q.front().x;
    int y = q.front().y;

    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      // 범위 체크 잊지 말기
      if(nx < 0 || ny < 0 || nx >= N || ny >= N){
        continue;
      }

      // 방문된 적 없는 빈칸 또는 비활성화 바이러스에 바이러스 퍼질 수 있음.
      // 선택된 바이러스 time = 0 이므로 구별 가능
      if(map[ny][nx] != 1 && Time[ny][nx] == -1){
        q.push({ny, nx});
        Time[ny][nx] = Time[y][x] + 1;

        // 빈 칸 감염
        if(map[ny][nx] == 0){
          cnt++;
          // 빈 칸의 경우에만 시간 갱신, 
          maxTime = max(maxTime, Time[ny][nx]);
        }
      }
    }
  }

  // 바이러스 다 퍼뜨림
  // 빈 칸 없이 바이러스 다 퍼진 경우 그 때 최소 값 고르기
  // 모든 경우 탐색하고 가장 작은 경우 출력
  if(emptyB == cnt){
    ans = min(ans, maxTime);
  }

  // printf("-----\n");
  // for(int i = 0; i < N; i++){
  //   for(int j = 0; j< N; j++){
  //     printf("%d ", Time[i][j]);
  //   }
  //   printf("\n");
  // }
}

// 바이러스 M개 선택 - 백트래킹
void DFS(int idx, int cnt){
  // 연구소의 바이러스 M개를 활성 상태로 변경 - DFS 멈추는 조건
  if(cnt == M){
    // 바이러스 전부 선택되었으므로 감염 시작
    memset(Time, -1, sizeof(Time)); // time -1로 초기화 - 0부터 시작하므로

    for(int i = 0; i < v.size(); i++){
      // 활성화된 바이러스 큐에 넣기
      if(vvisited[i] == true){
        q.push({v[i].y, v[i].x});
        Time[v[i].y][v[i].x] = 0; // 바이러스 0부터 시작
      }
    }
    // 바이러스 퍼뜨리기 시작
    BFS();
  }

  for(int i = idx; i < v.size(); i++){
    vvisited[i] = true;
    DFS(i+1, cnt+1); // 고르고 다음 인덱스부터 또 탐색
    vvisited[i] = false;
  }
}

int main(){
  scanf("%d %d", &N, &M); 

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      scanf("%d", &map[i][j]);
      // 바이러스 놓을 수 있는 위치
      if(map[i][j] == 2){
        v.push_back({i, j}); // 바이러스 정보 벡터에 저장
      } else if(map[i][j] == 0){
        // 바이러스 다 퍼졌는지 체크할 때 2중 for문 계속 돌려서 체크하면 시간이 너무 많이 걸림
        // 그냥 빈 칸 수 세고 빈 칸 다 감염시켰는지만 확인해준다.
        emptyB++;
      }
    }
  }

  // 바이러스 고르기
  DFS(0, 0);

  // 다른 경우 다 탐색해도 모든 빈 칸에 바이러스를 퍼뜨릴 수 없는 경우에는 -1을 출력
  // 모든 칸에 바이러스 퍼뜨렸으면 최초 설정값 변했을 것
  if(ans == 9999999){
    ans = -1;
  }

  printf("%d", ans);

  return 0;
}