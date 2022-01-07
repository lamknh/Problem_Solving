#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char **argv){
    int N, S = 0; // 초기화 안해줘서 오류났음
    scanf("%d",&N);
    int * A = new int[N];
    int * B = new int[N];

    for(int i=0; i<N; i++){
        scanf("%d",&A[i]);
    }

    sort(A, A+N, greater<int>()); // 역순 정렬

    for(int i=0; i<N; i++){
        scanf("%d",&B[i]);
    }

    sort(B, B+N);

    for(int i=0; i<N; i++){
        S += A[i] * B[i];
    }

    printf("%d",S);

    return 0;
}