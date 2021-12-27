#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, a = 1;
	scanf("%d", &n);

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < a; i++) {
			printf("*");
		}
		printf("\n");
		a++;
	}

	return 0;
}