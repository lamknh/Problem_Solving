#include <iostream>
using namespace std;

int main(int argc, char **argv){
    string str;

    cin >> str;

    for(int i = 0; i < str.size(); i++){
        cout << str[i];
        if((i+1) % 10 == 0){
            printf("\n");
        }
        // 문자열을 치환할 생각 하지 말고, 10의 배수가 나오면 \n을 삽입하자.
    }

    return 0;
}