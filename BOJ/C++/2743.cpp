#include <iostream>
using namespace std;

int main(int argc, char **argv){
    string str;
    char c;
    int cnt = 0;

    cin >> str;
    for(int i=0; i<str.length(); i++){
        cnt++;
    }

    printf("%d", cnt);

    return 0;
}