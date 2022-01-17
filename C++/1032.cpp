#include <iostream>
using namespace std;

string str;
string tmp;
char c;
int main(int argc, char **argv){
    int N;
    scanf("%d",&N);

    cin >> str;
    for(int i=0; i<N-1; i++){
        cin >> tmp;
        for(int j=0; j<tmp.length(); j++){
            c = tmp[j];
            if(c != str[j]){
                str[j] = '?';
            }
        }
    }

    cout << str;

    return 0;
}