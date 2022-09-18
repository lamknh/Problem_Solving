#include <iostream>
#include <string>
#include <vector>
#include <map> // hash map

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string, int> m; // map - 2가지 요소 (이름을 저장할 필요 없음)
    
    for(int i = 0; i < clothes.size(); i++){
        m[clothes[i][1]]++;
    }
    
    for(auto iter : m){
        if(answer == 0){
            answer = iter.second + 1;
        } else {
            answer *= (iter.second + 1);
        }
    }
    
    return answer - 1;
}