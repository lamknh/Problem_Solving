#include <iostream>
#include <stack>
using namespace std;

string str;
char c;
int main(int argc, char **argv){
    do{
        getline(cin, str); // 한 줄 입력받기
        stack<int> s;
        bool flag = true;
        for(int i=0; i<str.size(); i++){
            c = str[i];
            if(c == '('){
                s.push(1);
            } else if(c == ')'){
                if(!s.empty() && s.top() == 1){
                    s.pop();
                } else {
                    flag = false;
                    break;
                }
            } else if(c == '['){
                s.push(2);
            } else if(c == ']'){
                if(!s.empty() && s.top() == 2){
                    s.pop();
                } else {
                    flag = false;
                    break;
                }
            }
        }

        if(!s.empty()){
            flag = false;
        }

        if(str != "."){
            if(flag){
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    } while(str != ".");

    return 0;
}