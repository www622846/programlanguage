#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define sol "apple"
int main(void) {
	char s[100] = sol;
	char ans[100];
	int i, len;

	len = strlen(s);

	for (i = 0; i < len; i++) {
		int pos1 = rand() % len;
		int pos2 = rand() % len;

		char tmp = s[pos1];
		s[pos1] = s[pos2];
		s[pos2] = tmp;
	}

	do {
		printf("%s�� �ܾ ���߽ÿ� : ",s);
		scanf("%s",ans);
	} while (strcmp(sol, ans) != 0);
	printf("�����մϴ�.\n");
	return 0;
}