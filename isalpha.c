#include <stdio.h>
#include <ctype.h>

int main(void) {
	int i = 0, num = 0;
	char str[50];

	printf("���ڿ��� �Է��Ͻÿ� >> \n");
	gets(str);
	while (str[i])
	{
		if (isalpha(str[i])) num++;
		i++;
	}
	printf("�������� ���� %d\n", num);

	return 0;
}