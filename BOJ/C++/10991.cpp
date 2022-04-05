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
        } else {
            printf("*");
            for(int j=0; j<i; j++){
                printf(" *");
            }
        }
        printf("\n");
    }

    return 0;
}