#include <stdio.h>
void my_strcat(char *d, char *s);

int main(void) {
	char s1[15] = "love";
	char s2[6] = "holic";
	my_strcat(s1, s2);
	printf("%s\n", s1);
	return 0;
}

void my_strcat(char *d, char *s) {
	int length = 0;
	while (d[length])
	{
		length++;
	}
	while (*s)
	{
		*(d + length++) = *s++;
	}
}