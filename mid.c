#include <stdio.h>
#include <string.h>

void mid(int num1, int num2, char *s);

int main(void) {
	int num1, num2;
	char str[50];
	printf("���ڿ��� �Է��Ͻÿ� >> ");
	scanf("%s", str);
	printf("���ڿ��� ������ġ �Է� >> ");
	scanf("%d", &num1);
	printf("���ڿ��� ���� �Է� >> ");
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
	printf("������� %s�̴�.\n", temp);
}