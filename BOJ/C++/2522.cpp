#include <iostream>

int main(int argc, char **argv){
    int N;
    scanf("%d",&N);

    for(int i=1; i<N*2; i++){
        if(i <= N){
            for(int j=0; j <N-i; j++){
                printf(" ");
            }
            for(int j=0; j < i; j++){
                printf("*");
            }
        } else {
            for(int j=0; j<i-N; j++){
                printf(" ");
            }
            for(int j=2*N; j >i; j--){
                printf("*");
            }
        }
        printf("\n");
    }

    return 0;
}