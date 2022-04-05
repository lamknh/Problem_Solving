#include <iostream>

int arr[9];
int N, M;

void DFS(int cnt, int num){
  if(cnt == M){
    for(int i = 0; i <M; i++){
      printf("%d ", arr[i]);
    }
    printf("\n");
    return;
  }

  for(int i = 1; i <= N; i++){
    if(i >= num){
      arr[cnt] = i;
      DFS(cnt + 1, i);
    }
  }
}

int main(int argc, char** argv){
  scanf("%d %d", &N, &M);

  DFS(0, 0);

  return 0;
}