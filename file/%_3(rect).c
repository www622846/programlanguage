#include <stdio.h>
typedef struct {
	int left, top, right, bottom;
} RECT;

int main(void) {
	FILE *fp;
	RECT rect;
	printf("�簢���� �� �𼭸��� ��ǥ�� ��Ÿ���� ���ڸ� �Է��Ͻʽÿ� : ");
	scanf("%d %d %d %d", &rect.left, &rect.top, &rect.right, &rect.bottom);
	printf("left = %d, top = %d, right = %d, bottom = %d\n", rect.left, rect.top, rect.right, rect.bottom);
	fp = fopen("rect.dat", "wb");
	if (fp == NULL) {
		printf("������ ������� �� �� �����ϴ�.");
		return 0;
	}
	fwrite(&rect, sizeof(RECT), 1, fp);
	fclose(fp);

	fp = fopen("rect.dat", "rb");
	if (fp == NULL) {
		printf("���� �б���� �� �� �����ϴ�.\n");
		return 0;
	}
	fread(&rect, sizeof(RECT), 1, fp);
	fclose(fp);
	printf("left = %d, top = %d, right = %d, bottom = %d\n", rect.left, rect.top, rect.right, rect.bottom);
	return 0;
}