#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char **argv){
    stack<int> s;
    int K, x, sum = 0;
    scanf("%d", &K);

    for(int i=0; i<K; i++){
        scanf("%d", &x);
        if(x != 0){
            s.push(x);
        } else {
            s.pop();
        }
    }

    while(!s.empty()){
        sum += s.top();
        s.pop();
    }

    printf("%d", sum);

    return 0;
}