#include <stdio.h>
#include <string.h>
void replace(int num1, int num2, char *s1, char *s2);
int main(void) {
	int num1, num2;
	char str1[50], str2[50];
	printf("문자열 입력 >> ");
	gets(str1);
	printf("문자열의 시작위치 입력 >> ");
	scanf("%d", &num1);
	printf("문자열 길이 입력 >> ");
	scanf("%d", &num2);
	printf("문자열 입력 >> ");
	scanf("%s", str2);
	replace(num1, num2, str1, str2);

	return 0;
}

void replace(int num1, int num2, char *s1, char *s2) {
	int i;

	for (i = 0; i < num2; i++) {
		s1[num1 + i] = s2[i];
	}
	printf("결과물은 %s이다.\n", s1);
}