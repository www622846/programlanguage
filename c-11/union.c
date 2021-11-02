#include <stdio.h>
union example {
	int i;
	char c;
};


int main(void) {
	union example data;
	data.i = 10000;
	printf("%d %c\n", data.i, data.c);

	data.c = 'A';
	printf("%d %c\n", data.i, data.c);


	return 0;
}