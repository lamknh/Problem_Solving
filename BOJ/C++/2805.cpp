#include <iostream>
#include <vector>
using namespace std;

long long N, M;
vector<long long> v;
int main(int argc, char **argv){
    scanf("%lld %lld",&N,&M);

    long long x, maxN = 0;
    for(int i=0; i<N; i++){
        scanf("%lld",&x);
        v.push_back(x);
        if(maxN < x){
            maxN = x;
        }
    }

    long long left = 1, right = maxN, mid; // 이진탐색
    long long result = 0;
    while(left <= right){
        mid = (left + right) / 2;
        long long tmp = 0;
        for(int i=0; i<v.size(); i++){
            if(v[i] >= mid){
                tmp += v[i] - mid;
            }
        }

        if(tmp >= M){
            left = mid + 1;
            result = mid;
        } else {
            right = mid - 1;
        }
    }
    printf("%lld", result);

    return 0;
}