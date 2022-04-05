#include <iostream>
#include <vector>
#include <algorithm> // sort
using namespace std;

int N;
int map[26][26] = {0}; // 간선 저장
bool visited[26][26] = {false}; // 방문 여부 저장
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int cnt = 0; // 단지 개수
vector<int> v;

void DFS(int x, int y){
  cnt++;
  visited[x][y] = true; // 방문 처리

  for(int i = 0; i < 4; i++){ // 모든 방향 순회
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx < 0 || ny < 0 || nx >= N || ny >= N){ // 범위 벗어난 경우
      continue;
    }else if(map[nx][ny] == 1 && visited[nx][ny] == false){ // else if 말고 if
      DFS(nx, ny);
    }
  }
}

int main(int argc, char** argv){
  scanf("%d", &N);

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      scanf("%1d", &map[i][j]); // 숫자 1개씩 입력받기
    }
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(map[i][j] == 1 && visited[i][j] == false){ // 집이 있고 방문된 적 없다면
        cnt = 0;
        DFS(i, j);
        v.push_back(cnt);
      }
    }
  }

  sort(v.begin(), v.end()); // 오름차순 정렬
  printf("%lu\n", v.size());
  for(int i = 0; i < v.size(); i++){
    printf("%d\n", v[i]);
  }

  return 0;
}