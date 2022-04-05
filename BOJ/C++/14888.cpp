#include <iostream>

int A[101] = {0}; // 수열
int cal[100] = {0}; // 연산자 순서 저장 1 : +, 2 : -, 3 : *, 4 : /

int N;
int plus, minus, multiple, division;
long long min = 9999999999, max = -9999999999;

void DFS(int p, int m, int mul, int div, int cnt){
  if(p == 0 && m == 0 && mul == 0 && div == 0){ // 연산자 다 쓴 경우
    int tmp = A[0];

    for(int i = 1; i <= N; i++){
      if(cal[i] == 1){
        tmp += A[i];
      } else if(cal[i] == 2){
        tmp -= A[i];
      } else if(cal[i] == 3){
        tmp *= A[i];
      } else if(cal[i] == 4){
        tmp /= A[i];
      }
    }

    if(tmp > max){
      max = tmp;
    }
    if(tmp < min){
      min = tmp;
    }

    return;
  }

  for(int i = 1; i <= 4; i++){ // 연산자 1~4
    if(i == 1 && p > 0){
      cal[cnt] = i;
      DFS(p-1, m, mul, div, cnt + 1); // + 수 감소
    } else if(i == 2 && m > 0){
      cal[cnt] = i;
      DFS(p, m-1, mul, div, cnt + 1); // - 수 감소
    } else if(i == 3 && mul > 0){
      cal[cnt] = i;
      DFS(p, m, mul-1, div, cnt + 1); // * 수 감소
    } else if(i == 4 && div > 0){
      cal[cnt] = i;
      DFS(p, m, mul, div-1, cnt + 1); // / 수 감소
    }
  }
}

int main(int argc, char** argv){
  scanf("%d", &N);
  
  for(int i=0; i<N; i++){
    scanf("%d", &A[i]);
  }

  scanf("%d %d %d %d", &plus, &minus, &multiple, &division);

  DFS(plus, minus, multiple, division, 1); // 연산자는 1부터 시작

  printf("%lld\n%lld", max, min); // 출력은 마지막

  return 0;
}