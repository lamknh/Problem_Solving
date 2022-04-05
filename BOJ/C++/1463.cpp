#include <iostream>

int main(int argc, char **argv){
    int dp[1000001] = {0}; //dp -> 반대로 생각해서 채우기
    int x;
    scanf("%d",&x);

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for(int i = 4; i <= x; i++){ // 전부 다 구할 필요 없다.
        // 제일 적은 연산 + 1 = 제일 작은 연산값
        dp[i] = dp[i-1] + 1;
        if((i % 3) == 0){ // 배수인 것 구해야
            if((dp[i/3] + 1) < dp[i]){
                dp[i] = dp[i/3] + 1;
            }
        }
        if((i % 2) == 0){ //else if 대신
            if((dp[i/2] + 1) < dp[i]){
                dp[i] = dp[i/2] + 1;
            }
        }
        // 그냥 dp[i/3] < dp[i/2] && dp[i/3] < dp[i-1] 나누기 하면 안되는 이유 4/3 = 1 (정수화 된다)
    }

    printf("%d",dp[x]);

    return 0;
}