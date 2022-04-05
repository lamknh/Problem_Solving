#include <iostream>

int main(void){
    int A, B, n, cnt = 0;
    int num[42] = {0}; // 0으로 초기화 필수

    for(int i = 0; i < 10; i++){
        scanf("%d", &n);
        num[n % 42]++;
    }

    for(int i = 0; i < 42; i++){
        if(num[i] != 0){
            cnt++;
        }
    }

    printf("%d", cnt);

    return 0;
}