#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int a, b, maxNum = 1, minNum = 0, div = 1;
    scanf("%d %d",&a,&b);

    for(int i=2; i <= min(a, b); i++){
        if(a % i == 0 && b % i == 0){
           maxNum = i;
        }
    }
    printf("%d\n", maxNum);
        

    while(minNum == 0){
        if((b * div) % a == 0){
            minNum = b * div;
            printf("%d", minNum);
        }
        div++;
    }

    return 0;
}