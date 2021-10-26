#include <stdio.h>
#include <math.h>
#include <Windows.h>
struct point {
	int x;
	int y;
};

struct rect {
	struct point p1;
	struct point p2;
};

int main(void) {
	struct rect r;
	int w, h, area, peri;

	printf("점을 입력하시오 (x, y) : ");
	scanf("%d %d", &r.p1.x, &r.p1.y);
	printf("점을 입력하시오 (x, y) : ");
	scanf("%d %d", &r.p2.x, &r.p2.y);

	w = r.p2.x - r.p1.x;
	h = r.p2.y - r.p1.y;

	area = w * h;
	peri = 2 * w + 2 * h;

	printf("면적 : %d, 둘레 : %d\n", area, peri);
	return 0;
}