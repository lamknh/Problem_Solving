#include <iostream>
#include <vector>
using namespace std;

int K, N;
vector<int> line;

int main(int argc, char **argv){
    int x, maxN = 0;

    scanf("%d %d",&K,&N);

    for(int i=0; i<K; i++){
        scanf("%d", &x);
        line.push_back(x);
        maxN = max(maxN, x); // 최대값 저장
    }

    long long left = 1, mid, right = maxN;
    long long result = 0, tmp; // 초기화해주기
    while(left <= right){
        mid = (left + right) / 2;
        tmp = 0;
        for(int i=0; i<line.size(); i++){
            tmp += line[i] / mid;
        }

        if(tmp >= N){
            left = mid + 1;
            result = max(result, mid); // 값 갱신 - 랜선의 최대길이
        } else {
            right = mid - 1;
        }
    }

    printf("%lld", result);

    return 0;
}