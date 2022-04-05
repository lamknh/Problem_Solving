#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, a = 1;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (n - a); j++) {
			printf(" ");
		}
		for (int j = 0; j < a; j++) {
			printf("*");
		}
		a++;
		printf("\n");
	}
	return 0;
}