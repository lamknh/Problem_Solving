#include <iostream>

int main(int argc, char **argv){
    int K, N, M, tmp;
    scanf("%d %d %d",&K,&N, &M);

    tmp = K * N - M;

    if(tmp >= 0){
        printf("%d", tmp);
    } else {
        printf("0");
    }
    

    return 0;
}