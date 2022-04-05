#include <iostream>

using namespace std;

//Bronze 2

int main() {
	int n, sum = 0;
	char num;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num; //자릿수 나누기로 나누지 말고 char형으로 받으면 하나씩 받을 수 있음
		sum += num - '0'; // \0 빼주기 아스키코드로 입력됨 char -> int
	}

	cout << sum;

	return 0;
}