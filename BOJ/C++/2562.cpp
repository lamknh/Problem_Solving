#include <iostream>

using namespace std;

int main()
{
	int num[9], max = 0, index = 0;
	for (int i = 0; i < 9; i++) {
		cin >> num[i];
	}

	for (int j = 0; j < 9; j++) {
		if (num[j] > max) {
			index = j;
			max = num[j];
		}
	}

	cout << max << endl;
	cout << index + 1;

	return 0;
}