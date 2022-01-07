#include <iostream>

int main(int argc, char **argv){ // 소수 - 에라토스테네스의 체
    int M, N;
    int a[1000001];

    scanf("%d %d",&M,&N);

    //소수 판별 범위까지 배열 생성, 값 넣어주기, 해당 수의 배수인 것 하나씩 지워나가기

    for(int i=2; i<=1000000; i++) {
        a[i] = i; // 배열 초기화 (인덱스의 숫자로)
    }

    for(int i=2; i<=1000000; i++) {
        if(a[i]==0){
            continue; // 이미 지워진 수 -> 건너뛰기
        }

        for(int j=2*i; j<=1000000; j+=i) { // 지워진 수 아닌 경우(소수) -> 배수 전부 지우기
            a[j] = 0; // j의 첫번째 배수에서 수 끝까지, j = j + i (다음 배수 i만큼 더하는 것과 같다)
        }
    }

    for(int i=M;i <= N;i++) {
        if(a[i]!=0) {
            printf("%d ", a[i]); // 소수 출력
        }
    }

    return 0;
}