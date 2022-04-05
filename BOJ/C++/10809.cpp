#include <iostream>

using namespace std;

int main(void){
    string S;
    int num = 0, index;
    int alphabet[26];
    std::fill_n(alphabet, 26, -1); // c++ 배열 초기화

    cin >> S; // string 입력

    for(int i = 0; i < S.length(); i++){
        index = (int)S[i] - 97; //97 = a
        if(alphabet[index] == -1){
            alphabet[index] = num;
        }
        num++;
    }

    for(int i = 0; i < 26; i++){
        printf("%d ", alphabet[i]);
    }

    return 0;
}