#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(void) {
	char str[1000000];
	int word = 0, i = 0;

	cin.getline(str, 1000000); // gets ���Ұ�

	while (str[i] != 0) {
		if (str[i] == ' ') {
			word++;
		}
		i++;
	}//while�� ���� ���ڷ� �ϸ� ��� i �����ϰ�, str 0(������ �� ���� ī����)

	if (str[0] == ' ') {
		word--;
	}

	if (str[i - 1] == ' ') {
		word--;
	}

	printf("%d", word+1);
	return 0;
}