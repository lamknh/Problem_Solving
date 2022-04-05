#include <iostream>
#include <deque>
using namespace std;

int main(int argc, char **argv){
    int N;
    deque<int> deque;
    string str;
    scanf("%d",&N);

    for(int i=0; i<N; i++){
        cin >> str;
        if(str == "push_front"){
            int X;
            scanf("%d",&X);
            deque.push_front(X);
        } else if(str == "push_back"){
            int X;
            scanf("%d",&X);
            deque.push_back(X);
        } else if(str == "pop_front"){
            if(deque.empty()){
                printf("-1\n");
            } else {
                cout << deque.front() << endl;
                deque.pop_front();
            }
        } else if(str == "pop_back"){
            if(deque.empty()){
                printf("-1\n");
            } else {
                cout << deque.back() << endl;
                deque.pop_back();
            }
        } else if(str == "size"){
            cout << deque.size() << endl;
        } else if(str == "empty"){
            if(deque.empty()){
                printf("1\n");
            } else {
                printf("0\n");
            }
        } else if(str == "front"){
            if(deque.empty()){
                printf("-1\n");
            } else {
                cout << deque.front() << endl;
            }
        } else if(str == "back"){
            if(deque.empty()){
                printf("-1\n");
            } else {
                cout << deque.back() << endl;
            }
        }
    }


    return 0;
}