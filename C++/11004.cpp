#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char **argv){
    int N, K;
    scanf("%d %d",&N,&K);
    int * num = new int[N];

    for(int i=0; i<N; i++){
        scanf("%d",&num[i]);
    }

    sort(num, num + N);

    printf("%d", num[K-1]);

    return 0;
}