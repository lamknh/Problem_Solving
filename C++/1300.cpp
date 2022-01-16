#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, k;
int main(int argc, char **argv){
    scanf("%d %d",&N,&k);
    int start = 1, mid, end = k, result = 0;
    long long sum = 0;

    while(start <= end){
        mid = (start + end) / 2;
        sum = 0;
        for(int i = 1; i <= N; i++){
            sum += min(mid/i, N);
        }
        if(sum < k){
            start = mid + 1;
        } else {
            result = mid;
            end = mid - 1;
        }
    }
    
    printf("%d", result);

    return 0;
}