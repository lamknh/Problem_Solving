#include <iostream>

int A, B;
int num[10000] = {0};
int n = 1;
int sum = 0;
int main(int argc, char** argv){
  scanf("%d %d", &A, &B);

  for(int i = 1; i <= 1000; i++){
    for(int j = 0; j < n; j++){
      num[i++] = n;
    }
    i--;
    n++;
  }

  for(int i=A; i<=B; i++){
    sum += num[i];
  }

  printf("%d", sum);

  return 0;
}