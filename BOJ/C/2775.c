#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int T, k, n;

	int ppl[15][15] = {0};
	int num[100] = { 0 };

	for (int j = 1; j < 15; j++) {
		ppl[0][j] = j;
	} // 0층 값 넣기

	for (int j = 1; j < 15; j++) {
		for (int m = 1; m < 15; m++) {
			for (int k = 1; k < (m+1); k++) {
				ppl[j][m] += ppl[j - 1][k];
			}
		}	
	} // 전체 사람 수 저장

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &k);
		scanf("%d", &n);

		for (int j = 0; j < T; j++) {
			for (int p = 0; p < n; p++) {
				num[i] = ppl[k][p+1];
			}
		}
	}

	for (int i = 0; i < T; i++) {
		printf("%d\n", num[i]);
	}

	return 0;
}