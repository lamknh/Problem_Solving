#include <iostream>

int main(int argc, char **argv){
    int a, b;

    do{
        scanf("%d %d",&a,&b);
        if(a != 0 && b != 0){ // 전체를 if문으로 묶지 않고 아래의 조건문이 오기 전에 break 시키는게 좋다.
            if(b / a > 0 && b % a == 0){
                printf("factor\n");
            } else if(a / b > 0 && a % b == 0){
                printf("multiple\n");
            } else {
                printf("neither\n");
            }
        }
    }while (a != 0 && b != 0);
    



    return 0;
}