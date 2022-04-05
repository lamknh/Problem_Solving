#include <iostream>

int N, S;
int cnt = 0;
int arr[20]; // 1 <= N <= 20

void dfs(int start, int tmp){
  if(tmp == S && start != 0){ // start != 0 - 처음 시작때 카운트하지 말 것
    cnt++;
    // 여기 return X - 계속 더해나가야 함. 여기서 분기 끊기면 안됨.
  }
  if(start == N){ // 범위 초과
    return;
  }
  for(int i = start; i < N; i++){
    dfs(i+1, tmp + arr[i]); // tmp += arr[i]로 따로 빼지 말 것. tmp 값 다른 분기까지 변동됨
  }
}

int main(int argc, char** argv){
  scanf("%d %d", &N, &S);

  for(int i=0; i<N; i++){
    scanf("%d", &arr[i]);
  }

  dfs(0, 0);
  printf("%d", cnt);
  return 0;
}