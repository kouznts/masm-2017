#include <stdio.h> 
#include <iostream>
#include <conio.h>
using namespace std;

double CalcWithMasm(double x, int N)
{
	double fact = 2.0;
	double funct = 0.0;

	__asm {
		mov ecx, 0;
		finit;
		fld x;					x
			fld st(0);			x				x
			Cycle :
		fmul x;					x * x			x
			fmul x;				x * x * x		x
			fdiv fact;			x * x * x / 2	x
			fld fact;			2				x * x * x / 2		x
			fld1;				1				2					x * x * x / 2		x
			fadd;				3				1					2					x * x * x / 2
			fdiv st(1), st(0);	1 / 3			3					1					2
			fld1;
		fadd;
		fstp fact;
		fadd st(1), st(0);
		; fld st(0);
		inc ecx
			cmp ecx, N
			jne Cycle
			fstp fact;
		fstp funct;
	}
	return funct;
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	printf("Задание:\n* Определить значение sh x.\n\n");

	double x;
	printf("Введите значение x: ");
	cin >> x;

	int N;
	do {
		printf("Введите количество итераций (количество членов в ряду): ");
		cin >> N;
	} while (N < 1);
	printf("\n");

	printf("\n\t\t\tТаблица ответов");
	printf("\n");
	printf("=========================================================================\n");

	std::cout << "  " << " № " << "\t" << " Ассемблер" << "\t\t " << "C++" << "\t\t\t " << "погрешность";
	printf("\n");
	printf("=========================================================================\n");

	for (int i = 1; i <= N; i++)
	{
		printf("   %d \t %9.12f \t %9.12f \t %9.12f", i, CalcWithMasm(x, i), sinh(x), abs(sinh(x) - CalcWithMasm(x, i)));
		printf("\n");
	}
	printf("=========================================================================\n\n");

	system("PAUSE");
	return 0;
}