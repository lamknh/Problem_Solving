#include <iostream>

int dp1[41] = {0};
int dp2[41] = {0};

void fibonacci() { // 그대로 쓰면 시간 초과
    dp1[0] = 1; dp1[1] = 0;
    dp2[0] = 0; dp2[1] = 1;
    
    for (int i = 2; i <= 41; i++){
        dp1[i] = dp1[i-2] + dp1[i-1];
        dp2[i] = dp2[i-2] + dp2[i-1];
    }
}

int main(int argc, char **argv){
    int T, N;
    scanf("%d",&T);
    fibonacci();

    for (int i=0; i<T; i++){
        scanf("%d", &N);
        printf("%d %d\n", dp1[N], dp2[N]);
    }

    return 0;
}