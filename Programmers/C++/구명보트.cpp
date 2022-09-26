#include <string>
#include <vector>
#include <algorithm> // sort
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int start = 0;
    
    sort(people.begin(), people.end()); // 오름차순 정렬
    
    while(start < people.size()){
        int back = people.back(); // vector 제일 끝 back으로 알 수 있음.
        people.pop_back(); // vector pop 가능
        
        if(people[start] + back <= limit){
            answer++;
            start++; // 앞 사람도 같이 태우기
        } else {
            answer++; // 뒷 사람만 혼자 타기
        }
    }
    
    return answer;
}