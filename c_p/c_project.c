#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>	//system을 쓰기 위함
#include <direct.h>		//mkdir()을 쓰기 위함
#include <io.h>	//struct _finddata_t fd;를 써야함. 있어야지 폴더 내에 있는 파일 정보를 읽을 수 있음.
#include <time.h>//time_t

struct date
{
	int month;
	int day;
	int year;
};
struct d_title	//Display Title main_screen()에 필요한 구조체
{
	int id;
	char title[100];
	struct date d_date;
};

typedef struct {
	int prority;
	char title[101];	//제목은 100자이하
	char content[501];	//내용은 500자이하
	struct date file_crate_date;	//파일 생성 날짜
	int Iscorrect;	//수정 여부 확인
}FILE_SAMPLE;

char folder_path[] = "C:\\diaryFolder";	//폴더 경로

void file_read(int file_number);
void write_file();
const char* get_path_of_file(int input);
void correct_file(int file_number);
void remove_file(int page, int listnum);
void array_setup(int delete_file_number);
void print_line();

int file_count_func(char *path) {	//파일의 최대 개수
	struct _finddata_t fd;
	int result = -1;
	long handle;
	int r = 1;
	char path_f[100];
	strcpy(path_f, path);
	strcat(path_f, ".\\*.*");
	handle = _findfirst(path_f, &fd);	//첫번째 파일
	if (handle == -1) {
		printf("오류\n파일 없음\n");
		return;
	}
	while (r != -1) {	//파일의 개수을 알아냄
		r = _findnext(handle, &fd);	//다음 파일
		if (strcmp(fd.name, ".") != 0 && strcmp(fd.name, "..") != 0) {	//.과 ..은 제외
			result++;	//파일있을 때마다 result++
		}
	}
	return result;
}

const char* get_file_name_func(char *path, int total_file_count, int select_file_number) {	//파일의 이름(반드시 파일이 1개 이상 있어야함)
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
	}
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
				if (f_s.prority == select_file_number) {	//선택한 우선순위가 파일 내 우선순위와 같다면
					strcpy(result_string, fd.name);
				}
				i++;
			}
			fclose(fp);
		}
		r = _findnext(handle, &fd);	//다음 파일로
	}
	_findclose(handle);	//닫음
	return result_string;
}

void start_screen(char *ch) {	//시작할 때 가장 먼저 실행하는 함수
	system("mode con cols=141 lines=40");	//cmd창을 140 * 40 으로 맞춤
	int Result_Folder_crete = mkdir(folder_path);	//해당경로에 있는 해당폴더를 만드는 함수
	if (Result_Folder_crete == 0) {
		printf("폴더가 생성되지 않았습니다\n%s 폴더를 생성했습니다.", folder_path);
	}
	else if (Result_Folder_crete == -1)
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
	return;
}

