#include <iostream>

using namespace std; //std �̷��� ������Ű��

int calculate(int a, int b, int c) {
	int money;

	if (a == b && b == c) {
		money = 10000 + (b * 1000);
	}
	else if (a != b && b != c && a != c) {
		if (a > b&& a > c) {
			money = a * 100;
		}
		else if (b > a&& b > c) {
			money = b * 100;
		}
		else {
			money = c * 100;
		}
	}
	else {
		if (a == b) {
			money = 1000 + a * 100;
		}
		else if (b == c) {
			money = 1000 + b * 100;
		}
		else {
			money = 1000 + a * 100;
		}
	}

	return money;
}
int main(void) {
	int a, b, c;
	cin >> a >> b >> c;

	printf("%d", calculate(a, b, c)); //C�� printf, ����� �� %d �� ��½�Ű�� �׳� �ȵ�
	return 0;
}