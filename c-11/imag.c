#include <stdio.h>

typedef struct complex {
	double real;
	double imag;
} Complex;

Complex complex_sum(Complex a, Complex b);
void get_input(Complex *px);
int main(void) {
	Complex a, b,z;

	printf("ù��°�� ���Ҽ��� �Է��Ͻÿ�(a, b) : "); 
	get_input(&a);
	printf("�ι�°�� ���Ҽ��� �Է��Ͻÿ�(a, b) : ");
	get_input(&b);

	z = complex_sum(a, b);
	printf("��� : %lf + lf\n", z.real, z.imag);
	return 0;
}
void get_input(Complex *px) {
	scanf("%lf %lf", px->real, px->imag);
}

Complex complex_sum(Complex a, Complex b) {
	Complex z;
	z.real = a.real + b.real;
	z.imag = a.imag + b.imag;

	return z;
}