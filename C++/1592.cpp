#include <iostream>

int N, M, L; // 자리 수, 종료 조건, L번째
int arr[51] = {0};
int cnt = 0, idx = 1; // 1번 학생부터 시작
int main(int argc, char** argv){
  scanf("%d %d %d", &N, &M, &L);

  while(arr[idx] != M){
    cnt++; // 공 던지는 횟수 세기

    if(arr[idx] % 2 != 0){ // 홀수인 경우 시계 방향
      if(idx + L > N){ // 범위 초과
        idx = (idx + L) - N;
      } else {
        idx = idx + L;
      }
    } else { // 짝수인 경우 시계 반대 방향
      if(idx - L < 1){ // 범위 초과
        idx = N + (idx - L);
      } else {
        idx = idx - L;
      }
    }
    arr[idx]++; // 공 받은 횟수 세기
  }

  printf("%d", cnt - 1); // 첫번째 시작은 공 안 던짐

  return 0;
}