#include <stdio.h>
#include <string.h>
void replace(int num1, int num2, char *s1, char *s2);
int main(void) {
	int num1, num2;
	char str1[50], str2[50];
	printf("���ڿ� �Է� >> ");
	gets(str1);
	printf("���ڿ��� ������ġ �Է� >> ");
	scanf("%d", &num1);
	printf("���ڿ� ���� �Է� >> ");
	scanf("%d", &num2);
	printf("���ڿ� �Է� >> ");
	scanf("%s", str2);
	replace(num1, num2, str1, str2);

	return 0;
}

void replace(int num1, int num2, char *s1, char *s2) {
	int i;

	for (i = 0; i < num2; i++) {
		s1[num1 + i] = s2[i];
	}
	printf("������� %s�̴�.\n", s1);
}