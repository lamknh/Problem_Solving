#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	int a = n;
	for (int i = 0; i < n; i++) {
		for (int j = a; j > 0; j--) {
			cout << "*";
		}
		cout << endl;
		a--;
	}

	return 0;
}