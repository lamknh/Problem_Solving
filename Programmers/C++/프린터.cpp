#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility> // pair

using namespace std;

queue<pair<int, int> > q; // 중요도, 순서
priority_queue<int> order; // 순서

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    for(int i = 0; i < priorities.size(); i++){
        q.push({priorities[i], i}); // 큐는 push_back X
        order.push(priorities[i]); // 중요도 순서 저장
    }
    
    while(!q.empty()){
        int prio = q.front().first; // 큐 제일 앞
        int loc = q.front().second;
        
        int orderPrio = order.top(); // priority queue는 top
        
        q.pop();
        
        if(orderPrio == prio){
            answer++; // 출력
            order.pop();
            if(loc == location){
                break; // if문 안에 if문을 뒀어야...
            }
        } else {
            q.push({prio, loc});
        }
    }
    
    return answer;
}