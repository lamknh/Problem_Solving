#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, m, sumY = 0, sumM = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		for (int j = 0; j < (m / 30) + 1; j++) {
			sumY += 10;
		}
		for (int j = 0; j < (m / 60) + 1; j++) {
			sumM += 15;
		}
	}

	if (sumY > sumM) {
		printf("M %d", sumM);
	}
	else if (sumY == sumM) {
		printf("Y M %d", sumY);
	}
	else {
		printf("Y %d", sumY);
	}

	return 0;
}