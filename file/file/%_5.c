#include <stdio.h>
#include <stdlib.h>
#define MAX 3

typedef struct _POINT {
	char *name;
	int xpos;
	int ypos;
} POINT;

int main(void) {
	POINT point[MAX] = { {"point1", 12, 14}, {"point2", 24, 11}, {"point3", 5, 114} };
	FILE *fp = fopen("example.txt", "wb");
	if (fwrite(point, sizeof(POINT), MAX, fp) != MAX) {
		printf("파입 입력이 잘못됨");
		exit(1);
	}
	fclose(fp);
	fp = fopen("example.txt", "rb");
	POINT cpPoint[MAX];
	fread(cpPoint, sizeof(POINT), MAX, fp);

	for (int i = 0; i < MAX; i++) {
		printf("%d번 (%s | %d, %d)\n", i + 1, cpPoint[i].name, cpPoint[i].xpos, cpPoint[i].ypos);
	}
	fclose(fp);
	return 0;
}