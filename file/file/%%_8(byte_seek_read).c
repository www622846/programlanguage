#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE  *fp;
	int fileindex, text;

	fp = fopen("data.txt", "w");
	if (fp == NULL) {
		printf("������ �� �� �����ϴ�");
		return 0;
	}
	fputs("Hello, C Language!", fp);
	fclose(fp);
	fp = fopen("data.txt", "r");
	if (fp == NULL) {
		printf("������ ���� �� �����ϴ�.");
		return 0;
	}
	printf("������ ���� ����Ʈ ������ �Է��Ͻʽÿ� : ");
	scanf("%d", &fileindex);
	fp = fopen("data.txt", "r");
	if (fp == NULL) {
		printf("������ ���� �� �����ϴ�.");
		return 0;
	}
	fseek(fp, fileindex, SEEK_SET);
	printf("���� ��ġ %d���� �н��ϴ�.\n", ftell(fp));

	while (1)
	{
		text = fgetc(fp);
		printf("%c", text);
		if (feof(fp)) break;
	}
	printf("\n");
	fclose(fp);
	return 0;
}