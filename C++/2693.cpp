#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char **argv){
    int A[10] = {0};
    int T;
    scanf("%d",&T);

    for(int i=0; i<T; i++){
        for(int j=0; j<10;j++){
            scanf("%d",&A[j]);
        }
        sort(A, A + 10);
        printf("%d\n", A[7]); // 3번째 큰 값 9 8 7
    }

    return 0;
}