#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(void) {
	char str[1000000];
	int word = 0, i = 0;

	cin.getline(str, 1000000); // gets 사용불가

	while (str[i] != 0) {
		if (str[i] == ' ') {
			word++;
		}
		i++;
	}//while문 조건 숫자로 하면 계속 i 증가하고, str 0(존재할 때 까지 카운팅)

	if (str[0] == ' ') {
		word--;
	}

	if (str[i - 1] == ' ') {
		word--;
	}

	printf("%d", word+1);
	return 0;
}