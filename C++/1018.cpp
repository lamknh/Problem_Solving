#include <iostream>
#include <algorithm>
using namespace std;

string board[50]; // 50보다 작거나 같다. string으로 행 한 번에 받아오기
string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
}; // 체스판은 두 개의 형태로 고정되어있다. 고정된 것 먼저 선언

//(0, 0)이 W인 체스보드 기준 바뀔 칸 수
int WBChange(int y, int x){
    int cnt = 0;
    for (int i = y; i < y + 8; i++){ // 모든 정점에서 8 * 8 보드판을 떼어오자
        for (int j = x; j < x + 8; j++){
            if (board[i][j] != WB[i - y][j - x]){ // string이라 이차원 배열 가능
                cnt++;
            }
        }
    }
    return cnt;
}

//(0, 0)이 B인 체스보드 기준 바뀔 칸 수
int BWChange(int y, int x){
    int cnt = 0;
    for (int i = y; i < y + 8; i++){ 
        for (int j = x; j < x + 8; j++){
            if (board[i][j] != BW[i - y][j - x]){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(int argc, char **argv){
    int N, M;
    int result = 9999999;
    scanf("%d %d",&N,&M);

    // 브루트포스 알고리즘 -> 모든 경우를 다 구한 다음에 제일 적은 것 출력

    for (int i = 0; i < N; i++){
        cin >> board[i]; // string이라 열 통째로 받아옴, 행만큼만 반복해서 받아오면 됨.
    }

    for (int i = 0; i + 7 < N; i++){ // 모든 좌표에서 8 * 8 찾음
        for (int j = 0; j + 7 < M; j++){
            result = min(result, min(WBChange(i, j), BWChange(i, j))); // 최소값 result 할당
        }
    }

    cout << result << endl;

    return 0;
}