#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    for(int i = 0; i < sizes.size(); i++){
        if(sizes[i][0] < sizes[i][1]){
            // 더 큰 것을 앞에 두기
            int tmp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = tmp;
        }
    }
    
    int maxA = 0, maxB = 0;
    
    for(int i = 0; i < sizes.size(); i++){
        maxA = max(maxA, sizes[i][0]);
        maxB = max(maxB, sizes[i][1]);
    }
    
    answer = maxA * maxB;
    
    return answer;
}