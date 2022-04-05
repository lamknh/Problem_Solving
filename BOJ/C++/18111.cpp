#include <iostream>
#include <vector>
using namespace std;

int N, M, B;
int house[500][500];
int t1 = 2, t2 = 1; // 블록제거 : 2초, 블록쌓기 : 1초
int t = 99999999, line = 99999999; // 시간, 최대 높이

int main(int argc, char **argv){ //브루트포스 알고리즘
    scanf("%d %d %d",&N,&M,&B); // 집터 크기와 블록 개수

    int max = 0, min = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> house[i][j]; // 집 입력 받기
            if(max < house[i][j]){
                max = house[i][j];
            } else if(min > house[i][j]){
                min = house[i][j];
            } // 높이 최소, 최대값 찾기
        }
    }

    for(int i=min; i<=max; i++){ // 해당 높이 사이
        int remove = 0; // 블록 바로 빼면 뒤의 블록을 먼저 제거하는 경우를 고려하지 못한다.
        int stack = 0;
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                if(house[j][k] > i){
                    remove += (house[j][k] - i); // 깎기
                } else if(house[j][k] < i){
                    stack += (i - house[j][k]); // 채우기
                }
            }
        }

        if(stack <= remove + B){ // 깎아낸 것이 채우는 것보다 많을 때
            int temp = remove * 2 + stack;
            if(t > temp){
                t = temp;
                line = i;
            } else if(t == temp){
                line = i; // i는 계속 증가하므로 갱신만 시켜주면 됨
            }
        }
    }   

    printf("%d %d", t, line); // 시간과 최대 높이 출력

    return 0;
}