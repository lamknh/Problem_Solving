#include <iostream>

int N, cnt = 0;
int col[15]; // col의 index가 열, col의 값이 행
bool promising(int x){
  for(int i = 0; i < x; i++){
    // 세로나 대각선에 위치하는 경우 - 가로는 이미 반복문을 사용해 한 행에 하나만 위치하도록 제한하여 상관 x
    if(col[i] == col[x] || abs(col[i] - col[x]) == x - i){
      return false; // 퀸 놓기 불가능
    }
  }
  return true; // 유망함 - 퀸 놓기 가능
}

void nQueens(int x){
  if(x == N){ // 마지막 줄에 퀸을 둘 수 있는 경우
    cnt++;
  } else {
    for(int i = 0; i < N; i++){ // 모든 열 체크하면서
      col[x] = i; // 퀸 배치
      if(promising(x)){ // 유효한 경우
        nQueens(x+1); // 다음 행에 퀸 배치
      }
    }
  }
}
int main(){
  scanf("%d", &N);
  nQueens(0); // 제일 처음 행부터 퀸 두기 시작
  printf("%d", cnt);
  return 0;
}