#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *fp = NULL;
	fp = fopen("data.txt", "w");
	if (fp == NULL) {
		printf("������ �� �� �����ϴ�.");
		exit(1);
	}
	fputs("This is an house", fp);
	fseek(fp, 11, SEEK_SET);
	fputs("apple", fp);
	fclose(fp);
	return 0;
}