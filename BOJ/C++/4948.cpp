#include <iostream>
#define MAX 123456 * 2

int a[MAX + 1];
int n;
int main(int argc, char **argv){
    for(int i = 1; i <= MAX; i++){
        a[i] = i; // 초기화
    }

    for(int i = 2; i <= MAX; i++){
        if(a[i] == 0){
            continue; // 건너뛰기
        }
        for(int j = i*2; j <= MAX; j+=i){ // i의 배수
            a[j] = 0;
        }
    }

    do{
        int cnt = 0;
        scanf("%d", &n);
        if(n == 0){
            return 0;
        }
        if(n == 1){
            printf("1\n");
            continue;
        }
        for(int i = n + 1; i <= n*2; i++){
            if(a[i] != 0){
                cnt++;
            }
        }
        printf("%d\n", cnt);
    } while(n != 0);
    
    return 0;
}