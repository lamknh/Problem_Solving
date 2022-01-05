#include <iostream>

int main(int argc, char **argv){
    int N, cnt = 0; // fac 숫자 크기 때문에 직접 구하는 것 불가능
    scanf("%d", &N);

    for(int i = 1; i <= N; i++){ // 5의 배수 개수 구하기 - 2의 배수는 많다.
        if(i % 125 == 0){ // 5 * 5 * 5
            cnt += 3;
        } else if(i % 25 == 0){ // 5 * 5
            cnt += 2;
        } else if(i % 5 == 0){
            cnt++;
        }
    }

    printf("%d", cnt);

    return 0;
}