#include <iostream>

int main(int argc, char **argv){
    int M, N, sum = 0, min = 0;
    int a[10001];
    scanf("%d %d",&M,&N);

    for(int i=2; i<=10000; i++) {
        a[i] = i; // 배열 초기화 (인덱스의 숫자로)
    }

    for(int i=2; i<=10000; i++) {
        if(a[i]==0){
            continue; // 이미 지워진 수 -> 건너뛰기
        }

        for(int j=2*i; j<=10000; j+=i) { // 지워진 수 아닌 경우(소수) -> 배수 전부 지우기
            a[j] = 0; // j의 첫번째 배수에서 수 끝까지, j = j + i (다음 배수 i만큼 더하는 것과 같다)
        }
    }

    for(int i=M;i <= N;i++) {
        if(a[i]!=0) {
            sum += a[i];
            if(min == 0){
                min = a[i];
            }
        }
    }

    if(sum == 0 && min == 0) {
        printf("-1");
        return 0;
    }

    printf("%d\n%d", sum, min);

    return 0;
}