#include <iostream>

using namespace std;

int main(void){
    int num[10];
    bool asc = true;
    bool des = true;

    for(int i=0; i<8; i++){
        cin >> num[i];
    }

    for(int j = 1; j < 9; j++){
        if(num[j-1] != j){
            asc = false;
            break;
        }
    }

    for(int j = 8; j > 0; j--){
        if(num[8-j] != j){
            des = false;
            break;
        }
    }
    
    if(asc){
        cout <<  "ascending";
    } else if(des){
        cout << "descending";
    } else {
        cout << "mixed";
    }

    return 0;
}