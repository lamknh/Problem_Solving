#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N;
vector<int> v;
stack<pair<int, int> >s;

int main(int argc, char **argv){
    scanf("%d", &N);

    int x;
    for(int i=0; i<N; i++){
        scanf("%d", &x);
        v.push_back(x);
    }

    for(int i=0; i<N; i++){ // O(N)
        while(!s.empty() && v[i] > s.top().first){
            s.pop();
        }
        if(!s.empty()){
            printf("%d ", s.top().second);
        } else {
            printf("0 ");
        }
       
        s.push(make_pair(v[i], i+1)); // pair 만들어줌
    }

    return 0;
}