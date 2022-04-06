#include <iostream>

int T, x;
int main(int argc, char** argv){
  scanf("%d", &T);

  for(int i = 1; i <= T; i++){
    int num = 0;
    for(int j = 1; j <= 10; j++){
      scanf("%d", &x);
      if(x % 2 == 1){
        num += x;
      }
    }
    printf("#%d %d\n", i, num);
  }

  return 0;
}