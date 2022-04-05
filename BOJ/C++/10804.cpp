#include <iostream>
#include <algorithm>
using namespace std;

int arr[20];
int a, b, tmp;
int main(int argc, char** argv){
  for(int i = 0; i < 20; i++){
    arr[i] = i+1; // 초깃값 설정
  }
  
  for(int i = 0; i < 10; i++){
    scanf("%d %d", &a, &b);

    //뒤집는 작업
    reverse(arr + a-1, arr + b); // 0부터 시작해서 -1 해줘야함.
  }

  for(int i = 0; i < 20; i++){
    printf("%d ", arr[i]); // 출력
  }

  return 0;
}