#include <iostream>

int main(int argc, char **argv){
    int h[3], b[3], min = 999999;
    scanf("%d %d %d %d %d", &h[0], &h[1], &h[2], &b[0], &b[1]);

    for(int i = 0; i <3; i++){
        for(int j = 0; j <2; j++){
            if(h[i] + b[j] < min){
                min = h[i] + b[j];
            }
        }
    }

    printf("%d\n", min - 50);

    return 0;
}