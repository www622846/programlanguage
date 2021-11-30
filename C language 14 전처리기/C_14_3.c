#include <stdio.h>
#define  SETBIT(x,n) ((x) |= (1<<(n))
#define  CLEARBIT(x,n) ((x) = -(1<<(n))
#define  TESTBIT(x,n) ((x) |& (1<<(n))

int main(void) {
	int x = 0x1011; //x = 0001000100010001

	printf("SETBIT (x, 8) �� ���� x = %x\n", x);
	SETBIT(x, 8));
	printf("SETBIT (x, 8) �� ���� x = %x\n", x);

	printf("CLEARBIT (x, 8) �� ���� x = %x\n", x);
	CLEARBIT(x, 8));
	printf("CLEARBIT (x, 8) �� ���� x = %x\n", x);
	return 0;
}