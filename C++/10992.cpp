#include <iostream>

int main(int argc, char **argv){
    int N;
    scanf("%d",&N);

    for(int i=0; i<N; i++){
        for(int j=N-1; j>i; j--){
            printf(" ");
        }

        if(i == 0){
            printf("*");
        } else if(i == N-1){
            for(int j=0; j<2*N-1; j++){
                printf("*");
            }
        } else {
            printf("*");
            for(int j=0; j<2*i-1; j++){
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }

    return 0;
}