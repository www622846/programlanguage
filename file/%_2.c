#include <stdio.h>
#include  <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100

int main(void) {
	FILE *fp = NULL;
	char name[SIZE];
	char buf[SIZE];
	int count = 0;
	int i = 0;

	strcpy(name, "test2.txt");
	if ((fp = fopen(name, "w")) == NULL) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}

	strcpy(buf, "Hello, C Language");
	fputs(buf, fp);
	fclose(fp);
	if ((fp = fopen(name, "r")) == NULL) {
		fprintf(stderr, "���Ͽ��¿���\n");
		exit(1);
	}
	while (1) {
		fgets(buf, SIZE, fp);
		printf("buf�� ���� %s\n", buf);
		for (i = 0; buf[i] != '\0'; i++) {
			printf("buf[%d] = %c\n", i, buf[i]);
			if (isprint(buf[i]))	//0�� �ƴϸ� ����Ʈ ����, 0�̸� ����Ʈ �Ұ� (�ƽ�Ű 32~126).
				count++;			//���� ' '�� �������� ��(\t)�� �� �������� \n�� �� ������.
		}
		if (feof(fp)) break;//end of file
	}
	printf("�μ� ������ ������ ������ %d���Դϴ�.\n", count);
	fclose(fp);
	return 0;
}