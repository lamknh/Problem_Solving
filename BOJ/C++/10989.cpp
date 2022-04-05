#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char **argv){
    int N, x;
    scanf("%d",&N);
    int cnt[10001] = {0}; // 동적할당 해도 메모리 초과

    for(int i=0; i<N; i++){
        scanf("%d",&x);  // 입력받은 수 다 배열에 저장하면 메모리 초과 -> 숫자를 센 후에 출력만 해주자
        cnt[x]++;
    }

    for(int i=1; i<=10000; i++){ // <= 빼먹지 말기
        for(int j=0; j<cnt[i]; j++){
            printf("%d\n", i);
        }
    }

    return 0;
}
