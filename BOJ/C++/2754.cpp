#include <iostream>
using namespace std;

int main(int argc, char **argv){
    string str;

    cin >> str;

    if(str == "A+"){
        printf("4.3");
    } else if(str == "A0"){
        printf("4.0");
    } else if(str == "A-"){
        printf("3.7");
    } else if(str == "B+"){
        printf("3.3");
    } else if(str == "B0"){
        printf("3.0");
    } else if(str == "B-"){
        printf("2.7");
    } else if(str == "C+"){
        printf("2.3");
    } else if(str == "C0"){
        printf("2.0");
    } else if(str == "C-"){
        printf("1.7");
    } else if(str == "D+"){
        printf("1.3");
    } else if(str == "D0"){
        printf("1.0");
    } else if(str == "D-"){
        printf("0.7");
    } else {
        printf("0.0");
    }

    return 0;
}