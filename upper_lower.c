#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LINENUM 81

int main(void) {
	int i, len;
	char line[LINENUM];
	printf("영문 문장을 입력하시오 : \n");
	gets(line);
	len = strlen(line);//문자열의 길이를 len에 저장.
	printf("위에서 입력한 문자열에서 대문자와 소문자를 반대로 변환하면 >> \n");
	for (i = 0; i < len; i++) {
		if ('A' <= line[i] && 'Z' >= line[i]) {
			line[i] = tolower(line[i]);
		}
		else if ('a' <= line[i] && 'z' >= line[i])
		{
			line[i] = toupper(line[i]);
		}
		printf("%c", line[i]);
	}
	printf("\n");

	return 0;
}