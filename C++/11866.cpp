#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char **argv){ // Segfault
    int N, K, cnt = 1;
    queue<int> q;
    scanf("%d %d", &N, &K);

    for(int i=1; i<=N; i++){
        q.push(i); // 값 넣기
    }

    printf("<");
    while(!q.empty()){
        if(q.size() == 1){
            printf("%d", q.front());
            q.pop();
            break; // cnt == K일 때 아무것도 없는 q에서 front를 구하기 때문에 segfault
        }
        if(cnt == K){
            printf("%d, ", q.front());
            q.pop();
            cnt = 1;
        } else {
            q.push(q.front());
            q.pop();
            cnt++;
        }
    }
    printf(">");

    return 0;
}