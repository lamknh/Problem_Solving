#include <iostream>
#include <vector>
#include <algorithm> // std::unique <- 벡터의 중복 요소 삭제
using namespace std;

int main(int argc, char **argv){
    int N;
    scanf("%d",&N);
    vector<int> v(N); // N개의 벡터 생성 -> segfault

    for(int i=0; i<N; i++){
        scanf("%d",&v[i]);
    }
    sort(v.begin(), v.end()); // 정렬 먼저 해줘야함.
    v.erase(unique(v.begin(), v.end()), v.end());
    // 중복 원소를 vector의 제일 뒷부분 쓰레기 값으로 보냄 -> 이 뒷부분 erase로 삭제
    // unique 함수는 앞과 뒤 원소를 비교하기 때문에 무조건 먼저 정렬을 해줘야한다.

    for(int i = 0; i < v.size(); i++){
        printf("%d ",v[i]);
    }

    return 0;
}