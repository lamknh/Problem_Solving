#include <iostream>

int main(void){
    int N, K, Ai, count = 0;
    scanf("%d %d", &N, &K);
    int * A = new int[N]; // 동적 배열 할당

    for(int i=0; i<N; i++){
        scanf("%d", &Ai);
        A[i] = Ai;
    }

    for(int i = N-1; i >= 0; i--){ // 배열은 0부터 N-1까지다.
        count += (K / A[i]);
        K %= A[i];
    }

    printf("%d", count);

    return 0;
}