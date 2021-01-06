#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, a;
	scanf("%d", &n);
	a = 2 * n - 1;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < i; k++) {
			printf(" ");
		}
		for (int j = 0; j < a; j++) {
			printf("*");
		}
		a = a - 2;
		printf("\n");
	}
	return 0;
}