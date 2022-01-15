#include <iostream>

int a[10001];
int main(int argc, char **argv){

    for(int i=1; i<=10001; i++){
        a[i] = i;
    }

    for(int i=2; i<=10001; i++){
        if(a[i] == 0){
            continue;
        }
        
        for(int j=i*2; j<=10001; j+=i){
            a[j] = 0;
        }
    }

    int T, n;
    scanf("%d",&T);
    for(int i=0; i<T; i++){
        scanf("%d",&n);

        for(int j = n / 2; j>=2; j--){ // n = n/2 - i + n/2 + i 모두가 소수가 되는 i 찾기
            if(a[j] != 0 && a[n-j] != 0){
                printf("%d %d\n", j, n-j);
                break;
            }
        }

    }

    return 0;
}