#include <iostream>

int main(int argc, char **argv){
    int month, day;
    scanf("%d %d",&month,&day);
    if(month < 2 || (month == 2 && day < 18)){
        printf("Before");
    } else if (month == 2 && day == 18){
        printf("Special");
    } else {
        printf("After");
    }

    return 0;
}