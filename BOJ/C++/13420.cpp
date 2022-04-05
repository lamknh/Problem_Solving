#include <iostream>

int N;
long long a, b, c; // 32 비트 말고 64 비트
char oper[2];
bool answer = true; // 정답
int main(int argc, char** argv){
  scanf("%d", &N);

  for(int i = 0; i < N; i++){
    scanf("%lld %c %lld %c %lld", &a, &oper[0], &b, &oper[1], &c);

    if(oper[0] == '+'){
      if(a + b != c){
        answer = false;
      }
    } else if(oper[0] == '-'){
      if(a - b != c){
        answer = false;
      }
    } else if(oper[0] == '*'){
      if(a * b != c){
        answer = false;
      }
    } else if(oper[0] == '/'){
      if(a / b != c){
        answer = false;
      }
    }

    if(answer){
      printf("correct\n");
    } else {
      printf("wrong answer\n");
    }

    answer = true; // 초기화
  }

  return 0;
}