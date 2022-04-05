#include <iostream>

using namespace std;

int main(void) {
	int n, a = 1;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (n - a); j++) {
			cout << " ";
		}
		for (int j = 0; j < a; j++) {
			cout << "*";
		}
		a++;
		cout << endl;
	}
	return 0;
}