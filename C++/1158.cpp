#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char **argv){
    int N, K, i = 0, cnt = 0;
    queue<int> q;
    scanf("%d %d",&N,&K);
    int * circle = new int[N];

    while(q.size() != N){
        if(circle[i] != 1) { // 1이면 circle
            cnt++;
        }
        if(cnt == K){
            circle[i] = 1;
            q.push(i+1);
            cnt = 0;
        }
        i++;
        if(i >= N){
            i = 0;
        }
    }


    printf("<");

    for(int i=0; i<N; i++){ // 큐에 넣고 한번에 출력
        if(i == N - 1){
            printf("%d", q.front());
        } else {
            printf("%d, ", q.front());
        } 
        q.pop();
    }

    printf(">");

    return 0;
}