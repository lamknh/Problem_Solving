#include <iostream>

using namespace std;

int main(void){
    int n, score = 0, num = 0;
    string ox;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> ox;
        for(int j = 0; j < ox.length(); j++){
            if(ox[j] == 'O'){
                score++;
                num += score;
            } else {
                score = 0;
            }
        }
        cout << num << endl;
        num = 0;
        score = 0;
    }

    return 0;
}