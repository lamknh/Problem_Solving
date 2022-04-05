#include <iostream>
using namespace std;

int main(int argc, char **argv){
    string str;
    cin >> str;
    char c;

    printf("%c", str[0]);
    for(int i=1; i<str.size(); i++){
        c = str[i];
        if(c == '-'){ // char 비교시에는 "" 말고 ''
            printf("%c", str[i+1]);
        }
    }

    return 0;
}