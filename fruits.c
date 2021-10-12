#include <stdio.h>
#include <string.h>

#define SIZE 6
int main(void) {
	int i, k;

	char fruits[SIZE][20] = {
		"pineapple",
		"banana",
		"apple",
		"tomato",
		"paer",
		"avocado"
	};

	for (k = 0; k < SIZE; k++) {
		for (i = 0; i < SIZE; i++) {
			if (strcmp(fruits[i], fruits[i + 1]) > 0) {///fruits[i+1]이 더 앞이라면
				char tmp[20];
				strcpy(tmp, fruits[i]);
				strcpy(fruits[i], fruits[i + 1]);
				strcpy(fruits[i + 1], tmp);
			}
		}
	}for (k = 0; k < SIZE; k++) {
		printf("%s\n", fruits[k]);
	}

	return 0;
}