#include <iostream>

using namespace std;

int main(void){
    int n, m, min, max;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> m;
        if(i == 0){
            min = m;
            max = m;
        }
        
        if(m < min){
            min = m;
        } else if(m > max){
            max = m;
        }
    }

    cout << min << " " << max << endl;

    return 0;
}