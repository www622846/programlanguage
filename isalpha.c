#include <stdio.h>
#include <ctype.h>

int main(void) {
	int i = 0, num = 0;
	char str[50];

	printf("문자열을 입력하시오 >> \n");
	gets(str);
	while (str[i])
	{
		if (isalpha(str[i])) num++;
		i++;
	}
	printf("영문자의 개수 %d\n", num);

	return 0;
}