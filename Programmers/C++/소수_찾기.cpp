#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // sort

using namespace std;

int arr[10000001] = {0}; // 7자리니까 8자리로 잡아야
vector<int> nums;
set<int> num;

// 에라토스테네스의 체
void prime(){
    arr[0] = 1; arr[1] = 1; // 0과 1은 소수 아님
    
    for(int i = 2; i < 10000001; i++){
        if(arr[i] != 0){
            continue;
        }
        
        for(int j = 2 * i; j < 10000001; j+=i){
            arr[j] = 1; // 소수 체크
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    
    prime(); // 소수 체크
    
    sort(numbers.begin(), numbers.end());
    
     do{
        for(int i = 1; i <= numbers.size(); i++){
            string num = numbers.substr(0, i);
            
            if(arr[stoi(num)] == 0){
                answer++;
                arr[stoi(num)] = 3; // 방문 체크
            }
        }
    } while(next_permutation(numbers.begin(), numbers.end()));
    
    return answer;
}