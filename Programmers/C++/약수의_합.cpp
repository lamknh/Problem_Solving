#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int div = 1; // 2부터 나누기 시작
    
    while(div <= n){
        if(n % div == 0){
            answer += div;
        }
        div++;
    }
    
    return answer;
}