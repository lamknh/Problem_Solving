#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int A, B, C;
    scanf("%d %d %d",&A,&B,&C);

    if((A >= B && C >= A) || (A >= C && B >= A)){
        printf("%d", A);
    } else if((B >= A && C >= B) || (B >= C && A >= B)){
        printf("%d", B);
    } else {
        printf("%d", C);
    }

    return 0;
}