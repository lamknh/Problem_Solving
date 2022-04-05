#include <iostream>
#include <cmath>

int N;
int A[10000001] = {0};
int B, C;

int main(int argc, char **argv){
    scanf("%d",&N);
    for(int i=1; i<=N; i++){
        scanf("%d",&A[i]); // 시험자 수 입력받기
    }
    scanf("%d %d",&B,&C); // 감독 가능 명 수 입력받기

    long long cnt = 0;
    for(int i=1; i<=N; i++){
        A[i] -= B;
        cnt += 1;
        if(A[i] > 0){
            cnt += (int)ceil(A[i] / (double)C);
        }
    }

    printf("%lld", cnt);
    return 0;
}