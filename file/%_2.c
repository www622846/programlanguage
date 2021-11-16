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
		fprintf(stderr, "파일 오픈 오류\n");
		exit(1);
	}

	strcpy(buf, "Hello, C Language");
	fputs(buf, fp);
	fclose(fp);
	if ((fp = fopen(name, "r")) == NULL) {
		fprintf(stderr, "파일오픈오류\n");
		exit(1);
	}
	while (1) {
		fgets(buf, SIZE, fp);
		printf("buf의 내용 %s\n", buf);
		for (i = 0; buf[i] != '\0'; i++) {
			printf("buf[%d] = %c\n", i, buf[i]);
			if (isprint(buf[i]))	//0이 아니면 프린트 가능, 0이면 프린트 불가 (아스키 32~126).
				count++;			//공백 ' '은 세어지고 탭(\t)은 안 세어지고 \n도 안 세어짐.
		}
		if (feof(fp)) break;//end of file
	}
	printf("인쇄 가능한 문자의 개수는 %d개입니다.\n", count);
	fclose(fp);
	return 0;
}