#include <stdio.h>
#include <string.h>
#define SIZE 3

struct food {
	char name[100];
	int cal;
};
int main(void) {
	struct food food_array[3] = { {"hambuger", 900}, {"bulgogi", 500}, {"sushi", 700} };

	int i, total = 0;

	for (i = 0; i < 3; i++) {
		printf("%10s, %5d\n", food_array[i].name, food_array[i].cal);
		total += food_array[i].cal;
	}
	printf("%d\n", total);
	return 0;
}