#include <iostream>
#include <string> // stoi
#include <deque>
using namespace std;

int T;
string p;
int n;
int main(int argc, char **argv){ // 덱
    scanf("%d",&T);

    for(int i=0; i<T; i++){
        string str;
        deque<int> dq;
        bool flag = true; // true면 정방향, false면 역방향
        bool error = false; // 에러 체크

        cin >> p; // 함수 입력받기
        scanf("%d",&n);
        cin >> str; // 정수 배열 입력받기

        string num = "";
        for(int j=0; j<str.length(); j++){
            if(isdigit(str[j])){ // 정수인지 판별
                num += str[j];
            } else {
                if(!num.empty()){ // 숫자가 존재할 때
                    dq.push_back(stoi(num)); // 숫자 int로 변경하여 dq에 넣기
                    num = ""; // 숫자 초기화
                }
            }
        }

        for(int j=0; j<p.length(); j++){
            if(p[j] == 'R'){
                flag = !flag; // 방향 바꾸기
            } else if(p[j] == 'D'){
                if(dq.size() > 0){
                    if(flag){ // 정방향
                        dq.pop_front();
                    } else { // 역방향
                        dq.pop_back();
                    }
                } else {
                    error = true;
                    break;
                }
            }
        }

        int dqsize = dq.size(); // dq size pop 하면 계속 변하기 때문에 변수에 저장

        if(error){
            printf("error\n");
        } else if(!error && dqsize == 0){
            printf("[]\n"); // 비어있는 경우에는 [] 출력
        } else {
            printf("[");
            if(flag){ // 정방향인 경우
                for(int j=0; j<dqsize; j++){
                    if(j == dqsize - 1){
                        printf("%d", dq.front());
                    } else {
                        printf("%d,", dq.front());
                    }
                    dq.pop_front();
                }
                
            } else { // 역방향인 경우
                for(int j=0; j<dqsize; j++){
                    if(j == dqsize - 1){
                        printf("%d", dq.back());
                    } else {
                        printf("%d,", dq.back());
                    }
                    dq.pop_back();
                }
            }
            printf("]\n");
        }
        
    }

    return 0;
}