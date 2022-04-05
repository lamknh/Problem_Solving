#include <iostream>

using namespace std;

int main(void){
    int n, maxNum = 0;
    int arr[501][501]; // 값 입력 받는 arr 0 ~ 500
    int dp[501][501] = {0}; // 합계 구할 arr 0 ~ 500
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){ // 1부터 하는 이유는 인덱스 벗어나지 않게 하려고
        for(int j = 1; j <= i; j++) {
            scanf("%d", &arr[i][j]); //값 입력받기
        }
    }

    dp[1][1] = arr[1][1]; // 첫째 줄 값
    for(int i = 2; i <= n; i++){ // 삼각형 두번째 줄 부터 값 합산 시작
        for(int j = 1; j <= i; j++){ 
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j]; // 해당 인덱스와 그 전 줄에서 큰 것 합산
        }
    }

    for(int i=0; i<=n; i++){
        if(maxNum < dp[n][i]){ // 마지막 줄이 결과 값
            maxNum = dp[n][i];
        }
    }

    printf("%d", maxNum);

    return 0;
}