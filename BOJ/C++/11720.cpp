#include <iostream>

using namespace std;

//Bronze 2

int main() {
	int n, sum = 0;
	char num;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num; //�ڸ��� ������� ������ ���� char������ ������ �ϳ��� ���� �� ����
		sum += num - '0'; // \0 ���ֱ� �ƽ�Ű�ڵ�� �Էµ� char -> int
	}

	cout << sum;

	return 0;
}