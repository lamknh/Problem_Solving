#include <iostream>

using namespace std;

int main(void) {
	int a, b;
	cin >> a;
	cin >> b;

	int n1 = b % 10;
	int n2 = (b / 10) % 10;
	int n3 = (b / 100) % 10;

	cout << a * n1 << endl;
	cout << a * n2 << endl;
	cout << a * n3 << endl;
	cout << a * b << endl;;

	return 0;
}