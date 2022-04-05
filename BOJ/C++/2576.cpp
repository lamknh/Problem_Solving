#include <iostream>

int main(int argc, char **argv){
    int sum = 0, x, min = 999;
    for(int i=0; i<7; i++){
        scanf("%d",&x);
        if(x % 2 != 0){
            sum += x;
            if(x < min){
                min = x;
            }
        }
    }

    if(sum == 0){ // min == 999 안됨. 왜인지는 모르겠다 오잉... 
        printf("-1");
    } else {
        printf("%d\n",sum);
        printf("%d",min);
    }

    return 0;
}