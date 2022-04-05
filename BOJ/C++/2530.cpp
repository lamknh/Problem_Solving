#include <iostream>

int main(int argc, char **argv){
    int A, B, C, D, tmp1, tmp2;
    scanf("%d %d %d %d", &A, &B, &C, &D);

    if((C+D) >= 60){
        tmp1 = (C + D) / 60;
        C = (C + D) % 60;
        if((B + tmp1) >= 60){
            tmp2 = (B + tmp1) / 60;
            B = (B + tmp1) % 60;
            A += tmp2;
            if(A >= 24){
                A = A % 24;
            }
        } else {
            B = B + tmp1;
        }
    } else {
        C = C + D;
    }

    printf("%d %d %d", A, B, C);

    return 0;
}