#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void get_random(int);

int main(void) {
	srand((unsigned)time(NULL));
	get_random(10);
	return 0;
}
void get_random(int x) {
	int i;
	for (i = 0; i < x; i++) {
		printf("	%6d\n", (rand() % 20) + 1);
	}
}