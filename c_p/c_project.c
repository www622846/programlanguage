#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <direct.h>
#include <io.h>


struct date
{
	int month;
	int day;
	int year;
};
struct d_title
{
	int id;
	char title[100];
	struct date d_date;
};
void file_searcher(char *path) {
	struct _finddata_t fd;
	long handle;
	int r = 1;
	char path_f[100];
	strcpy(path_f, path);
	strcat(path_f, ".\\*.*");
	handle = _findfirst(path_f,  &fd);
	if (handle == -1) {
		printf("파일 없음\n");
		return;
	}
	while (r != -1) {
		char no_pr[2][3] = { ".", ".." };
		for (int i = 0; i < 2; i++) {
			if (strcmp(fd.name, no_pr[i]) != 0)
				printf("파일명 : %s\n", fd.name);
			r = _findnext(handle, &fd);
		}
	}
	_findclose(handle);
	return;
}

void start_screen(char *ch) {
	system("mode con cols=140 lines=40");
	char direct_path_str[] = "C:\\diaryFolder";
	int Result_Folder_crete = mkdir(direct_path_str);
	if (Result_Folder_crete == 0) {
		printf("폴더가 생성되지 않았습니다\n%s 폴더를 생성했습니다.", direct_path_str);
	}
	else if(Result_Folder_crete == -1)
	{
		printf("폴더가 있습니다.\n");
	}
	file_searcher(direct_path_str);
	for (int i = 0; i < 3; i++) {
		printf("\n");
	}
	printf("%70s\n", "일기장");
	for (int i = 0; i < 4; i++) {
		printf("\n");
	}
	printf("%80s\n", "시작하려면 y를 누르시오.");
	char c;
	c = getch();
	*ch = c;
}

void main_screen() {
	system("cls");
	struct date d = { 01,01,2021 };
	struct d_title data[25];
	char di_date[25][15];
	char c;
	for (int i = 0; i < 25; i++) {
		data[i].id = i + 1;
		strcpy(data[i].title, "테스트123123 ");
		char s[100];
		sprintf(s, "%d", i + 1);
		strcat(data[i].title, s);
		data[i].d_date = d;
		sprintf(di_date[i], "%d.%d.%d", data[i].d_date.year, data[i].d_date.month, data[i].d_date.day+i);
	}
	char de[3][5] = {
		{"번호"},
		{"제목"},
		{"날짜"}
	};
	printf("%5s%2c%45s%55c%15s\n", de[0],'|', de[1],'|', de[2]);
	for (int i = 0; i < 140; i++) {
		printf("-");
	}
	printf("\n");
	for (int i = 0; i < 25; i++) {
		printf("%4d%3c%50s%50c%17s\n", data[i].id, '|', data[i].title, '|', di_date[i]);
	}
	printf("\n\n\t이전 : [\t다음 : ]\t만들기 : z\t검색 : x\t삭제 : c\t해상도 초기화 : v\n");
	while (1)
	{
		c=getch();
		char comment[6] = {'[', ']', 'z', 'x', 'c', 'v'};
		switch (c)
		{
			case '[':
				printf("이전");
				continue;
			case ']':
				printf("다음");
				continue;
			case 'z':
				printf("만듦");
				continue;
			case 'x':
				printf("검색");
				continue;
			case 'c':
				printf("삭제");
				continue;
			case 'v':
				printf("해상도 초기화");
				system("mode con cols=140 lines=40");
				main_screen();
				continue;
		}
	}
}

int main(void) {
	char input_1;
	start_screen(&input_1);
	if (input_1 == 'y') {
		main_screen();
	}
	return 0;
}