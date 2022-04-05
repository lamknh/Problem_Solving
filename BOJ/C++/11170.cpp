#include <iostream>

int T, N, M;
int main(int argc, char **argv){
    scanf("%d",&T);

    for(int i=0; i<T; i++){
        int sum = 0;
        scanf("%d %d",&N,&M);
        for(int j=N; j<=M; j++){
            int tmp = j;
            if(tmp == 0){
                sum++;
            }
            while(tmp > 0){ // j 자체를 나누면 무한루프에 걸린다. 다른 변수를 써야함.
                if(tmp % 10 == 0){
                    sum++;
                }
                tmp /= 10;
            }
        }

        printf("%d\n",sum);
    }

    return 0;
}