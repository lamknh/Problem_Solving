#include <iostream>
using namespace std;

int main(int argc, char **argv){
    string str; //getline으로 한 줄씩 받기
    while (1){
        getline(cin, str);
        if(str == ""){ // 아무것도 입력되지 않을 때 까지
            break;
        }
        cout << str << endl;
    }

    return 0;
}