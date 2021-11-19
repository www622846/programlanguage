#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>	//system을 쓰기 위함
#include <direct.h>		//mkdir()을 쓰기 위함
#include <io.h>	//struct _finddata_t fd;를 써야함.


struct date
{
	int month;
	int day;
	int year;
};
struct d_title	//Display Title
{
	int id;
	char title[100];
	struct date d_date;
};

typedef struct  {
	int prority;
	char title[101];	//제목은 100자이하
	//struct date file_crate_date;
	char content[501];	//내용은 500자이하
}FILE_SAMPLE;

char folder_path[] = "C:\\diaryFolder";	//폴더 경로

void file_read(int file_number);
void write_file();
const char* get_path_of_file(int input);
void correct_file(int file_number);
void remove_file();
int file_count_func( char *path) {	//파일의 최대 개수
	struct _finddata_t fd;
	int result = -1;
	long handle;
	int r = 1;
	char path_f[100];
	strcpy(path_f, path);
	strcat(path_f, ".\\*.*");
	handle = _findfirst(path_f, &fd);
	if (handle == -1) {
		printf("오류\n파일 없음\n");
		return;
	}
	while (r != -1) {	//파일의 개수을 알아냄
		r = _findnext(handle, &fd);
		if (strcmp(fd.name, ".") != 0 && strcmp(fd.name, "..") != 0) {
			result++;
		}
	}
	return result;
}

const char* get_file_name_func( char *path, int total_file_count, int select_file_number) {	//파일의 이름(반드시 파일이 1개 이상 있어야함)
	struct _finddata_t fd;
	long handle;
	int r = 1;
	char path_f[100];
	char path_for_file[100] = { 0 };
	char result_string[10] = { 0 };
	strcpy(path_f, path);
	strcat(path_f, ".\\*.*");

	FILE *fp;
	FILE_SAMPLE f_s;
	handle = _findfirst(path_f, &fd);
	if (handle == -1) {
		printf("오류\n파일 없음\n");
		return;
	}r = 1;
	int i = 0;
	while (r != -1) {	//파일의 이름을 알아냄
		if (strcmp(fd.name, ".") != 0 && strcmp(fd.name, "..") != 0) {
			strcpy(path_for_file, path);
			strcat(path_for_file, "\\");
			strcat(path_for_file, fd.name);
			if ((fp = fopen(path_for_file, "rb")) == NULL) {
				printf("get_file_name_func()\n파일 쓰기 오류\n");
				exit(1);
			}
			else	//파일 오류가 안 난다면
			{
				fread(&f_s, sizeof(FILE_SAMPLE), 1, fp);
				////////////////////////////////printf("%s | %d\n", fd.name, f_s.prority);
				if (f_s.prority == select_file_number) {	//선택한 우선순위가 파일 내 우선순위와 같다면
					strcpy(result_string, fd.name);
				}
				i++;
			}
			fclose(fp);
		}
		r = _findnext(handle, &fd);
	}
	_findclose(handle);
	return result_string;
}



