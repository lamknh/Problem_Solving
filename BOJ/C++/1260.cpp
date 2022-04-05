#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001
 
int N, M, V; //정점개수, 간선개수, 시작정점
int map[MAX][MAX]; //인접 행렬 그래프
bool visited[MAX]; //정점 방문 여부
queue<int> q;
 
void reset() {
    for (int i = 1; i <= N; i++) {
        visited[i] = 0; // 방문 처리 초기화
    }
}
 
void DFS(int v) { // 재귀 사용
    visited[v] = true; // 방문 처리
    printf("%d ", v);
    
    for (int i = 1; i <= N; i++) {
        if (map[v][i] == 1 && visited[i] == 0) { //현재 정점과 연결되어있고 방문되지 않았으면
            DFS(i);
        }
    }
}
 
void BFS(int v) { // 큐 사용
    q.push(v);
    visited[v] = true;
    printf("%d ", v);
 
    while (!q.empty()) {
        v = q.front();
        q.pop();
        
        for (int w = 1; w <= N; w++) {
            if (map[v][w] == 1 && visited[w] == 0) { //정점과 연결되어있고 방문되지 않았으면
                q.push(w);
                visited[w] = true;
                printf("%d ", w);
            }
        }
    }
}
 
int main() {
    scanf("%d %d %d", &N, &M, &V);
 
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        map[a][b] = 1;
        map[b][a] = 1; // 인접 행렬 그래프 - 간선 있으면 1
    }
 
    reset();
    DFS(V);
    
    printf("\n");
    
    reset();
    BFS(V);
 
    return 0;
}