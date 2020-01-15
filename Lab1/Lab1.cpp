#include <stdio.h>
#include <iostream>
using namespace std;

int CalcWithMasm(int a, int d, int c)
{
	int result = 0;

	__asm {
		mov	eax, a
		mov	ebx, d
		mov	ecx, c
		imul eax;			<edx:eax> = a * a
		shl eax, 1;			2 * a * a
		dec	eax;			<eax> = 2 * a * a - l
		push eax;			в стеке 2 * a * a - 1
		shr ebx, 1;			d / 2
		neg ebx;			-(d / 2)
		add ebx, 33;		+33
		add ebx, ecx;
		mov eax, ebx;		(c - d / 2 + 33)
			pop ebx;		(2 * a * a - 1)
			cdq;			<eax> = > <edx:eax>
			idiv ebx;
		mov result, eax;	result = eax
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	printf("Задание: (c - d/2 + 33)/(2 * a * a - 1)\n\n");

	int a, d, c;
	printf("a = ");
	cin >> a;
	printf("c = ");
	cin >> c;
	printf("d = ");
	cin >> d;
	printf("\n");

	int resMasm = CalcWithMasm(a, d, c);
	printf("Результат на MASM: %d\n", resMasm);

	int resCpp = (c - d / 2 + 33) / (2 * a* a - 1);
	printf("Результат на C++: %d\n", resCpp);

	printf("\n");
	system("PAUSE");
	return 0;
}