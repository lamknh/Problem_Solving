#include <iostream>

int main(int argc, char **argv){
    int T, n, idx = 0;
    scanf("%d",&T);

    for(int i=0; i<T; i++){
        int arr[100001] = {0}; // 배열 안써도 풀 수 있다.
        scanf("%d",&n);
        while(n != 1){ // n > 0 을 쓰는게 더 효율적
            if(n % 2 == 1){
                arr[idx]++; // 그냥 idx 출력해버리는게 더 효율적
            }
            n /= 2;
            idx++;
        }
        arr[idx] = 1; // 이거 없어도 됨

        for(int j=0; j<=idx; j++){ // 일을 두 번 하네...
            if(arr[j] > 0){
                printf("%d ", j);
            }
        }
        idx = 0;
    }

    return 0;
}