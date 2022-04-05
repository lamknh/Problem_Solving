#include <iostream>

int GCD(int a, int b){
    int tmp;
    while(b){      //b가 0이 될 때까지
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main(int argc, char **argv){
    int t, n;
    long long sum = 0; // int X
    scanf("%d",&t);

    for(int i=0; i<t; i++){
        scanf("%d",&n);
        int * arr = new int[n];
        for(int j=0; j<n; j++){
            scanf("%d",&arr[j]);
        }

        for(int j=0; j<n; j++){
            for(int k=(j+1); k<n; k++){
                sum += GCD(arr[j], arr[k]);
            }
        }

        printf("%lld\n",sum); // long long 출력형
        sum = 0;
    }

    return 0;
}