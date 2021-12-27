#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);

	int n1 = b % 10;
	int n2 = (b / 10) % 10;
	int n3 = (b / 100) % 10;

	printf("%d\n", a * n1);
	printf("%d\n", a * n2);
	printf("%d\n", a * n3);
	printf("%d", a * b);

	return 0;
}