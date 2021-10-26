#include <stdio.h>
#include <string.h>

struct email {
	char title[100];
	char receiver[100];
	char sender[100];
	char content[100];
	char date[100];
	int priority;//우선 순위
};
int main(void) {

	struct email e;
	strcpy(e.title, "제목");
	strcpy(e.receiver, "수신자");
	strcpy(e.sender, "발신자");
	strcpy(e.content, "내용");
	strcpy(e.date, "2020/9/1");
	e.priority = 1;

	printf(" %13s\n %25s\n%25s\n\n%30s\n\n%15s\n%10d\n\n", e.title, e.receiver, e.sender, e.content, e.date, e.priority);
	return 0;
}