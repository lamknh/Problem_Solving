#include <iostream>

int arr[9] = {0}; // 최대 8개
bool visited[9] = {false}; // 방문 여부
int N, M; // N개 중 M개 고른 수열

void DFS(int cnt){
  if(cnt == M){ // M개가 골라졌을 때
    for(int i = 0; i < M; i++){
      printf("%d ", arr[i]); // arr에 저장된 수 출력하기
    }
    printf("\n");
    return;
  }

  // M개 아닌 경우
  for(int i = 1; i <= N; i++){ // 1~N까지의 모든 수 탐색
    if(!visited[i]){ // 방문된 적이 없으면
      visited[i] = true; // 방문 체크
      arr[cnt] = i; // 순열 추가
      DFS(cnt+1); // 다음 순열 고르기
      visited[i] = false; // 방문 초기화 - 재귀 함수 끝나면 호출됨
    }
  }
}

int main(int argc, char** argv){
  scanf("%d %d", &N, &M);

  DFS(0);

  return 0;
}