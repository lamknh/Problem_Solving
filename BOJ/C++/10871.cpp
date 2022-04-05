#include <iostream>

using namespace std;

// Bronze 3

int main() {
	int n, num, a;
	cin >> n >> num;

	for (int i = 0; i < n; i++) {
		cin >> a;
		if(a < num){
			cout << a << " ";
		}
	}

	return 0;
}