#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // sort

using namespace std;

vector<string> n;

bool compare(string &a, string &b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    for(int i = 0; i < numbers.size(); i++){
        n.push_back(to_string(numbers[i]));
    }
    
    sort(n.begin(), n.end(), compare);
    
    for(int i = 0; i < n.size(); i++){
        answer += n[i];
    }
    
    if(answer[0] == '0'){
        answer = "0";
    }
    
    return answer;
}