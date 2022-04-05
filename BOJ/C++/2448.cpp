#include <iostream>
#define MAX 2*(3072)

char stars[MAX/2][MAX];

void star(int n, int x, int y){ // x : 가로, y : 세로
    if(n == 3){ // 높이 3
        stars[y][x] = '*'; // (0,2)

        stars[y+1][x-1] = '*'; // (1,1)
        stars[y+1][x+1] = '*'; // (1,3)

        stars[y+2][x-2] = '*'; // (2,0)
        stars[y+2][x-1] = '*'; // (2,1)
        stars[y+2][x] = '*'; // (2,2)
        stars[y+2][x+1] = '*'; // (2,3)
        stars[y+2][x+2] = '*'; // (2,4)

        return;
    }
    // 재귀
    star(n/2, x, y); // 삼각형 높이 반씩 줄어듦
    star(n/2, x - n/2, y + n/2); // 왼쪽 삼각형
    star(n/2, x + n/2, y + n/2); // 오른쪽 삼각형
}

int main(int argc, char **argv){
    int N;
    scanf("%d",&N);

    // 그냥 찍기 X 2차원 배열 이용

    for(int i=0; i<N; i++){ // 초기화 - 세로 길이
        for(int j=0; j<N * 2; j++){ // 가로 길이
            if(j == N * 2 - 1){
                stars[i][j] = '\0'; // 문자열 끝내기 -> "" 대신 ''
            } else {
                stars[i][j] = ' '; // 공백으로 초기화
            }
        }
    }

    star(N, N-1, 0); // 별 찍기 - 줄 수, 삼각형 시작 좌표 넘기기 (위에서부터 0이다)

    for(int i=0; i<N; i++){ 
        for(int j=0; j< N * 2 - 1; j++){
            printf("%c", stars[i][j]);
        }
        printf("\n");
    }

    return 0;
}