#include <stdio.h>
#include <string.h>

//���ڿ� ��ū

char s[] = "Man is immortal, because he has soul";
char seps[] = ",\t\n";
char *token;

int main(void) {
	token = strtok(s, seps);
	while (token != NULL) {
		printf("��ū : %s\n", token);

		token = strtok(NULL, seps);
	}

	return 0;
}