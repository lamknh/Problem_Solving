#include <iostream>
using namespace std;

int main(int argc, char **argv){
    char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
    char caesar[26] = {'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C'};

    string ccode;
    char code;

    cin >> ccode;

    for(int i = 0; i < ccode.size(); i++){
        code = ccode[i];
        for(int j = 0; j < 26; j++){
            if(code == caesar[j]){
                printf("%c", alphabet[j]);
            }
        }
    }

    return 0;
}