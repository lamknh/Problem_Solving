#include <iostream>
#include <vector>

using namespace std;

int N;
bool A[101][101] = {false}; // 격자가 아니라 해당 점을 나타내는 2차원 배열
int x, y, d, g; // x와 y는 드래곤 커브의 시작 점, d는 시작 방향, g는 세대

int cnt = 0; // 정사각형 갯수

// → ↑ ← ↓
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

vector<int> v; // 드래곤커브 dir 정보 저장

// 드래곤 커브는 이전세대 정보 역순으로 탐색하고 그를 뒤에 추가시킨 것과 같음
void dragonCurve(){
  for(int i = v.size() - 1; i >= 0; i--){
    int nd = (v[i] + 1) % 4; // 0~4 순서로 반복
    x += dx[nd];
    y += dy[nd];
    A[y][x] = true; // (x, y) 점 찍기

    v.push_back(nd);
  }
}

int main(){
  scanf("%d", &N);

  for(int i = 0; i < N; i++){
    scanf("%d %d %d %d", &x, &y, &d, &g);
    v.clear(); // 드래곤커브 선분 정보 초기화

    // 0세대 방향 d 긋고 시작
    A[y][x] = true; // 점 x, y 부터 시작
    x += dx[d];
    y += dy[d];
    A[y][x] = true;
    v.push_back({d}); 

    // 세대만큼 드래곤커브 구하기
    for(int j = 0; j < g; j++){
      dragonCurve();
    }
  }

  for(int i = 0; i < 101; i++){
    for(int j = 0; j < 101; j++){
      // 범위 벗어나는 경우 체크
      if(i + 1 > 100 || j + 1 > 100){
        continue;
      }
      // 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부
      if(A[i][j] && A[i+1][j] && A[i][j+1] && A[i+1][j+1]){
        cnt++;
      }
    }
  }

  printf("%d\n",cnt);

  return 0;
}