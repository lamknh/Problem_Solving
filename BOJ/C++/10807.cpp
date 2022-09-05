#include <iostream>

int main(){
  int arr[101] = {0};
  int N, v, idx;
  scanf("%d", &N);

  for(int i = 0; i < N; i++){
    scanf("%d", &idx);
    arr[idx]++;
  }

  scanf("%d", &v);

  printf("%d", arr[v]);
}