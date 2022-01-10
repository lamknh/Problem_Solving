#include <iostream>


int main(int argc, char **argv){
    int N, div = 2;
    scanf("%d",&N);

    while(N != 1){
        if(N % div == 0){
            N /= div;
            printf("%d\n", div);
        } else {
            div++;
        }
    }

    return 0;
}