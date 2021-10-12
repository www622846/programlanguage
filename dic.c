#include <stdio.h>
#include <string.h>


#define Words 5
int main(void) {
	int i, index;
	char dic[Words][2][30] = {
		{"book", "책"},
		{"boy", "소년"},
		{"computer", "컴퓨터"},
		{"language", "언어"},
		{"rain", "비"}
	};
	char word[30];
	
	printf("단어를 입력하시오 : ");
	scanf("%s", word);
	index = 0;
	for (i = 0; i < Words; i++) {
		if (strcmp(dic[i][0], word) == 0) {
			printf("%s : %s\n", word, dic[i][1]);
			return 0;
		}
	}
	printf("사전에서 발견되지 않았습니다.\n");
	return 0;
}