void main_screen() {	//시작 후 일기장을 보여주는 함수
	struct d_title data[25];
	char di_date[25][15];
	char file_name[50];

	FILE *fp;
	struct _finddata_t fd_;
	int Isclear = 1;
	FILE_SAMPLE read_f_s;
	char c;	//입력받게 하는 문자
	int page = 0;
	int se_nu = 0;	//숫자를 다시 셋팅하는 정수
	while (1)
	{
		int file_total_number = file_count_func(folder_path);
		if (Isclear)
		{
			system("cls");	//cmd창을 비움
			if (file_total_number >= 25 * (page + 1)) {	//만약 파일 최대 숫자가 page + 1에 25를 곱한 수보다 크거나 같다면
				se_nu = 25 * (page + 1);	//se_nu는 page + 1에서 25 곱한 값이다.
			}
			else
			{
				se_nu = file_total_number - 25 * (file_total_number / 25);	//아니라면 se_nu는 최대 개수에 최대 개수를 25로 나눈 몫에 25를 곱한 값이다.
			}
			if (file_total_number != -1) {
				for (int i = 0; i < se_nu; i++) {
					strcpy(file_name, get_path_of_file(i + 1 + page * 25));
					if ((fp = fopen(file_name, "rb")) == NULL) {
						printf("--main_screen--\n파일 읽기 오류!\n");
						exit(1);
					}
					fread(&read_f_s, sizeof(read_f_s), 1, fp);
					fclose(fp);
					data[i].id = read_f_s.prority;	//우선순위를 data[i].id로
					strcpy(data[i].title, read_f_s.title);	//data[i].title에 제목을 복사
					data[i].d_date = read_f_s.file_crate_date;
					sprintf(di_date[i], "%d.%d.%d", data[i].d_date.year, data[i].d_date.month, data[i].d_date.day);
				}
			}
			printf("\n");
			char de[3][5] = {
				{ "번호" },
				{ "제목" },
				{ "날짜" }
			};
			printf("%5s%2c%45s%55c%15s\n", de[0], '|', de[1], '|', de[2]);	//틀 만듦
			for (int i = 0; i < 140; i++) {
				printf("-");
			}
			printf("\n");
			for (int i = 0; i < se_nu; i++) {//문자열 나열 시작
				printf("%4d%3c ", data[i].id, '|');
				for (int j = 0; j < 98; j++) {
					if (strlen(data[i].title) > j) {
						if (data[i].title[j] != '\n')
							printf("%c", data[i].title[j]);
					}
					else
					{
						printf(" ");
					}
				}
				printf("|%16s\n", di_date[i]);//문자열 나열 끝
			}
			printf("\n\n\t\t\t\t\t\t\t[현재 페이지 : %d]\n\n\t이전 : [\t다음 : ]\t만들기 : z\t읽기 : x\t삭제 : c\t초기화 : v\t종료 : b\n", page + 1);
			Isclear = 0;
		}
		c = getch();	//문자를 입력받음
		char comment[6] = { '[', ']', 'z', 'x', 'c', 'v' };
		switch (c)
		{
		case '[':	//이전으로 넘어감
			if (page == 0) {	//page가 0이라면
				printf("마지막 페이지입니다.\n");
				continue;
			}
			else
			{
				page--;
				Isclear = 1;
				continue;
			}
		case ']':	//다음으로 넘어감
			if (file_count_func(folder_path) <= 25 * (page + 1)) {	//최대 파일 개수가 page + 1에 25를 곱한 값보다 작거나 같다면
				printf("더이상 넘길 수 없습니다.\n");
				continue;
			}
			else
			{
				page++;
				Isclear = 1;
				continue;
			}
		case 'z':	//일기를 만듦
			system("cls");
			printf("\t일기장을 만듭니다.\n\n\t주의 : 작성 중 프로그램을 끄지마세요!\n\n\t중간에 끄면 파일 작성이 안됩니다!\n\n");
			write_file();
			Isclear = 1;
			continue;
		case 'x':	//읽기
			printf("\n현재 페이지에서 읽고 싶은 파일 번호를 입력하시오 (1~25) (0 : 취소) : ");
			int input_number = 0;
			while (1)
			{
				scanf("%d", &input_number);
				if (input_number<= se_nu && input_number > 0) {	//만약 입력한 숫자가 폴더 내에 있는 파일 숫자보다 작거나 같다면
					file_read(input_number + 25 * page);	//파일을 읽는 함수 호출
					break;
				}
				else if (input_number == 0) {
					rewind(stdin);	//만약 숫자가 아닌 문자를 입력할 수 있어 입력 버퍼를 지운다.
					break;
				}
				else
				{
					printf("%d보다 같거나  작은 수(양수)를 입력해주세요. >> ", se_nu);
					continue;
				}
			}
			Isclear = 1;
			continue;
		case 'c':	//삭제
			remove_file(page, se_nu);
			Isclear = 1;
			continue;
		case 'v':	//초기화 
			page = 0;
			Isclear = 1;
			system("mode con cols=141 lines=40");
			continue;
		case 'b':	//종료
			return;
		default: //나머지
			continue;
		}
	}
}

