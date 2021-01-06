#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, a = 1, m;
	scanf("%d", &n);
	m = n;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			printf(" ");
		}
		for (int k = 0; k < a; k++) {
			printf("*");
		}
		m--;
		a = a + 2;
		printf("\n");
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			printf(" ");
		}
		for (int k = 0; k < a; k++) {
			printf("*");
		}
		m++;
		a = a - 2;
		printf("\n");
	}

	return 0;
}