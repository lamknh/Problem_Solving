#include <iostream>

int main(void){
    int N, n, cnt = 0, result = 0;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d", &n);
        for(int j = 1; j < n; j++){ // 1부터 자기자신 전까지 나누어주기
            if(n % j == 0){ 
                cnt++; // 나누어 떨어지는 수 개수 세기
            }
        }
        
        if (cnt == 1){ // 나누어 떨어지는 수가 1밖에 없을 때
            result++;
        }

		cnt = 0;
    }

    printf("%d", result);

    return 0;
}