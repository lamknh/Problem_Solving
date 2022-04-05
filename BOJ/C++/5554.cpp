#include <iostream>

int a[4];
int sum = 0;
int main(){
  for(int i = 0; i < 4; i++){
    scanf("%d", &a[i]);
    sum += a[i];
  }

  printf("%d\n%d", sum / 60, sum % 60);

  return 0;
}