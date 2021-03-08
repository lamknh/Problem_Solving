#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, score[1000], max = 0;
	float final[1000], all = 0;
	scanf("%d", &a);

	for (int i = 0; i < a; i++) {
		scanf("%d", &score[i]);
		if (score[i] > max) {
			max = score[i];
		}
	}

	for (int i = 0; i < a; i++) {
		final[i] = ((float)score[i] / (float)max * 100);
		all += final[i]	;
	}

	printf("%lf", (all / (float)a));

	return 0;
}