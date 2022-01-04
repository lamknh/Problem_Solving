#include <iostream>
#include <queue>

using namespace std;

int main(void){
    int N;
    string str;
    queue<int> queue;

    scanf("%d", &N);

    for(int i=0; i<N; i++){
        cin >> str;
        if(str == "push"){
            int n;
            scanf("%d", &n);
            queue.push(n);
        } else if(str == "pop"){
            if(queue.empty()){
                printf("-1\n");
            } else {
                cout << queue.front() << endl;
                queue.pop();
            }
        } else if(str == "size"){
            cout << queue.size() << endl;
        } else if(str == "empty"){
            if(queue.empty()){
                printf("1\n");
            } else {
                printf("0\n");
            }
        } else if(str == "front"){
            if(queue.empty()){
                printf("-1\n");
            } else {
                cout << queue.front() << endl;
            }
        } else if(str == "back"){
            if(queue.empty()){
                printf("-1\n");
            } else {
                cout << queue.back() << endl;
            }
        }
    }

    return 0;
}