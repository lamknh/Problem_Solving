#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a;
	scanf("%d", &a);

	for (int i = 0; i < a; i++) {
		int b, sum = 0, value, num = 0;
		scanf("%d", &b);
		int* arr = malloc(sizeof(int) * b);

		for (int j = 0; j < b; j++) {
			scanf("%d", &value);
			arr[j] = value;
			sum += value;
		}

		int avg = sum / b;

		for (int j = 0; j < b; j++) {
			if (arr[j] > avg) {
				num++;
			}
		}
		printf("%.3lf%%\n", (double)num / (double)b * 100);
		free(arr);
	}

	return 0;
}