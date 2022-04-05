#include <iostream>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	int i = 1;
	while (N > i) { // i 번째 대각선에 있다.
		N -= i;
		i++;
	}

	if (i % 2 != 0){
        cout << i + 1 - N << '/' << N << endl;
    } else {
        cout << N << '/' << i + 1 - N << endl;
    }
	
    return 0;
}