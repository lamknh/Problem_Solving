#include <string>
#include <vector>

using namespace std;

int solution(int inum) {
    long long num = (long long) inum;
    int answer = 0;
    
    while(num != 1){
        if(num % 2 == 0){
            num /= 2;
        } else {
            num = num * 3 + 1;
        }
        answer++;
        
        if(answer == 500 && num != 1){
            return -1;
        }
    }
    
    printf("%d %d", num, answer);
    
    return answer;
}
