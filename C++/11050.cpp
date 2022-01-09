#include <iostream>


int main(int argc, char **argv){
    int N, K;
    int sumN = 1, sumK = 1;
    scanf("%d %d", &N, &K);

    for(int i = N; i > N - K; i--){
        sumN *= i;
    }

    for(int i = K; i > 0; i--){
        sumK *= i;
    }

    printf("%d", sumN / sumK);

    return 0;
}