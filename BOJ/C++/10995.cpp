#include <iostream>

int main(int argc, char **argv){
    int N;
    scanf("%d",&N);
    
    for(int i=0; i<N; i++){
        if(i % 2 == 1){
            printf(" ");
        }
        for(int j=0; j<N; j++){
            printf("*");
            if(j != N-1){
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}