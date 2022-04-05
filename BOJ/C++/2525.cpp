#include <iostream>

int main(int argc, char **argv){
    int A, B, C;
    scanf("%d %d %d",&A,&B,&C);
    if(B + C >= 60){
        A += ((B + C) / 60);
        B = ((B + C) % 60);
    } else {
        B += C;
    }

    if(A >= 24){
        A -= 24;  
    } 
    printf("%d %d", A, B);
    
    return 0;
}