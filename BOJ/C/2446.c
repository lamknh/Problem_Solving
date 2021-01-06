#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	int a = 2 * n - 1;

	for (int i = 0; i < n - 1; i++) {
		for (int k = 0; k < i; k++) {
			printf(" ");
		}
		for (int j = 0; j < a; j++) {
			printf("*");
		}
		a = a - 2;
		printf("\n");
	}

	for (int i = n; i > 0; i--) {
		for (int k = 0; k < i - 1; k++) {
			printf(" ");
		}
		for (int j = 0; j < a; j++) {
			printf("*");
		}
		a = a + 2;
		printf("\n");
	}

	return 0;
}