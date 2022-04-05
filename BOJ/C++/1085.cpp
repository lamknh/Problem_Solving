#include <iostream>

using namespace std;

int main(void){
    int x, y, w, h, temp1, temp2, result;
    scanf("%d %d %d %d", &x, &y, &w, &h);

    temp1 = w - x;
    temp2 = h - y;

    result = min(x, min(min(y, temp1), temp2));

    printf("%d", result);

    return 0;
}