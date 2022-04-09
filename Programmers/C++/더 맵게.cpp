#include <string>
#include <vector>
#include <queue>
using namespace std;

bool flag = true; // 모든 음식 스코빌 지수 넘었는지 여부
int cnt = 0; // 섞은 횟수
priority_queue<int, vector<int>, greater<int>> pq; // 오름차순 정렬

int solution(vector<int> scoville, int K) {
    int answer = -1;
    
    for(int i = 0; i < scoville.size(); i++){
        pq.push(scoville[i]); // 우선순위 큐에 스코빌 지수 넣기 - 자동 정렬
    }
    
    // 스코빌 지수 K 값 안될 경우
    while(pq.size() > 1 && pq.top() < K){
        int front = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        pq.push(front + second * 2);
        cnt++;
    }
    
    // 더 이상 섞을 수 없는 경우
    if(pq.size() == 1 && pq.top() < K){
        return answer;
    }
    
    return cnt;
}