#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char **argv){
    int N, M, tmp, max = 0;
    int card[101] = {};
    scanf("%d %d",&N,&M);

    for(int i=0; i<N; i++){
        scanf("%d",&card[i]);
    }

    for(int i=0; i<N; i++){ // 브루트포스 알고리즘(완전탐색)
        for(int j=i+1; j<N; j++){
            for(int k=j+1; k<N; k++){
                tmp = card[i] + card[j] + card[k];
                if(tmp <= M && tmp > max){
                    max = tmp;
                }
            }
        }
    }

    printf("%d", max);

    return 0;
}