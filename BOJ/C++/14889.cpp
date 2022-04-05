#include <iostream>
#include <algorithm> // min
#include <vector>
#include <cmath> // abs(절댓값)
using namespace std;

int map[21][21]; // 세로 i, 가로 j

bool visited[21]; // 방문 여부
int N;
int Min = 999999999;

void DFS(int num, int cnt){
  if(cnt == N / 2){
    // 팀 저장 - 지역변수로 해야 별도의 초기화 불필요, 모든 수열에 따라 다른 팀 저장
    vector<int> team1;
    vector<int> team2;

    // 팀 별 능력치 저장
    int tmp1 = 0;
    int tmp2 = 0;

    for(int i = 1; i <= N; i++){ // 팀 저장
      if(visited[i]){ // 골라진 수열의 수
        team1.push_back(i); // team1에 저장
      } else {
        team2.push_back(i); // team2에 저장
      }
    }

    for(int i = 0; i < N/2; i++){
      // printf("team1 : %d team2 : %d\n", team1[i], team2[i]);
      for(int j = i; j < N/2; j++){
        tmp1 += map[team1[i]][team1[j]] + map[team1[j]][team1[i]];
        tmp2 += map[team2[i]][team2[j]] + map[team2[j]][team2[i]];
      }
    }

    int tmp = abs(tmp1 - tmp2);
    // printf("tmp : %d tmp1 : %d tmp2 : %d\n", tmp, tmp1, tmp2);
    
    Min = min(Min, tmp);
    return;
  }

  for(int i = num; i <= N; i++){
    visited[i] = true; // visited면 순열 골라진 것
    DFS(i+1, cnt + 1);
    visited[i] = false;
  }
}

int main(int argc, char** argv){
  scanf("%d", &N);

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      scanf("%d", &map[i][j]); // 능력치 표 입력받기
    }
  }

  visited[1] = true;
  DFS(2, 1); // 2번부터 체크, 1은 이미 팀 1에 속해있다고 가정

  printf("%d", Min);

  return 0;
}