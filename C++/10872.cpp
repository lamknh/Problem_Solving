#include <iostream>

int factorial(int n){
    if(n > 2){
        n *= factorial(n-1);
    }
    
    return n;
}

int main(int argc, char **argv){
    int N;
    scanf("%d", &N);
    if(N != 0){
        printf("%d", factorial(N));
    } else {
        printf("1");
    }
    return 0;
}