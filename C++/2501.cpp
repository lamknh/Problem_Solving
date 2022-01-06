#include <iostream>

int main(int argc, char **argv){ // 브루트 포스 알고리즘 -> 완전 탐색 알고리즘
    int N, K, cnt = 0 ;
    int q[10001] = {0, 1, 0};
    scanf("%d %d",&N,&K);

    for(int i=1; i<=N; i++){
        if(N % i == 0){
            q[i] = 1;
        }
    }

    for(int i=1; i<=N; i++){
        if(q[i] == 1){
            cnt++;
        }
        if(cnt == K){
            printf("%d", i);
            break;
        }
    }

    if(cnt != K){
        printf("0");
    }

    return 0;
}