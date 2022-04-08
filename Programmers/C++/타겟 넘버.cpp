#include <string>
#include <vector>
using namespace std;

bool visited[21] = {0}; // 방문 여부
int Numbers[21] = {0}; // 숫자 저장
int arrSize;
int Target;

int cnt = 0;
bool flag = true; // 모두 탐색 되었는지 검사

//백트래킹
void DFS(int idx, int tmp){
    if(tmp == Target && idx == arrSize){  
        for(int j = 0; j < arrSize; j++){
            if(visited[j] == 0){
                flag = false;
            }
        }
        
        if(flag){
            cnt++;
        } else {
            flag = true; // 초기화
        }
        return;
    }
    
    for(int i = idx; i < arrSize; i++){
        visited[i] = 1;
        DFS(i+1, tmp - Numbers[i]);
        DFS(i+1, tmp + Numbers[i]);
        visited[i] = 0;
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    for(int i = 0; i < numbers.size(); i++){
        Numbers[i] = numbers[i]; // 벡터 복사
    }
    arrSize = numbers.size();
    Target = target;
    
    DFS(0, 0); // 첫 숫자부터 값 0부터 시작
    
    answer = cnt;
    
    return answer;
}