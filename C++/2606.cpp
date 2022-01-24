#include <iostream>
#include <queue> // bfs
using namespace std;

int V, E; // vertex, edge

int map[101][101] = {0}; // 간선 저장
bool visited[101] = {false}; // 방문 여부
queue<int> q;

int cnt = 0; // 바이러스에 걸린 컴퓨터 수

void BFS(int n){
    if(!visited[n]){
        visited[n] = true; // 방문 체크
    }
    q.push(n); // 큐에 첫번째 노드 넣기

    while(!q.empty()){
        int vertex = q.front(); q.pop();

        for(int i=1; i<=V; i++){
            if(map[vertex][i] == 1 && !visited[i]){ // 간선 연결되어있고 방문되지 않았을 경우
                visited[i] = true; // 연결된 노드 방문
                q.push(i); // 노드 큐에 넣기
                cnt++; // 감염된 컴퓨터 개수 세기
            }
        }
    }
}

int main(int argc, char **argv){
    scanf("%d %d",&V,&E);

    int a, b;
    for(int i=1; i<=E; i++){
        scanf("%d %d",&a,&b);
        map[a][b] = 1;
        map[b][a] = 1; // 간선 연결, 방향 없음
    }

    BFS(1); // 1번 컴퓨터 감염 확인

    printf("%d", cnt);

    return 0;
}