#include <iostream>
#include <stack>
using namespace std;

bool parenthesis(string str){
    char c;
    stack<int> stack;
    bool check = true;

    for(int j=0; j<str.length(); j++){
        c = str[j]; // 한 문자씩 str 뽑아내는 법
        if(c == '('){
            stack.push(c);
        } else {
            if(stack.empty()){
                return false;
            } else {
                stack.pop();
            }
        }
    }

    if(!stack.empty()){
        return false;
    }
    return true;
}

int main(int argc, char **argv){ //스택 사용하기
    int n, cnt = 0;
    string str;

    scanf("%d",&n);
    for(int i=0; i<n; i++){
        cin >> str;
        
        if(parenthesis(str)){
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}