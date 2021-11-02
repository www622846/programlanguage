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
		printf("�й� : %d\n", s.id.stu_num);
		printf("�̸� : %s\n", s.name);
		break;
	case REG_NUM:
		printf("�ֹε�Ϲ�ȣ : %s\n", s.id.reg_num);
		printf("�̸� : %s\n", s.name);
		break;
	default:
		printf("Ÿ�� ����\n");
		break;
	}
}

int main(void) {
	struct student s1, s2;
	s1.type = STU_NUM;
	s1.id.stu_num = 20070001;
	strcpy(s1.name, "ȫ�浿");
	s2.type = REG_NUM;
	strcpy(s2.id.reg_num," 000000-000000") ;
	strcpy(s2.name, "��ö��");

	print_student(s1);
	print_student(s2);

	return 0;
}