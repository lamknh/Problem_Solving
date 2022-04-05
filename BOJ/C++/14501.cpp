#include <iostream>
#include <algorithm> // max
using namespace std;

int N;
int T[16]; // 상담 완료 걸리는 기간
int P[16]; // 상담 금액
int dp[16] = {0}; //dp용 배열

int main(int argc, char **argv){
    scanf("%d",&N);
    for(int i=1; i<=N; i++){
        scanf("%d %d",&T[i],&P[i]); // 모두 입력받기
    }

    for(int i=N; i>0; i--){ // 뒤에서부터 탐색, 퇴사일 고려 위해
        int day = i + T[i]; // 처리 완료 날짜 = 현재 날짜 + 걸리는 일
        if(day > N+1){ // 퇴사 일 넘어가는 경우
            dp[i] = dp[i+1]; // 그대로 최대 이익 이월
        } else {
            dp[i] = max(dp[i+1], dp[day] + P[i]); // 현재 최대 이익, 얻을 수 있는 최대 이익 비교
        }
    }

    printf("%d", dp[1]); // 마지막 탐색 값

    return 0;
}