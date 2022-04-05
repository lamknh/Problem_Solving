#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int n, one = 0;
    string tmp;
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        cin >> tmp;

        if(tmp == "1"){
            one++;
        } else {
            one--;
        }
    }

    if(one > 0){
        printf("Junhee is cute!");
    } else {
        printf("Junhee is not cute!");
    }


    return 0;
}