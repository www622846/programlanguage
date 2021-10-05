#include <stdio.h>

location(char *s, char c);

int main(void) {
	char str[50];
	char letter;

	printf("문자열 입력 >> ");
	gets(str);
	printf("특정 문자 입력 >> ");
	scanf("%c", &letter);
	location(str, letter);
	return 0;
}

location(char *s, char c) {
	int i;
	int num;

	for (i = 0; s[i] != NULL; i++) {
		if (s[i] == c) {
			num = i + 1;
		}
	}
	printf("문자열 %s에서 특정 문자 %c의 위치는 %d이다.\n", s, c, num);
}