#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) { // 함수를 만들어서 함수 기준으로 정렬할 수 있다.
    if(a.length() < b.length()){
        return true; // a 길이가 작으면 그대로
    } else if(a.length() == b.length()){
        return a < b; // 길이 같으면 사전순
    } else{
        return false; // b가 a보다 작으면 반대로해라.
    }
}

int main(int argc, char **argv){
    int N;
    scanf("%d",&N);
    vector<string> v(N); // [] 말고 ()

    for(int i=0; i<N; i++){
        cin >> v[i];
    }

    sort(v.begin(),v.end(), compare); // 세번째 인자로 사용자가 정의한 함수 기준으로 정렬 가능
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i=0; i<v.size(); i++){
        cout << v[i] << endl;
    }

    return 0;
}