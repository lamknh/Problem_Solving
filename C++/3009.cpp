#include <iostream>

int main(int argc, char **argv){
    int x1, y1, x2, y2, x3, y3;

    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);

    if(x1 == x2){
        printf("%d ", x3);
    } else if(x2 == x3){
        printf("%d ", x1);
    } else {
        printf("%d ", x2);
    }

    if(y1 == y2){
        printf("%d", y3);
    } else if(y2 == y3){
        printf("%d", y1);
    } else {
        printf("%d", y2);
    }

    return 0;
}