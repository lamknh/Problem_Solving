#include <iostream>

int main(void){ // 그리디 알고리즘
    int n, coin = 0, money = 1000;
    int coin_type[6] = {500, 100, 50, 10, 5, 1};
    scanf("%d", &n);

    money -= n;
    
    for(int i = 0; i < 6; i++){
        coin += money / coin_type[i];
        money %= coin_type[i];
    }
    
    printf("%d", coin);

    return 0;
}