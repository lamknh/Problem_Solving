#include <iostream>

void star(int i, int j, int N){
    if(i % 3 == 1 && j % 3 == 1){
        printf(" ");
    } else if(N / 3 == 0 || N / 3 == 2){
        printf("*");
    } else {
        star(i/3, j/3, N/3);
    }
}

int main(int argc, char **argv){
    int N;
    scanf("%d",&N);

    for(int i=0; i<N; i++){
        for(int j = 0; j < N; j++){
            star(i, j, N);
        }
        printf("\n");
    }

    return 0;
}