int main(void) {
	char input_1;
	start_screen(&input_1);
	if (input_1 == 'y') {
		main_screen(0);
	}
	return 0;
}

void file_read(int file_number) {	//일기장 (파일)을 읽는 함수 
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
	printf("우선순위 : %d\n", f_s.prority);
	print_line();
	printf("제목 : %s\n", f_s.title);
	print_line();
	printf("내용 : %s\n", f_s.content);
	print_line();
	printf("%s\n", (f_s.Iscorrect == 0) ? "수정되지 않은 글입니다." : "수정된 글입니다.");	//(f_s.Iscorrect == 0)가 참이면 "수정되지 않은 글입니다."라는 문자열을 출력을 거짓이면 "수정된 글입니다."라는 문자열을 출력한다
	print_line();
	printf("\t%s : %c\t%s : %c\n", "나가기", 'o', "수정", 'p');
	char input_key;
	while (1)
	{
		input_key = getch();
		switch (input_key)
		{
		case 'o':	//수정에서 나가는 키
			return;
		case 'p':	//수정하는 키
			printf("수정을 합니다.\n");
			correct_file(file_number);
			return 0;
		}
	}
	return;
}

void correct_file(int file_number) {	//파일 수정 함수
	FILE *fp;
	struct date d;
	FILE_SAMPLE correct_f_s;
	char p[50];
	char correct_title[101];
	char correct_content[501];
	int correct_Number;
	int prority_number;
	int skip_count = 0;;
	strcpy(p, get_path_of_file(file_number));
	if ((fp = fopen(p, "rb")) == NULL) {
		printf("수정하려는 파일을 읽기를 실패하였습니다.\n");
		exit(1);
	}
	fread(&correct_f_s, sizeof(correct_f_s), 1, fp);
	fclose(fp);
	correct_Number = correct_f_s.Iscorrect;
	d = correct_f_s.file_crate_date;
	prority_number = correct_f_s.prority;
	printf("먼저 제목을 수정합니다. ( 처음 엔터 누르면 안넘어감. | 100자 이하 | 0 : 취소 )\n");
	printf("제목 >> ");
	fgets(correct_title, 100, stdin);
	while (correct_title[0] == '\n') fgets(correct_title, 100, stdin);	//만약 그냥 '\n'를 누르면 다시 입력해야함.
	correct_title[strlen(correct_title) - 1] = '\0';	//'\n'을 '\0'로 바꿈
	if (correct_title[0] == '0' && strlen(correct_title) == 1) {	//만약 문자열의 길이가 1이고 첫번째 자리에 '0'이라고 입력한다면
		strcpy(correct_title, correct_f_s.title);	//기존에 있던 문자열을 복사
		skip_count++;	//스킵 횟수를 + 1
	}
	print_line();
	printf("내용을 수정합니다. ( 처음 엔터 누르면 안넘어감. | 500자 이하 | 0 : 취소 )\n");
	printf("내용 >> ");
	fgets(correct_content, 500, stdin);
	while (correct_content[0] == '\n') fgets(correct_content, 500, stdin);
	correct_content[strlen(correct_content) - 1] = '\0';
	if (correct_content[0] == '0' && strlen(correct_content) == 1) {
		strcpy(correct_content, correct_f_s.content);
		skip_count++;
	}
	print_line();
	if ((fp = fopen(p, "wb")) == NULL) {
		printf("수정하려는 파일을 읽기를 실패하였습니다.\n");
		exit(1);
	}
	correct_f_s.file_crate_date = d;
	correct_f_s.Iscorrect = (skip_count == 2) ? correct_Number : 1;
	correct_f_s.prority = prority_number;
	strcpy(correct_f_s.title, correct_title);
	strcpy(correct_f_s.content, correct_content);
	fwrite(&correct_f_s, sizeof(correct_f_s), 1, fp);
	fclose(fp);
	return;
}
void print_line() {
	printf("\n");
	for (int i = 0; i < 141; i++) {
		printf("-");
	}
	printf("\n");
	return;
}
const char* get_path_of_file(int input) {	//파일 경로만들어주는 함수
	int file_total_number = file_count_func(folder_path);
	char path_for_file[50];
	strcpy(path_for_file, folder_path);
	strcat(path_for_file, "\\");
	strcat(path_for_file, get_file_name_func(folder_path, file_total_number, input));
	return path_for_file;
}

