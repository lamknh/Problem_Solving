#include <iostream>
#include <vector> // vector 사용
#include <algorithm>
using namespace std;

int main(int argc, char **argv){
    int N, M;
    int x;
    scanf("%d",&N);
    vector<int> v(N); // N 크기의 벡터 생성

    for(int i=0; i<N; i++){
        scanf("%d",&v[i]); // 상근이 값 입력받기
    }  
    sort(v.begin(), v.end()); // vector의 시작과 끝으로 정렬

    scanf("%d", &M);
    for(int i=0; i<M; i++){
        scanf("%d", &x);
        auto low = lower_bound(v.begin(), v.end(), x); // auto : 타입 추론, 매개변수에는 사용 불가
        auto up = upper_bound(v.begin(), v.end(), x);
        //upper_bound : binary search로 해당 숫자가 끝나는 위치 반환
        //lower_bound : binary search로 해당 숫자가 시작하는 위치 반환

        printf("%ld ", up - low);
    }
    
    return 0;
}