#include <iostream>
#include <queue> // 우선순위 큐를 이용하여 쉽게 힙을 구현할 수 있다.
using namespace std;

int N, x;
priority_queue<int> pq;
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