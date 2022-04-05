  #include <iostream>
  using namespace std;

  int most, mostCnt = 0, x;
  int sum = 0;
  int cnt[101] = {0}; // 자연수는 1000보다 작은 10의 배수
  int main(int argc, char** argv){
    for(int i = 0; i < 10; i++){
      scanf("%d", &x);
      sum += x;
      cnt[x / 10]++;
      if(cnt[x / 10] > mostCnt){
        mostCnt = cnt[x/10]; // most는 횟수 세기
        most = x / 10;
      }
    }

    printf("%d\n", sum / 10);
    printf("%d\n", most * 10);

    return 0;
  }