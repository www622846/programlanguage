#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
	char s[100] = {0};
	char t[100] = { 0 };
	int i, j = 0;


	printf("�ؽ�Ʈ�� �Է��ϼ���.");
	gets(s);
	for (i = 0; i < strlen(s); i++) {
		if (s[i] != ' ') {
			t[j++] = s[i];
		}
	}
	printf("��� �ؽ�Ʈ ��� %s\n",t);


	return 0;
}