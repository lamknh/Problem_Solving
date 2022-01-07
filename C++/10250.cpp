#include <iostream>

int main(int argc, char **argv){
    int T, H, W, N, cnt = 0;
    int hotel[101][101] = {0};
    scanf("%d",&T);

    for(int i=0; i<T; i++){
        scanf("%d %d %d",&H,&W,&N);
        for(int j=1; j<=W; j++){ // for문 2개 돌리기보다 h1 = n % h / w1 = n / h 쓰는게
            for(int k=1; k<=H; k++){
                hotel[k][j] = 1;
                cnt++;
                if(cnt == N){
                    if(j < 10){
                        printf("%d0%d\n", k, j);
                    } else {
                        printf("%d%d\n", k, j);
                    }
                    
                    break;
                }
            }
        }
        cnt = 0;
    }

    return 0;
}