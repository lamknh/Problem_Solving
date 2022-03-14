#include <iostream>

int N, M, K;
int i, j, x, y;
int arr[301][301];
int main(int argc, char** argv){
  scanf("%d %d", &N, &M);

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      scanf("%d", &arr[i+1][j+1]);
    }
  }

  scanf("%d", &K);

  for(int r=0; r<K; r++){
    int sum = 0;
    scanf("%d %d %d %d", &i, &j, &x, &y);

    for(int n=i; n<=x; n++){
      for(int m=j; m<=y;m++){
        sum += arr[n][m];
      }
    }
    printf("%d\n", sum);
  }


  return 0;
}