#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int num;
	int value = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &num);
		value += (num * num);
	}

	printf("%d", (value % 10));
	return 0;
}