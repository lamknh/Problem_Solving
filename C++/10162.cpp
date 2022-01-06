#include <iostream>

int main(int argc, char **argv){
    int T, tmp, A = 0, B = 0, C = 0;
    scanf("%d",&T);

    A = T / 300;
    tmp = T % 300;
    B = tmp / 60;
    tmp = T % 60;
    C = tmp / 10;
    tmp = T % 10;

    if(tmp != 0){
        printf("-1");
    } else {
        printf("%d %d %d", A, B, C);
    }

    return 0;
}