#include <vector>
#include <iostream>
#include <deque>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    deque<int> dq;
    
    dq.push_back(arr[0]);

    for(int i = 1; i < arr.size(); i++){
        if(!dq.empty() && dq.back() != arr[i]){
            dq.push_back(arr[i]);
        }
    }
    
    for(int i = 0; i < dq.size(); i++){
        answer.push_back(dq[i]);
    }

    return answer;
}
