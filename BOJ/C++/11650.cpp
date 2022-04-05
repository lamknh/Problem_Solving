#include <iostream>
#include <vector>
#include <utility> // pair
#include <algorithm>
using namespace std;

int main(int argc, char **argv){
    int N;
    scanf("%d",&N);
    vector<pair<long, long> > arr;
    pair<long, long> tmp; // 값 입력받을 pair

    for(int i=0; i<N; i++){
        cin >> tmp.first >> tmp.second; // 좌표 입력받기
        arr.push_back(tmp); // 입력받은 pair 벡터에 넣기
    }

    sort(arr.begin(), arr.end()); // 페어의 경우 first가 같으면 second로 비교하게끔 이미 sort함수에서 구현
   
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i].first << " " << arr[i].second << "\n"; // endl 시간초과
    }

    return 0;
}