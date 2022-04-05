#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	int a = n;

	for (int i = 0; i < n; i++) {
		for (int j = a; j < n; j++) {
			printf(" ");
		}
		for (int k = 0; k < a; k++) {
			printf("*");
		}
		printf("\n");
		a--;
	}
	return 0;
}