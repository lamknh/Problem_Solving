#include <iostream>

int main(int argc, char **argv){
    int T, A, B;
    char comma;
    scanf("%d",&T);

    for(int i=0; i<T; i++){
        scanf("%d%c%d", &A, &comma, &B);
        printf("%d\n", A+B);
    }

    return 0;
}