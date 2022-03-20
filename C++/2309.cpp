#include <iostream>
#include <algorithm> // sort
using namespace std;

int arr[9] = {0};
int sum;
int main(int argc, char** argv){
  for(int i = 0; i < 9; i++){
    scanf("%d", &arr[i]);
    sum += arr[i];
  }

  sort(arr, arr + 9);

  int ans = sum - 100;

  for(int i = 0; i < 9; i++){ // 브루트포스
    for(int j = i; j < 9; j++){
      if(arr[i] + arr[j] == ans){
        for(int k = 0; k < 9; k++){
          if(k != i && k != j){
            printf("%d\n", arr[k]);
          }
        }
        return 0; // 하나만 출력
      }
    }
  }

  return 0;
}