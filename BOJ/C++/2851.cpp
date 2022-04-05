#include <iostream>

int main(int argc, char **argv){
    int n, sum = 0, tmp = 0;
    for(int i=0; i<10; i++){
        scanf("%d",&n);
        tmp += n;
        if(tmp <= 100){
            sum = tmp;
        } else if (tmp > 100){
            if(tmp - 100 <= 100 - sum){
                sum = tmp;
            }
        }
    }
    printf("%d", sum);
    return 0;
}