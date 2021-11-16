#include <stdio.h>

int main(void) {
	int buffer[] = { 10,20,30,40,50,60,70,80,90,100 };
	FILE *fp= NULL; 

	int i, size, count;

	fp = fopen("binary.bin", "wb");

	if (fp == NULL) {
		fprintf(stderr, "binary.bin파일을 찾을 수 없습니다,");
		exit(1);
	}

	size = sizeof(buffer[0]);
	count = sizeof(buffer) / sizeof(buffer[0]);
	i = fwrite(&buffer, size, count, fp);
	fclose(fp);

	return 0;
}