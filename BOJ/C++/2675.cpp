#include <iostream>

using namespace std;

int main(void){
    int n, num;
    string abc;
    
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> num >> abc;

        for(int j = 0; j < abc.length(); j++){
            for(int k = 0; k < num; k++){
                cout << abc[j];
            }
        }
        cout << endl;
    }

    return 0;
}