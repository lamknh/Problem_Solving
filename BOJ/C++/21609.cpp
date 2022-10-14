#include <iostream>
#include <cstring> // memset
#include <utility> // pair
#include <vector> // 그룹 정보 저장
#include <queue> // BFS

using namespace std;

int N, M; // 격자의 크기, 색상의 개수
int A[21][21]; // 검은색 블록은 -1, 무지개 블록은 0
bool visited[21][21] = {false}; // 방문체크

struct GROUP {
  int x, y; // 시작정보
  int rainbow = 0; // 무지개 블록 수
  vector<pair<int, int> > xy; // 그룹 블록 좌표 - 구조체에 vector 넣기 가능
};

vector<GROUP> v; // 그룹정보 저장 벡터

int ans = 0;

// 인접 칸 구하기
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct SEARCH{
 int y, x;
 int color;
};

queue<SEARCH> q; // BFS

// 블록 그룹 찾기
void BFS(int y, int x, int color){
  q.push({y, x, color});
  visited[y][x] = true;

  GROUP g; // BFS로 탐색한 그룹 정보 저장
  g.x = x; g.y = y;
  g.xy.push_back({y, x});

  while(!q.empty()){
    int y = q.front().y;
    int x = q.front().x;
    q.pop();

    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      // 범위 벗어나는 경우
      if(nx < 0 || ny < 0 || nx >= N || ny >= N){
        continue;
      }

      // 일반 블록 또는 무지개 블록이 블록 집합으로 묶일 수 있음.
      // 일반 블록의 색은 모두 같아야 한다
      if(!visited[ny][nx] && (A[ny][nx] == 0 || A[ny][nx] == color)){
        visited[ny][nx] = true;
        g.xy.push_back({ny, nx});

        if(A[ny][nx] == 0){
          g.rainbow++;
        }
        q.push({ny, nx, color});
      }
    }
  }

  // 그룹에 속한 블록의 개수는 2보다 크거나 같아야 하며
  if(g.xy.size() >= 2){
    v.push_back(g); // 모든 그룹 블록들 정보 저장
  }
}

void gravity(){
  // 아랫쪽 블록부터 아래로 내려줘야함
  // 제일 아래있는 칸의 블록은 내려줄 필요 없음
  // 열
  for(int i = N-2; i >= 0; i--){
    // 행
    for(int j = 0; j < N; j++){
      // 빈공간이거나 검정 블록인 경우 무시
      if(A[i][j] == -2 || A[i][j] == -1){
        continue;
      }
      
      int downY = i; // (j, i)의 아랫칸 y의 좌표
      while(1){
        downY++; // 다음 아랫칸 탐색

        // 제일 아랫칸까지 갔으면
        if(downY == N){
          break;
        }
        // 아랫칸이 비어있지 않으면
        if(A[downY][j] != -2){
          break;
        }
      }
      swap(A[--downY][j], A[i][j]); // 중력으로 블록 내려주기
    }
  }
}

// 맵 90도 반시계 방향  
void rotate(){
  int temp[21][21] = {0};

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      temp[N - j - 1][i] = A[i][j]; // 반시계방향 저장
    }
  }

  memcpy(A, temp, sizeof(A));
}

int main(){
  scanf("%d %d", &N, &M);
  
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      scanf("%2d", &A[i][j]);
    }
  }
  
  // 오토플레이 끝까지 계속 - 블록 그룹이 존재하는 동안 계속해서 반복
  while(1){
    memset(visited, false, sizeof(visited)); // 방문 초기화
    v.clear(); // 블록 그룹 정보 초기화

    // 크기가 가장 큰 블록 그룹을 찾는다
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        // 블록 그룹에는 일반 블록이 하나 이상 포함되어야하기에 일반 블록에서 블록 그룹 탐색 시작
        if(!visited[i][j] && A[i][j] > 0){
          BFS(i, j, A[i][j]);
        }
        
        // 무지개 visit 초기화해야함. 모든 경우에 대해서 그룹지을 수 있기 때문
        for(int n = 0; n < N; n++){
          for(int m = 0; m < N; m++){
            if(A[n][m] == 0){
              visited[n][m] = false;
            }
          }
        }
      }
    }

    // 블록 그룹 존재 x
    if(v.size() == 0){
      break;
    }

    // 크기가 가장 큰 블록 그룹을 찾는다.
    int maxGroup = 0;
    int maxGroupIdx = 0;
    for(int i = 0; i < v.size(); i++){
      if(v[i].xy.size() > maxGroup){
        maxGroup = v[i].xy.size();
        maxGroupIdx = i;
      } else if(v[i].xy.size() == maxGroup){
        // 그러한 블록 그룹이 여러 개라면 포함된 무지개 블록의 수가 가장 많은 블록 그룹, 
        if(v[i].rainbow > v[maxGroupIdx].rainbow){
          maxGroup = v[i].xy.size();
          maxGroupIdx = i;
        } else if(v[i].rainbow == v[maxGroupIdx].rainbow){
          // 그러한 블록도 여러개라면 기준 블록의 행이 가장 큰 것을
          // 문제는 행과 열을 혼동해서 사용하고 있다. 
          // 중력이 작용하면 모든 블록이 행의 번호가 큰 칸으로 이동 -> 행이 y인 것을 알 수 있다.
          if(v[i].y > v[maxGroupIdx].y){
            maxGroup = v[i].xy.size();
            maxGroupIdx = i;
          } else if(v[i].y == v[maxGroupIdx].y){
            // 그 것도 여러개이면 열이 가장 큰 것을 찾는다.
            if(v[i].x > v[maxGroupIdx].x){
              maxGroup = v[i].xy.size();
              maxGroupIdx = i;
            }
          }
        }
      }
    }

    // 블록 그룹의 모든 블록을 제거
    for(int i = 0; i < v[maxGroupIdx].xy.size(); i++){
      int x = v[maxGroupIdx].xy[i].second;
      int y = v[maxGroupIdx].xy[i].first;

      A[y][x] = -2;
    }

    // 블록 그룹에 포함된 블록의 수를 B라고 했을 때, B^2점을 획득
    int B = v[maxGroupIdx].xy.size(); // 블록 그룹에 포함된 블록의 수를 B
    ans += B * B;

    // 격자에 중력
    gravity();

    // 격자가 90도 반시계 방향으로 회전
    rotate();

    // 격자에 중력
    gravity();
  }

  printf("%d", ans);

  return 0;
}