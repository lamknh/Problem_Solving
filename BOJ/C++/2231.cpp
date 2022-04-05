#include <iostream>
int N, tmp, sum = 0;
int main(int argc, char **argv){ // 부르트포스 알고리즘
    scanf("%d",&N);
    
    for(int i=1; i<=N; i++){
        tmp = i;
        sum += i; // 2의 생성자는 1 (1+1)
        while(tmp > 0){
            sum += tmp % 10;
            tmp /= 10;
            if(tmp == 0 && sum == N){
                printf("%d", i);
                return 0;
            }
        }
        sum = 0;
    }

    printf("0");

    return 0;
}