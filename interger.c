#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char line[81];
	printf("���� ������ ���ڿ��� �ϳ� �Է��Ͻÿ�. ");
	gets(line);
	printf("���ڿ��� �Է� ���� : %s\n\n", line);
	printf("�Լ� atoi()�� �̿��Ͽ� �Է��� ���ڿ��� ������ �ٲٸ� > %d\n", atoi(line));

	return 0;
}