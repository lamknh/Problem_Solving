#include <iostream>

int M;
int X, Y;
int ball = 1;
int main(int argc, char** argv){
  scanf("%d", &M);

  for(int i = 0; i < M; i++){
    scanf("%d %d", &X, &Y);
    if(X == ball){
      ball = Y;
    } else if(Y == ball){
      ball = X;
    }
  }

  printf("%d", ball);

  return 0;
}