#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int N, x, y, cnt = 1;
vector<pair<int, int> > arr;
pair<int, int> tmp;

int main(int argc, char **argv){
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        cin >> tmp.first >> tmp.second;
        arr.push_back(tmp);
    }

    // 굳이 sort할 필요 없음. 그냥 브루트포스로 찾으면 됨.
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i].first < arr[j].first && arr[i].second < arr[j].second){ 
                cnt++; // 나보다 덩치 큰 애의 개수 세기
            }
        }
        printf("%d ", cnt);
        cnt = 1;
    }

    return 0;
}