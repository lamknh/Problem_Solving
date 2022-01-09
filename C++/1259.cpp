#include <iostream>
using namespace std;

int main(int argc, char **argv){
    string str;
    char c;
    // 굳이 반복문 쓰지 말고 reverse() 써서 문자열 비교하기
    do{
        cin >> str;
        if(str == "0"){
            return 0;
        }
        if(str.length() % 2 == 0){ // 1221 팰린드롬
            for(int i = 0; i < str.length(); i++){
                c = str[i];
                if(c != str[str.length() - i - 1]){
                    printf("no\n");
                    break;
                }
                if(i == (str.length() / 2 - 1)){
                    printf("yes\n");
                    break;
                }
            }
        } else {
            for(int i = 0; i < str.length(); i++){
                c = str[i];
                if(c != str[str.length() - i - 1]){
                    printf("no\n");
                    break;
                }
                if(i == (str.length() / 2)){
                    printf("yes\n");
                    break;
                }
            }
        }
    } while(str != "0");

    return 0;
}