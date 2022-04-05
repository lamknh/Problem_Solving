#include <iostream>
#include <queue> // 우선순위 큐를 이용하여 쉽게 힙을 구현할 수 있다.
#include <vector> // 큐 정렬 위해
using namespace std;

struct compare{
    bool operator()(int a, int b){
        if(abs(a) == abs(b)){ // 절댓값 같은 경우
            return a > b; // 오름차순 (음수가 앞) a > b - 오름차순 / a < b - 내림차순
        } else {
            return abs(a) > abs(b); // 절댓값 크기 오름차순
        }
    }
};

int N, x;
priority_queue<int, vector<int>, compare> pq; // compare을 통해 우선순위 정해주기
int main(int argc, char* argv[]){
    scanf("%d",&N);
    
    for(int i=0; i<N; i++){
        scanf("%d",&x);
        if(x == 0){ // 답 출력
            if(!pq.empty()){
                printf("%d\n", pq.top()); // front말고 top
                pq.pop(); // 값 꺼내기
            } else {
                printf("0\n");
            }
        } else { // 힙에 값 넣기
            pq.push(x);
        }
    }

    return 0;
}