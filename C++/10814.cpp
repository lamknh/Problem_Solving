#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b){
    return a.first < b.first; // 나이만 비교한다.
}

int main(int argc, char **argv){ // 시간초과, 원래 순서 손상 안시키게 정렬하는것 stable sort
    int N;
    string str;
    scanf("%d",&N);
    vector<pair<int, string> > arr;
    pair<int, string> tmp;

    for(int i=0; i<N; i++){
        cin >> tmp.first >> tmp.second;
        arr.push_back(tmp);
    }

    stable_sort(arr.begin(), arr.end(), compare); // stable_sort 사용시 컨테이너 앞의 원소 순서대로 정렬

    for(int i=0; i<arr.size(); i++){
        cout << arr[i].first << " " << arr[i].second << "\n";
    }

    return 0;
}