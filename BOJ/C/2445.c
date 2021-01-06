#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, a = 1;
	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++) {
		for (int p = 0; p < a; p++) {
			printf("*");
		}
		for (int q = 0; q < (2 * n) - (2 * a); q++) {
			printf(" ");
		}
		for (int p = 0; p < a; p++) {
			printf("*");
		}
		a++;
		printf("\n");
	}

	for (int i = 0; i < n; i++) {
		for (int p = 0; p < a; p++) {
			printf("*");
		}
		for (int q = 0; q < (2 * n) - (2 * a); q++) {
			printf(" ");
		}
		for (int p = 0; p < a; p++) {
			printf("*");
		}
		a--;
		printf("\n");
	}
	return 0;
}