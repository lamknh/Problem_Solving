#include <iostream>

int main(int argc, char **argv){
    int c = 100, s = 100;
    int n, x, y;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d %d", &x, &y);
        if(x < y){
            c -= y;
        } else if(x > y){
            s -= x;
        }
    }

    printf("%d\n", c);
    printf("%d\n", s);

    return 0;
}