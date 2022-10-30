#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int tmp = n;
    int ONE = 0;
    while(tmp > 1){
        if(tmp % 2 == 1){
            ONE++;
        }
        tmp /= 2;
    }
    
    int num = n;
    while(1){
        num++;
        int tmp = num;
        int one = 0;
        while(tmp > 1){
            if(tmp % 2 == 1){
                one++;
            }
            tmp /= 2;
        }
        
        if(one == ONE){
            answer = num;
            break;
        }
    }
    return answer;
}