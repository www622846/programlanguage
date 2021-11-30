#include <stdio.h>	//매크로 문제 
#define DEBUG

int main(void) { 
	int data[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int i, sum;
	double avg;
	sum = 0;
	for (i = 0; i < 10; i++) {
		#ifdef DEBUG
				printf("현재 데이터 : %d\n", data[i]);
		#endif // DEBUG
				sum += data[i];
	}
	avg = sum / 10;
	printf("평균값 : %f\n", avg);
	return 0;
}