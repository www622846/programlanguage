#include <stdio.h>
#include <string.h>


#define Words 5
int main(void) {
	int i, index;
	char dic[Words][2][30] = {
		{"book", "å"},
		{"boy", "�ҳ�"},
		{"computer", "��ǻ��"},
		{"language", "���"},
		{"rain", "��"}
	};
	char word[30];
	
	printf("�ܾ �Է��Ͻÿ� : ");
	scanf("%s", word);
	index = 0;
	for (i = 0; i < Words; i++) {
		if (strcmp(dic[i][0], word) == 0) {
			printf("%s : %s\n", word, dic[i][1]);
			return 0;
		}
	}
	printf("�������� �߰ߵ��� �ʾҽ��ϴ�.\n");
	return 0;
}