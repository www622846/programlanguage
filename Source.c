#include <stdio.h>//printf(), scanf()�� �� �� �ְ� ����
#include <math.h>//sqrt()�� �� �� �ְ� ����
#include <string.h>//���ڿ� ���̸� �� �� ���ִ�strlen(), ���ڿ� �񱳰� ���� strcmp()���� ���ؼ� �ʿ���

char data[8][10] = { "������ü", "��", "����", "�����", "�����ü", "������ü","�ﰢ��", "���簢��" };//8���� ���ڿ�
char c[] = "";//������ ���� �޴� ����
int check = 0;
int mm(char in); //���Ǹ� �����ϴ� �Լ�
void reset();//�ٽ� ������ �� ����� �Լ�
char stringtochar(char string[]);//���ڿ��� a,b,c,d...�� �ٲٴ��Լ�
void select_(char ch);//������ ��ü������ �����ִ� �Լ�

int main(void) {
	if (check == 0) {
		printf("\t\tVolume Program (���� ���α׷�)\n\n");
		check = 1;
	}
	printf("���Ǹ� ���ϰ� ���� ��ü������ �Է��ϼ���. [�̸��� �ҹ��� �Ѵ� �Է°���]\n(������ü : a | �� : b | ���� : c | �����  : d | �����ü : e | ������ü : f | �ﰢ�� : g | ���簢�� : h) >> ");
	scanf("%s", &c);
	if (strlen(c) > 1) {
		mm(stringtochar(c));
	}
	else
	{
		mm(c[0]);
	}
	reset();
	return 0;
}
void reset() {
	while (1)
	{
		printf("\n\n\t�ٽ� �Է��Ͻðڽ��ϱ�?\n\n\t�� : Y\t�ƴϿ� : N\n>> ");
		scanf("%s", &c);
		if (c[0] == 'Y' || c[0] == 'y') {
			printf("\n===========================================================================\n\n");
			main();
			break;
		}
		else if (c[0] == 'N' || c[0] == 'n') {
			printf("\t�����մϴ�...\n\n");
			break;
		}
	}
}
int mm(char in) {
	double x, y, z, result = 0;//�Է°� 3���� �����
	switch (in)
	{
	case 'a'://������ü
		select_('a');
		printf("�� ���� ���̸� �Է��ϼ��� : ");
		scanf("%lf", &x);
		result = x * x * x;
		printf("������ü");
		break;
	case 'b'://��
		select_('b');
		printf("�������� �Է��ϼ��� : ");
		scanf("%lf", &x);
		result = x * x * x * 3.14 * 4.0 / 3.0;
		printf("��");
		break;
	case 'c'://����
		select_('c');
		printf("������ ���̸� �Է��ϼ��� : ");
		scanf("%lf %lf", &x, &y);
		result = x * x  * 3.14 * y * 1.0 / 3.0;
		printf("����");
		break;
	case 'd'://�����
		select_('d');
		printf("������ ���̸� �Է��ϼ��� : ");
		scanf("%lf %lf", &x, &y);
		result = x * x  * 3.14 * y;
		printf("�����");
		break;
	case 'e'://�����ü
		select_('e');
		printf("�� ���� ���̸� �Է��ϼ��� : ");
		scanf("%lf", &x);
		result = sqrt(2) / 12.0 * x *x * x;
		printf("�����ü");
		break;
	case 'f'://������ü
		select_('f');
		printf("���� ���� ���̸� �Է��ϼ��� : ");
		scanf("%lf %lf %lf", &x, &y, &z);
		result = x * y * z;
		printf("������ü");
		break;
	case 'g'://�ﰢ��
		select_('g');
		printf("�غ��� ���� ���̸� �Է��ϼ��� : ");
		scanf("%lf %lf", &x, &y);
		result = x * y * 1.0 / 3.0;
		printf("�ﰢ��");
		break;
	case 'h'://���簢��
		select_('h');
		printf("�غ��� ���� ���̸� �Է��ϼ��� : ");
		scanf("%lf %lf", &x, &y);
		result = x * x  * y * 1.0 / 3.0;
		printf("���簢��");
		break;
	default :
		printf("�ٽ� �Է����ּ���.\n");
		main();
		break;
	}
	printf("�� ���� : %lf\n", result);
	return 0;
}
void select_(char ch) {
	printf("%s(��)�� �����ϼ̽��ϴ�.\n", data[(int)(ch - 'a')]);
	printf("%s | ", data[(int)(ch - 'a')]);
}
char stringtochar(char string[]) {
	char rec;
	int i, count;
	count = 0;
	for (i = 0; i < 8; i++) {
		if (strcmp(data[i], string) == 0) {
			count++;
			rec = 97 + i;
			return rec;
		}
	}
	if (count == 0) {
		printf("�ٽ� �Է����ּ���.\n");
		main();
	}
}