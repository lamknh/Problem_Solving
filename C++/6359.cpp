#include <iostream>

int T, n, tmp = 1;
int main(int argc, char** argv){
  scanf("%d", &T);

  for(int i = 0; i < T; i++){
    int arr[101] = {0}; // 0 : 닫힘, 1 : 열림
    int cnt = 0;
    scanf("%d", &n);
    for(int j = 1; j <= n; j++){
      tmp = j;
      while(tmp <= n){
        if(arr[tmp] == 0){
          arr[tmp] = 1;
        } else {
          arr[tmp] = 0;
        }
        tmp += j;
      }
    }

    for(int j = 1; j <= n; j++){
      if(arr[j] == 1){
        cnt++;
      }
    }
    printf("%d\n", cnt);
  }

  return 0;
}