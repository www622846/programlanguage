#include <stdio.h>
enum days{MON, TUE, WED, THU, FRI, SAT, SUN};

char *days_name[] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saterday", "sunday" };

int main(void) {
	enum days d;

	for (d = MON; d <= SUN; d++) {
		printf("%d��° ������ �̸��� %s�Դϴ�.\n", d, days_name[d]);
	}
	return 0;
}