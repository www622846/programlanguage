#include <stdio.h>
#include <string.h>

void mid(int num1, int num2, char *s);

int main(void) {
	int num1, num2;
	char str[50];
	printf("문자열을 입력하시오 >> ");
	scanf("%s", str);
	printf("문자열의 시작위치 입력 >> ");
	scanf("%d", &num1);
	printf("문자열의 길이 입력 >> ");
	scanf("%d", &num2);
	mid(num1, num2, str);
	return 0;
}
void mid(int num1, int num2, char *s) {
	int i;
	char temp[50];
	for (i = 0; i <= num2; i++) {
		temp[i] = s[num1 + i];
	}
	temp[num2] = '\0';
	printf("결과물은 %s이다.\n", temp);
}