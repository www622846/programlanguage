#include <stdio.h>
#include  <stdlib.h>
#define SIZE 20

int main(void) {
	FILE *fp = NULL;
	char *name[3] = { "ȫ�浿", "�̼���" , "�庸��" };
	char outname[20];
	int num, i;
	double korean, math;
	korean = 0.0;
	math = 0.0;
	if ((fp = fopen("test.txt", "w")) == NULL) {
		printf("�߸��� �Է�\n");
		exit(1);
	}

	for (i = 0; i < 3; i++) {
		korean = 90.0 + i;
		math = 80.0 + i;
		num = i;
		printf("%d %s %.2lf %.2lf\n", i, name[i], korean, math);
		fprintf(fp,"%d %s %.2lf %.2lf\n", i, name[i], korean, math);
	}
	fclose(fp);

	if ((fp = fopen("test.txt", "r")) == NULL) {
		printf("�߸��� �Է� \n");
		exit(1);
	}
	printf("�̸�	���\n");
	while (1) {
		fscanf(fp, "%d %s %f %f\n", &num, outname, &korean, &math);
		printf("%d %s %.2lf\n", num, outname, (korean + math) / 2);
		if (feof(fp)) { break; }//���̸� �ߴ�
	}
	fclose(fp);
	return 0;
}