#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char** argv){
    int N;
    scanf("%d",&N);
    queue<int> q;

    for(int i=1; i<=N; i++){
        q.push(i); // 값 넣기
    }

    while(q.size() != 1){
        q.pop(); // 맨 윗 장 버리기 - FIFO

        q.push(q.front()); // 다음 윗 장 아래로 옮기기
        q.pop();
    }

    printf("%d", q.front());

    return 0;
}