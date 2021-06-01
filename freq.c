#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void get_abc(int);

int main(void) {
	srand((unsigned)time(NULL));
	get_abc(200);
	return 0;
}
void get_abc(int a) {
	int i;
	char x[200];
	int freq[26] = { 0 };
	int index, max = 0;
	for (i = 0; i < a; i++) {
		x[i] = rand() % 26;
	}
	for (i = 0; i < 200; i++) {
		++freq[x[i]];
	}
	for (i = 0; i < 26; i++) {
		if (freq[i] > max) {
			max = freq[i];
			index = i;
		}
	}
	printf("\n많이 나온 소문자는 %c이고 %d번 나왔습니다.\n\n", (index + 'a'), max);
}