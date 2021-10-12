#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
	char s[100] = {0};
	char t[100] = { 0 };
	int i, j = 0;


	printf("텍스트를 입력하세요.");
	gets(s);
	for (i = 0; i < strlen(s); i++) {
		if (s[i] != ' ') {
			t[j++] = s[i];
		}
	}
	printf("결과 텍스트 출력 %s\n",t);


	return 0;
}