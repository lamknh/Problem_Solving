#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[1000000];
	int word = 0;

	gets(str); //scanf말고 gets 써야함 - gets는 공백 인식 가능
	char* token = strtok(str, " "); // string token	

	while (token != NULL) {
		word++;
		token = strtok(NULL, " ");
	}

	printf("%d", word);
	return 0;
}