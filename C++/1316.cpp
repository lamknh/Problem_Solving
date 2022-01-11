#include <iostream>
using namespace std;

int N;
string str;
int alphabet[26] = {0};
int cnt = 0, idx = 99999;

int main(int argc, char **argv){
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        cin >> str;
        char c;
        for(int i = 0; i < str.size(); i++){
            c = str[i];
            if(idx != c - 97 && alphabet[c - 97] != 0){ // 이전 인덱스
                break;
            }
            idx = c - 97; // 현재 인덱스
            alphabet[idx]++;
            if(i == (str.size() - 1)){
                cnt++;
            }
        }
        for(int i = 0; i < 26; i++){
            alphabet[i] = 0; // 초기화
        }
    }

    printf("%d\n", cnt);

    return 0;
}