#include <iostream>
#include <utility> // pair
#include <deque>
using namespace std;

int board[101][101] = {0}; //보드 0 : 빈칸, 1 : 사과, 2 : 뱀
char timeBoard[10001] = {0}; // 시간 저장 배열
int N, K, L;
int X; char C;

int sec = 0; // 0초
deque<pair<int, int> > snake; // 꼬리 머리 둘 다 줄고 늘 수 있음
int d = 0; // 현재 뱀이 바라보고 있는 방향, 처음엔 오른쪽

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

int nx, ny;

int main(int argc, char **argv){
    int x, y;

    scanf("%d %d",&N,&K); // 보드 크기, 사과 개수
    
    for(int i=0; i<K; i++){ // 사과의 위치
        scanf("%d %d", &x, &y);
        board[x][y] = 1; // 사과 있으면 1
    }

    snake.push_back(make_pair(1, 1)); // 뱀 (1,1)
    board[1][1] = 2; // 뱀 위치 표시

    scanf("%d", &L); //뱀의 방향 전환 정보
    for(int i = 0; i < L; i++){
        scanf("%d %c", &X, &C);
        timeBoard[X] = C;
    }

    while(1){
        if(timeBoard[sec] == 'L'){ // 왼쪽으로 90도 회전
            d = (d + 1) % 4;
        } else if(timeBoard[sec] == 'D'){ // 오른쪽으로 90도 회전
            d = (d + 3) % 4;
        }

        // <1번 조건> : 몸 길이를 늘려 머리를 다음 칸에 위치시킨다.
        nx = snake.front().first + dx[d];
        ny = snake.front().second + dy[d];
        //printf("%d d : %d nx : %d ny : %d\n", sec+1, d, nx, ny);

        // 벽에 부딪히거나 몸통에 닿을 경우 - 종료 조건
        if(nx < 1 || ny < 1 || nx > N || ny > N || board[nx][ny] == 2){
            sec++;
            break;
        }

        snake.push_front(make_pair(nx, ny)); // 머리 길어짐

        // <2번 조건> : 이동한 칸에 사과가 있다면 사과가 없어지고 꼬리는 움직이지 않는다.
        if(board[nx][ny] == 1){ // 사과가 있는 경우
            board[nx][ny] = 2; // 머리 - 뱀이 위치
        } else {
            // <3번 조건> : 사과가 없다면 몸길이를 줄여서 꼬리가 위치한 칸 비워줌.
            board[nx][ny] = 2; // 머리 - 뱀이 위치
            board[snake.back().first][snake.back().second] = 0; // 빈칸
            snake.pop_back(); // 꼬리 줄이기
        }

        // for(int i=1; i<=N; i++){
        //     for(int j=1; j<=N; j++){
        //         printf("%d ", board[i][j]);
        //     }
        //     printf("\n");
        // }

        sec++; // 1초 흐름
    }

    printf("%d", sec);

    return 0;
}