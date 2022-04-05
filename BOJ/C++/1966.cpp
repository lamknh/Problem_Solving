#include <iostream>
#include <queue>
using namespace std;

int T, N, M, x;
bool flag = true;
int main(int argc, char **argv){ // 우선순위 큐 -> 자동으로 우선순위따라 정렬
    scanf("%d", &T);

    int max = 0;
    for(int i=0; i<T; i++){
        scanf("%d %d", &N, &M);

        queue<pair<int, int> > q;
        priority_queue<int> pq;

        for(int j=0; j<N; j++){
            scanf("%d", &x);
            q.push(make_pair(j, x)); // index, 중요도값
            pq.push(x); // 중요도 우선순위 큐
        }

        int cnt = 0;
        while(!q.empty()){
            int first = q.front().first; // index
            int second = q.front().second; // 중요도

            if(pq.top() > second){ // 중요도 낮은 경우
                q.push(q.front());
                q.pop();
            } else { 
                q.pop();
                pq.pop();
                cnt++; // 순서 세기
                
                if(first == M){
                    printf("%d\n", cnt);
                    break;
                }
            }
        }
    }

    return 0;
}