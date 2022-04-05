#include <iostream>

int main(void){
    int T, A, B, num = 0, mul = 1;
    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        scanf("%d %d", &A, &B);
        while(num == 0){ // 조건일 때 반복
            if((B * mul) % A == 0){
                num = B * mul;
                printf("%d\n", num);
            } else {
                mul++;
            }
        }
        num = 0; mul = 1; // 초기화
    }

    return 0;
}