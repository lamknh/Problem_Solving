#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<long, long> a, pair<long, long> b){
    if(a.second < b.second){
        return true;
    } else if (a.second == b.second){
        return a < b;
    } else {
        return false;
    }
    // if (a.second == b.second) {
    //     return a.first < b.first;
    // }
    // else {
    //     return a.second < b.second;
    // }
}

int main(int argc, char **argv){
    int N;
    scanf("%d",&N);
    vector<pair<long, long> > arr; // [N]으로 개수 제한 x
    pair<long, long> tmp;

    for(int i=0; i<N; i++){
        cin >> tmp.first >> tmp.second;
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end(), compare);

    for(int i=0; i<arr.size(); i++){
        cout << arr[i].first << " " << arr[i].second << "\n";
    }

    return 0;
}