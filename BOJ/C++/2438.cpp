#include <iostream>

using namespace std;

int main(void) {
	int n, a = 1;
	cin >> n;

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < a; i++) {
			cout << "*";
		}
		cout << endl;
		a++;
	}

	return 0;
}