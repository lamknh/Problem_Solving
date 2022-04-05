#include <iostream>
#include <algorithm> // max
using namespace std;

int a[4] = {0};
int S, T; // 더 큰 수 출력, 같으면 S 출력
int main(){
  for(int i = 0; i < 4; i++){
    scanf("%d", &a[i]);
    S += a[i];
  }

  for(int i = 0; i < 4; i++){
    scanf("%d", &a[i]);
    T += a[i];
  }

  printf("%d", max(S, T));
  return 0;
}