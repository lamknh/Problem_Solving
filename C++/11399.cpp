#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int N, n, cnt = 0, result = 0;
    scanf("%d", &N);
    int * time = new int[N]; //동적할당

    for(int i = 0; i < N; i++){
        scanf("%d", &n);
        time[i] = n;
    } // 기다리는 시간 적은 사람 먼저 줄 서야지 총 줄 서는 시간을 줄일 수 있다.

    sort(time, time + N); // sort 컴파일 에러 남

    for(int i = 0; i < N; i++){
        cnt += time[i];
        result += cnt;
    }

    printf("%d", result);

    return 0;
}