void start_screen(char *ch) {	//시작할 때 가장 먼저 실행하는 함수
	system("mode con cols=140 lines=40");	//cmd창을 140 * 40 으로 맞춤
	int Result_Folder_crete = mkdir(folder_path);	//해당경로에 있는 해당폴더를 만드는 함수
	if (Result_Folder_crete == 0) {
		printf("폴더가 생성되지 않았습니다\n%s 폴더를 생성했습니다.", folder_path);
	}
	else if(Result_Folder_crete == -1)
	{
		printf("폴더가 있습니다.\n");
	}
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

void main_screen() {	//시작 후 일기장을 보여주는 함수
	struct _finddata_t fd_;
	system("cls");	//cmd창을 비움
	struct date d = { 01,01,2021 };
	struct d_title data[25];
	char di_date[25][15];
	char file_name[50];
	char c;
	FILE *fp;
	FILE_SAMPLE read_f_s;
	int file_total_number = file_count_func(folder_path);
	if (file_total_number != -1) {
		for (int i = 0; i < file_total_number; i++) {
			strcpy(file_name, get_path_of_file(i + 1));
			if ((fp = fopen(file_name, "rb")) == NULL) {
				printf("--main_screen--\n파일 읽기 오류!\n");
				printf("%s\n", file_name);
				exit(1);
			}
			fread(&read_f_s, sizeof(read_f_s), 1, fp);
			fclose(fp);
			data[i].id = read_f_s.prority;
			strcpy(data[i].title, read_f_s.title);
			char s[100];
			data[i].d_date = d;
			sprintf(di_date[i], "%d.%d.%d", data[i].d_date.year, data[i].d_date.month, data[i].d_date.day + i);
		}
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
	for (int i = 0; i < file_total_number; i++) {
		printf("%4d%3c%50s%50c%17s\n", data[i].id, '|', data[i].title, '|', di_date[i]);//문자열 수정
	}
	printf("\n\n\t이전 : [\t다음 : ]\t만들기 : z\t읽기 : x\t삭제 : c\t해상도 초기화 : v\t종료 : b\n");
	while (1)	//입력하는 문자를 입력받음.
	{
		c=getch();	//버퍼없이 문자를 입력받음
		char comment[6] = {'[', ']', 'z', 'x', 'c', 'v'};
		switch (c)
		{
			case '[':
				printf("이전");
				return;
			case ']':
				printf("다음");
				return;
			case 'z':
				system("cls");
				printf("일기장을 만듭니다.\n주의 : 작성 중 프로그램을 끄지마세요!\n중간에 끄면 파일 작성이 안됩니다!\n");
				write_file();
			case 'x':
				printf("읽기");
				int input_number = 0;
				printf("읽고 싶은 파일번호를 입력하시오 (1~25) : ");
				while (1)
				{
					scanf("%d", &input_number);
					if (input_number <= file_count_func(folder_path) && input_number > 0) {	//만약 입력한 숫자가 폴더 내에 있는 파일 숫자보다 작거나 같다면
						file_read(input_number);	//파일을 읽는 함수 호출
					}
					else
					{
						printf("%d보다 같거나  작은 수(양수)를 입력해주세요.", file_count_func(folder_path));
					} 
				}
				return;
			case 'c':
				printf("삭제"); 
				remove_file();
				continue;
			case 'v':
				printf("창 크기 초기화");
				system("mode con cols=140 lines=40");
				main_screen();
				continue;
			case 'b':
				printf("종료합니다.\n");
				return;
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

void file_read(int file_number) {
	FILE *fp;
	FILE_SAMPLE f_s;
	char path[50];
	system("cls");
	strcpy(path, get_path_of_file(file_number));
	if ((fp = fopen(path, "rb")) == NULL) {
		printf("\n파일 읽기 오류--file_read()\n");
		exit(1);
	}
	fread(&f_s, sizeof(f_s), 1, fp);
	fclose(fp);
	printf("우선순위 : %d\n제목 : %s\n내용 %s\n\n", f_s.prority, f_s.title, f_s.content);
	printf("\t%s : %c\t%s : %c\n", "나가기", 'o', "수정", 'p');
	char input_key;
	while (1)
	{
		input_key = getch();
		switch (input_key)
		{
		case 'o':
			main_screen();
		case 'p':
			printf("수정을 합니다.\n"); 
			correct_file(file_number);
			return 0;
		}
	}
}

void correct_file(int file_number) {
	FILE *fp;
	FILE_SAMPLE correct_f_s;
	char p[50];
	strcpy(p, get_path_of_file(file_number));
	printf("%s\n", p);
	if((fp = fopen(p, "wb"))==NULL){
		printf("수정하려는 파일을 읽기를 실패하였습니다.\n");
		exit(1);
	}
	fread(&correct_f_s, sizeof(correct_f_s), 1, fp);
	fclose(fp);
	scanf("%s", correct_f_s.title);
}
const char* get_path_of_file(int input) {	//파일 경로만들어주는 함수
	int file_total_number = file_count_func(folder_path);
	char path_for_file[100];
	strcpy(path_for_file, folder_path);
	strcat(path_for_file, "\\");
	strcat(path_for_file, get_file_name_func(folder_path, file_total_number, input));
	return path_for_file;
}

void remove_file() {
	int input_int = 0;
	char input_char = { 0 };
	char path[50];
	FILE *fp;
	FILE_SAMPLE file_sample;
	printf("삭제하려는 파일의 번호를 입력해주세요. (0 : 취소)");
	while (1) {
		scanf("%d", &input_int);
		if (input_int <= file_count_func(folder_path) && input_int > 0) {
			strcpy(path, get_path_of_file(input_int));
			if ((fp = fopen(path, "rb")) == NULL) {
				printf("remove_file()\n파일을 삭제하려는 동안 오류가 발생하였습니다!\n");
				exit(1);
			}
			fread(&file_sample, sizeof(file_sample), 1, fp);
			fclose(fp);
			printf("일기 제목이 %s맞습니까? (y/n) : ", file_sample.title);
			short i = 0;
			while (i == 0)
			{
				input_char = getchar();
				if (input_char == 'y') {
					char path[50];
					strcpy(path, get_path_of_file(input_int));
					int result = remove(path);
					if (result == 0) {
						printf("%s\n파일을 삭제 성공했습니다...\n", path);
						printf("메인화면으로 돌아갑니다...\n");
						Sleep(1500);
						main_screen();
					}
					else if (result == -1)
					{
						printf("%s\n파일을 삭제 실패했습니다...\n", path);
						printf("메인화면으로 돌아갑니다...\n");
						Sleep(1500);
						main_screen();
					}
				}
				else if (input_char == 'n') {
					printf("\n번호를 다시 입력해주십시오. >> ");
					i = 1;
				}
			}
		}
		else if(input_int == 0)
		{
			printf("다시 돌아갑니다...\n");
			return;
		}
		else {
			printf("%d보다 같거나  작은 수(양수)를 입력해주세요 >> ", file_count_func(folder_path));
		}
	}
}

void write_file() {
	srand(time(NULL));
	unsigned int random_title = (rand() % 50000) + 10000;//파일 이름을 난수로 정할거임.
	//===============파일 이름 중복 검출해야함.=====================
	char file_name[10];
	sprintf(file_name, "%d", random_title);
	strcat(file_name, ".txt");
	FILE *fp;
	FILE_SAMPLE write_f_s;
	if (file_count_func(folder_path) == -1) {
		write_f_s.prority = 1;
	}
	else
	{
		write_f_s.prority = file_count_func(folder_path) + 1;
	}
	printf("%d\n", write_f_s.prority);
	printf("제목을 입력해주세요.\n제목:");
	fgets(write_f_s.title, 100, stdin);
	printf("===========================================================\n내용을 입력해주세요.\n내용:");
	fgets(write_f_s.content, 500, stdin);
	int i;
	char path_[50];
	strcpy(path_, folder_path);
	strcat(path_, "\\");
	strcat(path_, file_name);
	printf("%s\n", path_);
	fp = fopen(path_, "wb");

	if (fp == NULL)
	{
		printf("실패\n");
	}
	else
	{
		printf("성공\n");
	}
	fwrite(&write_f_s, sizeof(write_f_s), 1, fp);
	fclose(fp);
	printf("\n작성 완료!\n곧 메인화면으로 돌아갑니다!\n");

	Sleep(1000);//딜레이를 줌
	main_screen();
}
