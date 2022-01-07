#include <iostream>

int main(int argc, char **argv){
    int T, s, n, q, p, sum = 0;
    scanf("%d",&T); // test case 수

    for(int i=0; i<T; i++){
        scanf("%d",&s); // 자동차의 가격
        sum += s;
        scanf("%d",&n); // 옵션 개수
        for(int j=0; j<n; j++){
            scanf("%d %d",&q,&p); // 특정 옵션 개수, 옵션 가격
            sum += q * p;
        }
        printf("%d\n", sum);
        sum = 0;
    }

    return 0;
}