#include <stdio.h>

struct time {
	int second;
	int minute;
	int hour;
};
int main(void) {
	int diff_h, diff_min, diff_sec;
	struct time t1, t2;
	printf("�ð��� �Է��Ͻÿ� (�� , ��, ��) : ");
	scanf("%d %d %d", &t1.hour, &t1.minute, &t1.second);
	printf("�ð��� �Է��Ͻÿ� (�� , ��, ��) : ");
	scanf("%d %d %d",& t2.hour, &t2.minute,& t2.second);

	if (t1.second > t2.second) {
		--t2.minute;
		t2.second += 60;
	}
	diff_sec = t2.second - t1.second;
	if (t1.minute > t2.minute) {
		--t2.hour;
		t2.minute += 60;
	}
	diff_min = t2.minute - t1.minute;
	diff_h = t2.hour - t1.hour;

	printf("�ҿ�ð� : %d:%d:%d\n", diff_h, diff_min, diff_sec);
	return 0;
}