#include <iostream>
#include <cmath>
#define PI 3.141592653589793

int main(int argc, char **argv){
    int R;
    scanf("%d",&R);

    printf("%lf\n", pow(R,2) * PI);
    printf("%lf", pow(R,2) * 2);

    return 0;
}