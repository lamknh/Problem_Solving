#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	int a = 0;
	int b = n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (b - 1); j++) {
			printf(" ");
		}
		for (int k = 0; k < (a * 2 + 1); k++) {
			printf("*");
		}
		printf("\n");
		a++;
		b--;
	}
	return 0;
}