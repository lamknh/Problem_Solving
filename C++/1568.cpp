#include <iostream>

int N, n = 1;
int cnt = 0;
int main(int argc, char** argv){
  scanf("%d", &N);

  while(N > 0){
    if(N >= n){
      N -= n;
      cnt++;
      n++;
    } else {
      n = 1;
    }
  }

  printf("%d", cnt);

  return 0;
}