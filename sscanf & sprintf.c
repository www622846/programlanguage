//sscanf & sprintf

#include <stdio.h>

int main(void) {

	char s1[] = "100";
	char s2[] = "12.93";
	char buffer[100];

	int i;
	double b;
	double result;

	sscanf(s1, "%d", &i);//s1�� int�� ����ȯ �� i���� ����
	sscanf(s2, "%lf", &b);

	result = i + b;

	sprintf(buffer, "%f", result);
	printf("���� ����� %s�Դϴ�.\n", buffer);

	return 0;
}