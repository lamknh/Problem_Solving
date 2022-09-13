#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // sort

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end()); // 빠른 비교를 위한 sort
    
    for(int i = 0; i < phone_book.size() - 1; i++){
        // string find 함수로 해당 문자열 속해있는지 확인할 수 있음
        int cnt = phone_book[i].size();
        // sort를 통해서 바로 다음 친구와 비교만 하면 된다.
        if(phone_book[i] == phone_book[i+1].substr(0, cnt)){
            return false;
        }
    }
    
    return answer;
}