#include <iostream>
#include <queue> // bfs
using namespace std;

int N, M, cnt = 0;
int map[1001][1001] = {0}; // 그래프
bool visited[1001] = {false}; // 방문 체크
queue<int> q; // 큐

void BFS(int n){
    if(!visited[n]){
        visited[n] = true; // 방문체크
    }
    q.push(n); // 큐에 노드 넣기

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i = 1; i <= N; i++){
            if(map[node][i] == 1 && !visited[i]){ // 노드에 연결된 노드가 있고 방문되지 않았다면
                visited[i] = true; // 방문체크
                q.push(i); // 연결 노드 큐에 넣기
            }
        }
    }
}

int main(int argc, char **argv){
    scanf("%d %d",&N,&M);

    int a, b;
    for(int i=1; i<=M; i++){
        scanf("%d %d",&a,&b);
        map[a][b] = 1;
        map[b][a] = 1; // 간선 연결, 방향이 없으니까 a -> b, b -> a
    }

    for(int i=1; i<=N; i++){
        if(!visited[i]){
            BFS(i);
            cnt++; // 방문하지 않았다면 카운터 세기
        }
    }

    printf("%d", cnt);

    return 0;
}