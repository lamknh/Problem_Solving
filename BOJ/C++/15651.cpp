#include <iostream>

int arr[8]; // 순열 저장 배열
// bool visited[8] = {false};

int N, M; // N 개 중 M개 뽑기

void DFS(int cnt){
  if(cnt == M){ // 순열 M개일 때
    for(int i = 0; i <M; i++){
      printf("%d ", arr[i]);
    }
    printf("\n");
    return;
  }

  for(int i = 1; i <= N; i++){
    arr[cnt] = i; // 수열 저장
    DFS(cnt + 1);
  }
}
int main(int argc, char** argv){
  scanf("%d %d", &N, &M);

  DFS(0);

  return 0;
}