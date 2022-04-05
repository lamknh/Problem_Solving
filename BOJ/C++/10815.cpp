#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char **argv){
    int N, M, x;
    scanf("%d", &N); // 상근이의 카드 개수
    int * sang = new int[N];

    for(int i=0; i<N; i++){
        scanf("%d", &sang[i]);
    }

    sort(sang, sang + N); // 정렬

    scanf("%d", &M); // 판단 수
    for(int i=0; i<M; i++){
        scanf("%d", &x);
        if(binary_search(sang, sang + N, x)){
            printf("1 ");
        } else {
            printf("0 ");
        }
    }
    return 0;
}