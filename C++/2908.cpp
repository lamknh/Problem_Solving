#include <iostream>

using namespace std;

int main(void){
    int n, m, n1, n2, n3, m1, m2, m3, newN, newM;

    cin >> n >> m;

    for(int i=0; i<3; i++){
        n1 = n / 100;
        n2 = (n - n1*100) / 10;
        n3 = (n - n1*100 - n2*10);
    }

    for(int i=0; i<3; i++){
        m1 = m / 100;
        m2 = (m - m1*100) / 10;
        m3 = (m - m1*100 - m2*10);
    }

    newN = n3 * 100 + n2 * 10 + n1;
    newM = m3 * 100 + m2 * 10 + m1;

    if(newN > newM){
        cout << newN;
    } else {
        cout << newM;
    }

    return 0;
}