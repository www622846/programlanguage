#include <stdio.h>

location(char *s, char c);

int main(void) {
	char str[50];
	char letter;

	printf("���ڿ� �Է� >> ");
	gets(str);
	printf("Ư�� ���� �Է� >> ");
	scanf("%c", &letter);
	location(str, letter);
	return 0;
}

location(char *s, char c) {
	int i;
	int num;

	for (i = 0; s[i] != NULL; i++) {
		if (s[i] == c) {
			num = i + 1;
		}
	}
	printf("���ڿ� %s���� Ư�� ���� %c�� ��ġ�� %d�̴�.\n", s, c, num);
}