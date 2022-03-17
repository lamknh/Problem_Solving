#include <iostream>

int K, N, T;
int tmp, ans = 0, t = 210; // 3분 30초
char Z; //T, N, P
int main(int argc, char** argv){
  scanf("%d %d", &K, &N);
  tmp = K;

  for(int i=0; i<N; i++){
    scanf("%d %c", &T, &Z);

    if(tmp == 9){
      tmp = 1;
    }

    t -= T;
    if(t < 0 && ans == 0){
      ans = tmp;
    } else {
      if(Z == 'T'){ // 문제를 틀리거나 패스할 경우에는 넘어가지 않음
        tmp++;
      }
    }
  }
  
  printf("%d", ans);

  return 0;
}