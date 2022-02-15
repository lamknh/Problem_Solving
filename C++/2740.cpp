#include <iostream>
using namespace std;

int N, M, K, sum = 0;
int main(int argc, char** argv){
  scanf("%d %d", &N, &M);
  int A[N][M];
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      scanf("%d", &A[i][j]);
    }
  }

  scanf("%d %d", &M, &K);
  int B[M][K];
  for(int i=0; i<M; i++){
    for(int j=0; j<K; j++){
      scanf("%d", &B[i][j]);
    }
  }

  for(int i=0; i<N; i++){
    for(int j=0; j<K; j++){
      for(int k=0; k<M; k++){
        // printf("A : %d, B : %d\n", A[i][k], B[k][j]);
        sum += A[i][k] * B[k][j];
      }
      printf("%d ", sum);
      sum = 0;
    }
    printf("\n");
  }

  return 0;
}