#include <string>
#include <vector>
#include <algorithm> //sort

using namespace std;

int onePick[5] = {1, 2, 3, 4, 5};
int twoPick[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int threePick[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int one = 0;
    int two = 0;
    int three = 0;
    
    for(int i = 0; i < answers.size(); i++){
        if(onePick[i % 5] == answers[i]){
            one++;
        }
        if(twoPick[i % 8] == answers[i]){
            two++;
        }
        if(threePick[i % 10] == answers[i]){
            three++;
        }
    }
    
    int mmax = max(one, max(two, three));
    if(mmax == one){
        answer.push_back(1); // vector는 push_back
    }
    if(mmax == two){
        answer.push_back(2);
    }
    if(mmax == three){
        answer.push_back(3);
    }
    
    sort(answer.begin(), answer.end()); // 오름차순
    
    return answer;
}