#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char **argv){
    int N;
    scanf("%d", &N);
    int * arr = new int[N]; // 동적 할당

    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + N);

    for(int i = 0; i < N; i++){
        printf("%d\n", arr[i]);
    }

    return 0;
}