void remove_file(int page, int listNum) {	//파일 삭제 함수
	int input_int = 0;
	char input_char = { 0 };
	char path[50];
	short Isdone = 0;	//완료되었는지 여부
	char *f_n;
	FILE *fp;
	FILE_SAMPLE file_sample;
	printf("\n삭제하려는 파일의 번호를 입력해주세요. (0 : 취소)");
	while (Isdone == 0) {
		scanf("%d", &input_int);
		print_line();
		if (input_int <= listNum && input_int > 0) {
			strcpy(path, get_path_of_file(input_int + 25 * (page)));
			if ((fp = fopen(path, "rb")) == NULL) {
				printf("remove_file()\n파일을 삭제하려는 동안 오류가 발생하였습니다!\n");
				exit(1);
			}
			fread(&file_sample, sizeof(file_sample), 1, fp);
			fclose(fp);
			f_n = (char *)malloc((strlen(file_sample.title) + 1));	//f_n을 동적할당
			strcpy(f_n, file_sample.title);

			f_n[strlen(file_sample.title)] = '\0';
			printf("일기 제목이 \"%s\"맞습니까? (y/n) : ", f_n);
			free(f_n);
			short i = 0;
			while (i == 0)	//y나 n을 누를 때까지 반복
			{
				input_char = getch();
				if (input_char == 'y') {
					char path[50];
					strcpy(path, get_path_of_file(input_int));
					int result = remove(path);
					if (result == 0) {	//파일 삭제 성공시
						array_setup(input_int);
						printf("\n%s\n파일을 삭제 성공했습니다...\n", path);
						printf("메인화면으로 돌아갑니다...\n");
						Sleep(1500);
						Isdone = 1;
						return;
					}
					else if (result == -1)	//파일 삭제 실패시
					{
						printf("\n%s\n파일을 삭제 실패했습니다...\n", path);
						printf("메인화면으로 돌아갑니다...\n");
						Sleep(1500);
						Isdone = 1;
						return;
					}
				}
				else if (input_char == 'n') {
					printf("\n번호를 다시 입력해주십시오. >> ");
					i = 1;
				}
			}
		}
		else if (input_int == 0)
		{
			printf("다시 돌아갑니다...\n");
			rewind(stdin);
			return;
		}
		else {
			printf("%d보다 같거나  작은 수(양수)를 입력해주세요 >> ", listNum);
		}
	}
	return;
}

int ditect_multiple_file_name(char *txt_file_name) {//파일 중복 검출하는 함수
	struct _finddata_t fd;
	long handle;
	int r = 1;
	int result_int = -1;	//처음 result_int는 -1
	char path_f[100];
	strcpy(path_f, folder_path);
	strcat(path_f, ".\\*.*");
	FILE *fp;
	FILE_SAMPLE f_s;
	handle = _findfirst(path_f, &fd);
	if (handle == -1) {
		printf("오류\n파일 없음\n");
		return;
	}
	while (r != -1) {
		if (strcmp(fd.name, ".") != 0 && strcmp(fd.name, "..") != 0) {
			if (strcmp(txt_file_name, fd.name) == 0) {	//파일명이 매개변수 txt_file_name과 같다면
				result_int = 0;	//result_int는 0
			}
		}
		r = _findnext(handle, &fd);	//다음 파일로
	}
	_findclose(handle);	//닫음
	return result_int;
}

