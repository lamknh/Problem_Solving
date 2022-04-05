#include <iostream>

int arr[9]; // 순열 저장 배열
bool visited[9] = {false}; // 방문 여부
int N, M; // N개 중에 M개 고른 순열

void DFS(int cnt, int num){
  if(cnt == M){ // M개의 순열 되었을 때
    for(int i = 0; i < M; i++){
      printf("%d ", arr[i]); // 순열 프린트
    }
    printf("\n");
    return;
  }

  for(int i = 1; i <= N; i++){ // 1~N 까지 순열 탐색
    if(!visited[i] && i > num){ // 방문되지 않은 수 일 때
      visited[i] = true; // 방문 체크
      arr[cnt] = i; // 순열 넣기
      DFS(cnt + 1, i);
      visited[i] = false; // 방문 초기화
    }
  }
}

int main(int argc, char** argv){
  scanf("%d %d", &N, &M);

  DFS(0, 0); // 0번째 순열

  return 0;
}