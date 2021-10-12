//sscanf & sprintf

#include <stdio.h>

int main(void) {

	char s1[] = "100";
	char s2[] = "12.93";
	char buffer[100];

	int i;
	double b;
	double result;

	sscanf(s1, "%d", &i);//s1을 int로 형변환 후 i에게 넣음
	sscanf(s2, "%lf", &b);

	result = i + b;

	sprintf(buffer, "%f", result);
	printf("연산 결과는 %s입니다.\n", buffer);

	return 0;
}