void array_setup(int delete_file_number) {//우선 순위를 다시 정렬시킴. 삭제할 때 쓰임.
	FILE *fp;
	struct date d;
	FILE_SAMPLE f_s;
	int I_s = 0;
	char p[50];
	int max_file_count = file_count_func(folder_path) + 1;	//삭제된 후이니 지금의 파일 개수를 1더함
	if (delete_file_number != max_file_count) { //만약 삭제된 파일의 우선 순위가 최대 파일 개수가 아니라면 ////////////////////////////////////////////////
		for (int i = delete_file_number + 1; i <= max_file_count; i++) {
			int prority_c;
			char title_c[101];
			char content_c[501];
			strcpy(p, get_path_of_file(i));
			if ((fp = fopen(p, "rb")) == NULL) {
				printf("정렬하려는 파일을 읽기 실패하였습니다.\n");
				exit(1);
			}
			fread(&f_s, sizeof(f_s), 1, fp);
			fclose(fp);
			prority_c = f_s.prority - 1;
			strcpy(title_c, f_s.title);
			strcpy(content_c, f_s.content);
			I_s = f_s.Iscorrect;
			d = f_s.file_crate_date;
			if ((fp = fopen(p, "wb")) == NULL) {
				printf("정렬하려는 파일을 읽기 실패하였습니다.\n");
				exit(1);
			}
			f_s.file_crate_date = d;
			f_s.prority = prority_c;
			strcpy(f_s.title, title_c);
			strcpy(f_s.content, content_c);
			f_s.Iscorrect = I_s;
			fwrite(&f_s, sizeof(f_s), 1, fp);
			fclose(fp);
		}
	}
}

void write_file() {	//일기장(파일) 생성하는 함수
	struct tm* t;
	time_t base = time(NULL);
	t = localtime(&base);
	int cut = 1;
	char file_name[10];
	char write_title[101];
	char write_content[501];
	while (cut != 0)
	{
		srand(time(NULL));
		unsigned int random_title = (rand() % 50000) + 10000;//파일 이름을 난수로 정할거임. 최대 50000번 작성 가능
		sprintf(file_name, "%d", random_title);
		strcat(file_name, ".txt");
		int Ismultiple = ditect_multiple_file_name(file_name);
		if (Ismultiple == 0) {
			if (cut > 6) {
				printf("5번 이상 실행했습니다.\n다시 메인 화면으로 돌아갑니다.\n");
				Sleep(1500);
				main_screen(0);
			}
			printf("파일명이 중복인 부분이 확인되었습니다.\n다시 난수를 다시 생성합니다.\n");
			Sleep(1000);
			cut++;
		}
		else if (Ismultiple == -1) {
			cut = 0;
		}
	}
	FILE *fp;
	FILE_SAMPLE write_f_s;
	if (file_count_func(folder_path) == -1) {
		write_f_s.prority = 1;
	}
	else
	{
		write_f_s.prority = file_count_func(folder_path) + 1;
	}
	printf("제목을 입력해주세요.( 처음 엔터 누르면 안넘어감. | 100자 이하 | 0 : 메인화면으로 )\n제목 : ");
	fgets(write_title, 100, stdin);
	while (write_title[0] == '\n') fgets(write_title, 100, stdin);
	if (write_title[0] == '0') return;
	write_title[strlen(write_title) - 1] = '\0';
	strcpy(write_f_s.title, write_title);
	print_line();
	printf("\n내용을 입력해주세요.( 처음 엔터 누르면 안넘어감. | 500자 이하 )\n내용 : ");
	fgets(write_content, 500, stdin);
	while (write_content[0] == '\n') fgets(write_content, 500, stdin);
	write_content[strlen(write_content) - 1] = '\0';
	strcpy(write_f_s.content, write_content);
	int i;
	char path_[50];
	write_f_s.Iscorrect = 0;
	write_f_s.file_crate_date.year = t->tm_year + 1900;
	write_f_s.file_crate_date.month = t->tm_mon + 1;
	write_f_s.file_crate_date.day = t->tm_mday;
	strcpy(path_, folder_path);
	strcat(path_, "\\");
	strcat(path_, file_name);
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

	Sleep(500);//딜레이를 줌 (1.5초)
	return;
}
