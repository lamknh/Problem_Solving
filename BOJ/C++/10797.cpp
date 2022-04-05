#include <iostream>

int main(int argc, char **argv){
    int N, x, sum = 0;
    scanf("%d",&N);

    for(int i=0; i<5; i++){
        scanf("%d",&x);
        if(x == N){
            sum++;
        }
    }

    printf("%d\n",sum);

    return 0;
}