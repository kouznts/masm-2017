#include <stdio.h>
#include <iostream>
using namespace std;

bool error = 0;

int CalcWithMasm(int a, int b)
{
	int result = 0;

	__asm {
		mov   eax, -20;			<eax> = -20;
		mov	ecx, a;				<ecx> = a
			mov	ebx, b;			<ebx> = b
			cmp	ecx, ebx;		сравнение a и b
			jg	l_bigger;		переход, если a > b
			jl	l_smaller;		переход, если a < b
			mov result, eax;	result = eax
			jmp	end_1;			переход в конец программы
			l_bigger :
		or ecx, ecx;			сравнение a и 0
			je	error1;			ошибка деления на ноль
			mov	eax, ebx;		<eax> = b
			cdq;				подготовка деления <edx:eax> = a
			idiv ecx;			<eax> = b / a
			add	eax, 10;		<eax> = b / a + 10
			mov result, eax;	result = eax
			jmp	end_1;			переход в конец программы
			l_smaller :
		or ebx, ebx;			сравнение b и 0
			je error1;			ошибка деления на ноль
			mov	eax, ebx;		<eax> = b
			sub	eax, ecx;		<eax> = b – a
			cdq;				подготовка деления <edx:eax>
			idiv ebx;			<eax> = (b – a) / b
			mov result, eax;	result = eax
			jmp	end_1;			переход в конец программы
			error1 :
		mov error, 1;
	end_1:
	}

	return result;
}

int CalcWithCpp(int a, int b)
{
	if (a > b) {
		return ((b / a) + 10);
	}
	else if (a < b) {
		return ((b - a) / b);
	}
	else {
		return (-20);
	}
}

int main()
{
	// функция вычисления выражения
	// * (b/a) + 10, если a > b
	// * -20, е-+сли a = b
	// * (b - a)/b, если a < b

	setlocale(LC_CTYPE, "rus");
	printf("Задание:\n");
	printf("Вычисление выражения с условием:\n* (b/a) + 10, если a > b\n* -20, если a = b\n* (b - a)/b, если a < b\n\n");

	int a, b;

	printf("Введите a = ");
	cin >> a;

	printf("Введите b = ");
	cin >> b;

	int res = CalcWithMasm(a, b);

	if (error == 1) {
		cout << "Ошибка" << endl;
	}
	else {
		printf("\nРезультат на MASM: ");
		printf("%d", res);

		printf("\nРезультат на C++: ");
		printf("%d\n", CalcWithCpp(a, b));
	}

	printf("\n\n");
	system("PAUSE");
	return 0;
}