#include <iostream>
#include <vector>
using namespace std;

int k;
int S[13]; // 6 < k < 13
int lotto[6] = {0};
void dfs(int start, int x){ // start : 함수 시작점 x : 로또 몇번째?
  if(x == 6){ // 로또가 마지막까지 채워지면
    for(int i = 0; i < 6; i++){
      printf("%d ", lotto[i]);
    }
    printf("\n");
    return; // 재귀 종료
  } else {
    for(int i = start; i < k; i++){
      lotto[x] = S[i]; //집합 값 하나씩 lotto에 넣기
      dfs(i+1, x+1); // 넣은 것 다음값 부터 다음 로또값에 집어넣기
    }
  }
}

int main(int argc, char** argv){
  do{ // 0 입력시 종료
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
      scanf("%d", &S[i]);
    }

    dfs(0, 0);
    printf("\n");
  } while(k);

  return 0;
}