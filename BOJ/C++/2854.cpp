#include <iostream>

int main(int argc, char **argv){
    int L, P, x, ppl;
    scanf("%d %d",&L,&P);

    ppl = L * P;

    for(int i=0; i<5; i++){
        scanf("%d",&x);
        printf("%d ", x - ppl);
    }

    return 0;
}