#include <iostream>
#include <stack> // stl 스택

using namespace std;

int main(void){
    int N, num;
    stack<int> stack; // 스택 선언
    string str;

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        cin >> str;

        if(str == "push"){
            scanf("%d", &num);
            stack.push(num);
        } else if(str == "pop"){
            if(stack.empty()){
                printf("-1\n");
            } else {
                cout << stack.top() << endl;
                stack.pop();
            }
        } else if(str == "size"){
            cout << stack.size() << endl;
        } else if(str == "empty"){
            if(stack.empty()){
                printf("1\n");
            } else {
                printf("0\n");
            }
        } else if(str == "top"){
            if(stack.empty()){
                printf("-1\n");
            } else {
                cout << stack.top() << endl;
            }
        }
    }

    return 0;
}