#include <iostream>

int student[31] = {0};
int n;
int main(int argc, char** argv){
  for(int i = 0; i < 28; i++){
    scanf("%d", &n);
    student[n]++;
  }

  for(int i = 1; i <31; i++){
    if(student[i] == 0){
      printf("%d\n", i);
    }
  }

  return 0;
}