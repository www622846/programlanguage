#include <stdio.h>
#include <ctype.h>

void count(char *s);

int main(void) {

	char str[50];
	printf("���ڿ� �Է� : \n");
	gets(str);
	count(str);
	return 0;
}

void count(char *s) {
	int number = 0, alphabet = 0, expression = 0;
	for (int i = 0; s[i] != NULL; i++) {
		if (isdigit(s[i]))//�������� �Ǻ�
		{
			number++;
		}
		else if (isalpha(s[i]))//���ĺ����� �Ǻ�
		{
			alphabet++;
		}
		else {
			expression++;
		}
	}
	printf("���ڿ� %s���� ���� : %d��, ���ĺ� : %d��, Ư����ȣ : %d��\n", s,number, alphabet, expression);
}