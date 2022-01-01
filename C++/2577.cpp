#include <iostream>

int main(void){
    int A, B, C, num;
    int num_type[10] = {0};
    scanf("%d %d %d", &A, &B, &C);
    num = A * B * C;

    while(num != 0){ // 마지막에 0이 되었을 때 0 % 10 = 0
        num_type[num % 10]++;
        num /= 10;
    }

    for(int i = 0; i < 10; i++){
        printf("%d\n", num_type[i]);
    }

    return 0;
}