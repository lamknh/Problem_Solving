#include <iostream>
#include <cmath>

using namespace std;

long long num[1000001] = {0}; // 최대 1,000,000개 수 체크 - 양수면 제곱ㅇㅇ수
long long minN, maxN;

int main() {
  cin >> minN >> maxN;
  int cnt = 0;

  // 제곱 구할 수 반복문
  for(long long i = 2; i <= sqrt(maxN); i++){
    // 제곱수의 배수 시작 찾기
    long long n = minN / (i * i); // 제곱수 몫 찾기, () 주의하기 minN/i * i 라고 쓰면 안됨
    
    // minN이 제곱수로 나누어지지 않는 경우
    if(minN % (i * i)){
      n += 1; // 다음 몫부터 계산 시작
    }

    // maxN까지 제곱수 에라토스테네스의 체
    while(n * i * i <= maxN){
      num[n * i * i - minN] = 1; // 제곱ㅇㅇ수 체크
      n++; // 다음 제곱 수 찾기
    }
  }

  for(int i = 0; i <= maxN - minN; i++){
    if(num[i] == 0){
      cnt++;
    }
  }

  cout << cnt;

  return 0;
}