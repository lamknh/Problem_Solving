#include <iostream>
#include <vector>
#include <queue> // 구름 위치
#include <uitlity> //pair
using namespace std;

int N, M; // 맵 크기, 이동 수
int map[51][51]; // 맵
int di, si; // 이동 정보 - 방향, 거리

queue<pair<int, int>> q; // r, c

// 방향 : ←, ↖, ↑, ↗, →, ↘, ↓, ↙
int dx[9] = {99, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {99, 0, 1, 1, 1, 0, -1, -1, -1};

int main(){
  scanf("%d %d", &N, &M);

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      scanf("%d", &map[i][j]); // 맵 입력 받기
    }
  }
  
  // 처음 비바라기 구름 위치 넣기
  q.push_back({N, 1});
  q.push_back({N, 2});
  q.push_back({N-1, 1});
  q.push_back({N-1, 2});

  for(int i = 0; i < M; i++){
    scanf("%d %d", di, si); // 이동 정보 입력받기
  }

  return 0;
}