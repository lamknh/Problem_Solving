#include <iostream>

int main(void){
    int a, b, c;
    
    do{
        scanf("%d %d %d", &a, &b, &c);
        if( a != 0 && b != 0 && c != 0){
            if(a * a + b * b == c * c || b * b + c * c == a * a || c * c + a * a == b * b){
                printf("right\n");
            } else {
                printf("wrong\n");
            }
        }
    } while(a != 0 && b != 0 && c != 0);

    return 0;
}