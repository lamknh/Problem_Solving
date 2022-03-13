#include <iostream>

char n[50];
int cnt = 1;
int main(int argc, char** argv){
  scanf("%s", n);

  for(int i = 0; i < 50; i++){
    if(n[i] == 'A'){
      if(cnt == 1){
        cnt = 2;
      } else if(cnt == 2){
        cnt = 1;
      }
    } else if(n[i] == 'B'){
      if(cnt == 2){
        cnt = 3;
      } else if(cnt == 3){
        cnt = 2;
      }
    } else if(n[i] == 'C'){
      if(cnt == 1){
        cnt = 3;
      } else if(cnt == 3){
        cnt = 1;
      }
    }
  }

  printf("%d", cnt);

  return 0;
}