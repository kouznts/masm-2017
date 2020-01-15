#include <stdio.h>
#include <iostream>
using namespace std;

double CalcWithMasm(double x)
{
	double result;

	int c2 = -2;
	int c3 = 3;

	__asm {
		finit;
		fld x;
		fld x;
		fmulp st(1), st;
		fild c2;
		fmulp st(1), st;
		fild c3;
		faddp st(1), st;
		fstp result;
	}

	return result;
}

double CalcWithCpp(double x)
{
	return 3 - 2 * x * x;
}

int main()
{
	// y = 3 - 2 * x * x

	setlocale(LC_CTYPE, "rus");
	printf("Задание:\n");
	printf("вычислить выражения y = 3 - 2 * x * x с шагом 0,1\n");
	printf("\n");

	printf("\t\t\tТаблица ответов");
	printf("\n");
	printf("==================================================================\n");

	cout << "  " << " № " << "\t\t" << " x " << "\t\t" << " АССЕМБЛЕР" << "\t\t" << "C++";
	printf("\n");
	printf("==================================================================\n");

	int counter = 1;
	for (double i = -1; i <= 3.1; i = i + 0.1)
	{
		printf("   %d \t\t% 0.1f \t\t % 0.4f \t\t% 0.4f", counter++, i, CalcWithMasm(i), CalcWithCpp(i));
		printf("\n");
	}
	printf("==================================================================\n\n");

	system("PAUSE");
	return 0;
}