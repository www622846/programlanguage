#include <stdio.h>
#include <ctype.h>

int main(void) {
	int i;
	int num = 0;
	char str[50] = "Hello C World";
	printf("���� ���ڿ�\n");
	puts(str);
	while (str[num] != '\0') num++;
	for (i = 0; i < num; i++) {
		str[i] = toupper(str[i]);
	}
	printf("�ٲ� ���ڿ� \n");
	puts(str);
	return 0;

}