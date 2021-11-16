#include <stdio.h>
typedef struct {
	int left, top, right, bottom;
} RECT;

int main(void) {
	FILE *fp;
	RECT rect;
	printf("사각형의 네 모서리의 좌표를 나타내는 숫자를 입력하십시오 : ");
	scanf("%d %d %d %d", &rect.left, &rect.top, &rect.right, &rect.bottom);
	printf("left = %d, top = %d, right = %d, bottom = %d\n", rect.left, rect.top, rect.right, rect.bottom);
	fp = fopen("rect.dat", "wb");
	if (fp == NULL) {
		printf("파일을 쓰기모드로 열 수 없습니다.");
		return 0;
	}
	fwrite(&rect, sizeof(RECT), 1, fp);
	fclose(fp);

	fp = fopen("rect.dat", "rb");
	if (fp == NULL) {
		printf("파일 읽기모드로 쓸 수 없습니다.\n");
		return 0;
	}
	fread(&rect, sizeof(RECT), 1, fp);
	fclose(fp);
	printf("left = %d, top = %d, right = %d, bottom = %d\n", rect.left, rect.top, rect.right, rect.bottom);
	return 0;
}