#include <iostream>

using namespace std;

// Silver 5

int main() 
{
	int n, num[10], div = 10, temp = 0;

	fill_n(num, 10, -1); //cpp 0 아닌 수로 배열 초기화

	cin >> n;

	for (int i = 0; i < 10; i++) {
		num[i] = n % div;

		if (n == 0) {
			num[i] = -1;
			break;
		}

		n /= div;
	}

	for (int j = 0; j < 9; j++) {
		for (int k = 0; k < 9 - j; k++) {
			if (num[k] < num[k+1]) {
				temp = num[k];
				num[k] = num[k + 1];
				num[k + 1] = temp;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		if (num[i] > -1) {
			cout << num[i];
		}
	}

	return 0;
}