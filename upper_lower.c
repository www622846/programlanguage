#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LINENUM 81

int main(void) {
	int i, len;
	char line[LINENUM];
	printf("���� ������ �Է��Ͻÿ� : \n");
	gets(line);
	len = strlen(line);//���ڿ��� ���̸� len�� ����.
	printf("������ �Է��� ���ڿ����� �빮�ڿ� �ҹ��ڸ� �ݴ�� ��ȯ�ϸ� >> \n");
	for (i = 0; i < len; i++) {
		if ('A' <= line[i] && 'Z' >= line[i]) {
			line[i] = tolower(line[i]);
		}
		else if ('a' <= line[i] && 'z' >= line[i])
		{
			line[i] = toupper(line[i]);
		}
		printf("%c", line[i]);
	}
	printf("\n");

	return 0;
}