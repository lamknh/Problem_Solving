#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char **argv){
    int num;
    scanf("%d",&num);
    int * A = new int[num];

    for(int i=0; i<num; i++){
        scanf("%d",&A[i]);
    }

    sort(A, A + num);

    printf("%d", A[0] * A[num-1]);

    return 0;
}