#include <string>
#include <vector>
#include <deque>
#include <utility> // pair
using namespace std;

deque<pair<int, int>> dq; // 현재 작업량, speed
int cnt = 0; // 기능 수 세기
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer; // 작업 
    
    for(int i = 0; i < progresses.size(); i++){
        dq.push_back({progresses[i], speeds[i]}); // 큐에 작업 넣기
    }
    
    //작업 모두 끝날 때 까지
    while(!dq.empty()){
        int progress = dq.front().first;
        int speed = dq.front().second;
        
        if(progress < 100){ // 첫번째 기능 
            for(int i = 0; i < dq.size(); i++){ // 모든 큐 순회
                dq[i].first += dq[i].second; // 작업 진행
                printf("!%d ", dq[i]);
            }
            printf("\n");
        } else {
            while(1){ // 큐는 배열 말고 while로 탐색해서 pop 해주기
                if(dq.front().first >= 100){
                    dq.pop_front(); // 100 넘은 값 삭제
                    cnt++; // 기능 수 세기
                } else {
                    // 처음부터 탐색하다가 이제 100 안 넘은 값 발견했을 때
                    printf("cnt : %d", cnt);
                    answer.push_back(cnt); // 배포 수 입력
                    cnt = 0; // 초기화
                    break;
                }
            }
        }
    }
    
    return answer;
}