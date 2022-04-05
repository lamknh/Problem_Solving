#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int A[100001] = {0};

void search(int n, int key){ //이진탐색(Binary Search) - 중위순회
    int start = 0;
    int end = n-1;
    int mid;
 
    while(end - start >= 0){
        mid = (start + end)/2; // 중앙값
 
        if(A[mid] == key){ //key 값 = 중앙값
            printf("1\n");
            return ;
 
        }else if(A[mid] > key) { //key 값 < 중앙값
            end = mid - 1;
 
        }else{ //key 값 > 중앙값
            start = mid + 1;
        }
    }
 
    printf("0\n");
    return ;
}

int main(int argc, char **argv){
    int x;
    scanf("%d",&N);

    for(int i=0; i<N; i++){
        scanf("%d",&A[i]);
    }

    sort(A, A + N); // 정렬

    scanf("%d",&M);
    for(int i=0; i<M; i++){
        scanf("%d", &x);
        search(N, x);
    }

    return 0;
}