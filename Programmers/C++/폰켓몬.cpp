#include <vector>
#include <algorithm> // sort
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int N = nums.size();
    
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end()); // erase
    
    if(nums.size() >= N/2){
        answer = N/2;
    } else {
        answer = nums.size();
    }
    
    return answer;
}