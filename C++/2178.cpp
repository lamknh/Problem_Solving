#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[101][101] = {0}; // 미로 입력
bool visited[101][101] = {false}; // 정점 방문 여부
queue<int> x, y, cnt; // 큐 2개 x, y, 칸 수 계산 - 길 탐색할 때 마다 거리 계산

int dx[4] = { 0, 0, -1, 1 }; // 상하좌우 좌표
int dy[4] = { -1, 1, 0, 0 };

bool check(int y, int x){ // y좌표를 먼저 해주는게 좋다고 한다.
    if(y < 1 || y > N || x < 1 || x > M){
        return false; // 좌표 범위 초과하면 갈 수 없음
    } else if(map[y][x] == 0){
        return false; // 벽이 있으면 이동 불가
    } else if(visited[y][x]){
        return false; // 이미 방문 했으면 이동 x
    }
    return true;
}

int main(int argc, char **argv){
    scanf("%d %d",&N,&M);

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            scanf("%1d", &map[i][j]); // 숫자 1개씩 입력받기
        }
    }

    x.push(1); y.push(1); // 첫 좌표 큐에 집어넣기
    cnt.push(1); // 첫번째 칸
    
    while(!y.empty()){
        int yp = y.front(); y.pop(); // y 좌표 
        int xp = x.front(); x.pop(); // x 좌표 
        int cntp = cnt.front(); cnt.pop(); // 칸 수 세기

        if(visited[yp][xp]){
            continue; // 방문된 노드이면 패스
        } else {
            visited[yp][xp] = true; // 방문 체크
        }

        if(xp == M && yp == N){ // N * M 배열 N은 y, M은 x
            // 도착점 도달
            printf("%d", cntp);
            break;
        }

        // 상하좌우 방문 - else if 사용 x
        if(check(yp + dy[0], xp + dx[0])){ // y 먼저
            x.push(xp + dx[0]); 
            y.push(yp + dy[0]); 
            cnt.push((cntp + 1));
        }
        if(check(yp + dy[1], xp + dx[1])){
            x.push(xp + dx[1]); 
            y.push(yp + dy[1]); 
            cnt.push((cntp + 1));
        }
        if(check(yp + dy[2], xp + dx[2])){
            x.push(xp + dx[2]); 
            y.push(yp + dy[2]); 
            cnt.push((cntp + 1));
        }
        if(check(yp + dy[3], xp + dx[3])){
            x.push(xp + dx[3]); 
            y.push(yp + dy[3]); 
            cnt.push((cntp + 1));
        }
    }

    return 0;
}