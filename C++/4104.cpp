#include <iostream>

int main(int argc, char **argv){
    int a, b;

    do{
        scanf("%d %d",&a,&b);

        if(a == 0 && b == 0){
            return 0;
        }

        if(a > b){
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    } while(a != 0 && b != 0);

    return 0;
}