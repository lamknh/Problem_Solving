#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int N = nums.size() / 2;
    printf("%d", N);

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end()); // 중복 없애기

    if(N <= nums.size()){
        answer = N;
    } else {
        answer = nums.size();
    }

    return answer;
}