#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE  *fp;
	int i, text;

	fp = fopen("data.txt", "w");
	if (fp == NULL) {
		printf("파일을 열 수 없습니다");
		return 0;
	}
	fputs("Hello, C Language!", fp);
	fclose(fp);
	fp = fopen("data.txt", "r");
	if (fp == NULL) {
		printf("파일을 읽을 수 없습니다.");
		return 0;
	}
	fseek(fp, 7, SEEK_SET);
	text = fgetc(fp);
	printf("%c\n", text);
	fseek(fp, 1, SEEK_CUR);
	for (i = 0; i < 4; i++) {
		text = fgetc(fp);
		printf("%c", text);
	}
	printf("\n");
	fclose(fp);
	return 0;
}