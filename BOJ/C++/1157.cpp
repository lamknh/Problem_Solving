#include <iostream>

using namespace std;

int main(void){
    string a;
    int alphabet[26] = {0};
    int cnt = 0, max = 0 ,idx;
    
    cin >> a;

    for(int i = 0; i < a.length(); i++){ // count
        if(a[i] < 97) { // 대문자일 경우
            alphabet[a[i] - 65]++;
        } else { // 소문자일 경우
            alphabet[a[i] - 97]++;
        }
    }

    for(int i = 0; i < 26; i++){
        if(max < alphabet[i]){
            max = alphabet[i];
            idx = i;
        }
    }

    for(int i = 0; i < 26; i++){
        if(max == alphabet[i]){
            cnt++;
        }
        if(cnt > 1){
            printf("?");
            return 0; // 바로 종료
        }
    }

    printf("%c", idx + 65);

    return 0;
}