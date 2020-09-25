#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, cal, temp, one, ten, num = 1;
	scanf("%d", &n);

	if (n < 10) {	n *= 10;	}

	ten = n % 10;
	temp = (n / 10) + ten;
	one = temp % 10;
	cal = ten * 10 + one;

	while (n != cal) {
		ten = cal % 10;
		temp = (cal / 10) + ten;
		one = temp % 10;
		cal = ten * 10 + one;
		num += 1;
	}

	printf("%d", num);

	return 0;
}