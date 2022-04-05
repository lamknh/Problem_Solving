#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, num = 0;

	scanf("%d", &a);

	while (1) {
		if (a % 5 == 0) {
			num += a / 5;
			break;
		}
		else{
			a -= 3;
			num++;
		}

		if (a < 0) {
			num = -1;
			break;
		}
	}

	printf("%d", num);
	return 0;
}