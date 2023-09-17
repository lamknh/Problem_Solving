#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[10000001];
int cnt = 0;

int main(){
  scanf("%d", &N);
  scanf("%d", &M);

  for(int i = 0; i < N; i++){
    scanf("%d", &arr[i]);
  }

  sort(arr, arr + N); // array sort

  // 갑옷은 고유 번호 가지고 있어서 2 pointer 가능
  for(int i = 0; i < N; i++){
    for(int j = N-1; j > i; j--){
      if(arr[i] + arr[j] == M){
        i++;
        cnt++;
      }
    }
  }

  printf("%d", cnt);

  return 0;
}