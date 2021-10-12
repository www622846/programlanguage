#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char line[81];
	printf("정수 형으로 문자열을 하나 입력하시오. ");
	gets(line);
	printf("문자열로 입력 받음 : %s\n\n", line);
	printf("함수 atoi()를 이용하여 입력한 문자열을 정수로 바꾸면 > %d\n", atoi(line));

	return 0;
}