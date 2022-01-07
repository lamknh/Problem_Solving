#include <iostream>
using namespace std;

int main(int argc, char **argv){
    string str;
    while (getline(cin, str)){//getline으로 한 줄씩 받기 - 입력있을 때 까지.
        cout << str << endl;
    }

    return 0;
}