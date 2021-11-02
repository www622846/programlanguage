#include <stdio.h>

typedef struct complex {
	double real;
	double imag;
} Complex;

Complex complex_sum(Complex a, Complex b);
void get_input(Complex *px);
int main(void) {
	Complex a, b,z;

	printf("첫번째의 복소수를 입력하시오(a, b) : "); 
	get_input(&a);
	printf("두번째의 복소수를 입력하시오(a, b) : ");
	get_input(&b);

	z = complex_sum(a, b);
	printf("결과 : %lf + lf\n", z.real, z.imag);
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