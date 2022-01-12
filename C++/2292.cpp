#include <iostream>

int N; // int로 커버 가능
int d = 1, tmp = 0, cnt = 0;
int main(int argc, char **argv){    
    scanf("%d", &N);
    while(tmp < N){
        tmp += d;
        cnt++;
        if(tmp < N){
            d = 6*cnt; // 한 줄에 6씩 증가한 별집 수.
        }
    }

    printf("%d\n", cnt);
    return 0;
}