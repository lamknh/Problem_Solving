#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

int map[51][51]; // 맵 0 : 빈칸, 1 : 집, 2 : 치킨집
int N, M; //맵 크기, 고를 치킨 집 수
vector<pair<int, int> > c, h; // 치킨집 좌표, 집 좌표
bool visited[13] = {false}; // 치킨 집 없앴는지

int ans = 99999999; // 도시 치킨 거리 최소값

// 거리 구하는 식
int Distance(int x, int y, int a, int b){
  return abs(x - a) + abs(y - b);
}

// 하나씩 치킨 집 없애보기 - 백트래킹 (하나씩 해보면서 탐색)
void DFS(int idx, int size){
  // 최대 M개 고르라고 하면 M개 고르는거 그냥 찾으면 되나봄.. M보다 이하인 경우는??
  if(size == M){
    // 모든 치킨집 순회 돌면서 치킨 거리 찾기
    int tmp = 0;
    for(int i = 0; i < h.size(); i++){
      int dist = 99999999; // 집에서의 치킨 거리
      for(int j = 0; j < c.size(); j++){
        if(visited[j]){
          // 남아있는 치킨집과 거리 찾기
          dist = min(dist, Distance(h[i].first, h[i].second, c[j].first, c[j].second));
        }
      }
      tmp += dist;
    }

    // 가장 작은 치킨 거리 찾기
    ans = min(ans, tmp);
    return;
  }

  // printf("*****\n");
  // for(int i = 0; i < c.size(); i++){
  //   if(visited[i]){
  //     printf("y : %d x : %d\n", c[i].first, c[i].second);
  //   }
  // }


  for(int i = idx; i < c.size(); i++){
    //i + 1부터 탐색 안해도 됨
    if(!visited[i]){
      visited[i] = true;
      DFS(i, size + 1);
      visited[i] = false;
    }
  }
}

int main(int argc, char** argv){
  scanf("%d %d", &N, &M);

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      scanf("%d", &map[i][j]); // 지도 입력받기
      if(map[i][j] == 1){
        h.push_back({i, j});
      }
      if(map[i][j] == 2){
        c.push_back({i, j});
      }
    }
  }

  // 0번째 치킨 집부터 살리기
  DFS(0, 0);

  printf("%d", ans);

  return 0;
}