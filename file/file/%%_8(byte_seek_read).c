#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE  *fp;
	int fileindex, text;

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
	printf("파일을 읽을 바이트 단위를 입력하십시오 : ");
	scanf("%d", &fileindex);
	fp = fopen("data.txt", "r");
	if (fp == NULL) {
		printf("파일을 읽을 수 없습니다.");
		return 0;
	}
	fseek(fp, fileindex, SEEK_SET);
	printf("파일 위치 %d에서 읽습니다.\n", ftell(fp));

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