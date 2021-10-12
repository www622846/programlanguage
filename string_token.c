#include <stdio.h>
#include <string.h>

//문자열 토큰

char s[] = "Man is immortal, because he has soul";
char seps[] = ",\t\n";
char *token;

int main(void) {
	token = strtok(s, seps);
	while (token != NULL) {
		printf("토큰 : %s\n", token);

		token = strtok(NULL, seps);
	}

	return 0;
}