#include <stdio.h>
#include <ctype.h>

void count(char *s);

int main(void) {

	char str[50];
	printf("문자열 입력 : \n");
	gets(str);
	count(str);
	return 0;
}

void count(char *s) {
	int number = 0, alphabet = 0, expression = 0;
	for (int i = 0; s[i] != NULL; i++) {
		if (isdigit(s[i]))//숫자인지 판별
		{
			number++;
		}
		else if (isalpha(s[i]))//알파벳인지 판별
		{
			alphabet++;
		}
		else {
			expression++;
		}
	}
	printf("문자열 %s에서 숫자 : %d개, 알파벳 : %d개, 특수기호 : %d개\n", s,number, alphabet, expression);
}