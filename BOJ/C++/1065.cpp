#include <iostream>

int hansoo(int n){ // 1000 미만
    if(n >= 100){
        int sum = 0;
        int n1, n2, n3;

        for(int i = 100; i <= n; i++){
            n1 = i / 100;
            n2 = (i - n1 * 100) / 10;
            n3 = i % 10;
            if((n1 - n2) == (n2 - n3)){
                sum += 1;
            }
        }
        
        return 99 + sum;
    } else {
        return n;
    }
}

int main(int argc, char **argv){
    int N; // 1~1000
    int sum;
    scanf("%d", &N);

    printf("%d", hansoo(N));

    return 0;
}