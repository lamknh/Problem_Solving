#include <iostream>

int main(void){
    int H, M;
    scanf("%d %d", &H, &M);

    if(M < 45){
        H -= 1;
        M = 60 - (45 - M);
    } else {
        M -= 45;
    }

    if(H == -1){
        H = 23;
    }

    printf("%d %d", H, M);
    return 0;
}