#include <stdio.h>
#include <string.h>
#define STU_NUM 1
#define REG_NUM 2

struct student {
	int type;
	union 
	{
		int stu_num;
		char reg_num[15];
	} id;
	char name[20];
};

void print_student(struct student s) {
	switch (s.type)
	{
	case STU_NUM:
		printf("학번 : %d\n", s.id.stu_num);
		printf("이름 : %s\n", s.name);
		break;
	case REG_NUM:
		printf("주민등록번호 : %s\n", s.id.reg_num);
		printf("이름 : %s\n", s.name);
		break;
	default:
		printf("타입 오류\n");
		break;
	}
}

int main(void) {
	struct student s1, s2;
	s1.type = STU_NUM;
	s1.id.stu_num = 20070001;
	strcpy(s1.name, "홍길동");
	s2.type = REG_NUM;
	strcpy(s2.id.reg_num," 000000-000000") ;
	strcpy(s2.name, "김철수");

	print_student(s1);
	print_student(s2);

	return 0;
}