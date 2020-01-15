#include <stdio.h> 
#include <iostream>
using namespace std;

bool error = 0;

double CalcWithMasm(double a, double b)
{
	int status;

	const int c10 = 10;
	const int c20 = -20;

	double result;

	__asm {
		finit;								инициализация сопроцессора
		fld qword ptr[b];					b
		fld qword ptr[a];					a, b
		fcom st(1);							сравниваем a и b
		fstsw status;						сохраняем регистр флагов сопроцессора
		mov ah, byte ptr[status + 1]
		sahf;								записываем в регистр флагов процессора
		ja a_bigger;						переход, если a больше
		jb b_bigger;						переход, если b больше
		;									если равны
		fild c20;							-20, a, b
		jmp	endcalc;
	a_bigger:
		ftst;								сравнение a с 0
			fstsw status;					сохраняем регистр флагов сопроцессора
			mov ah, byte ptr[status + 1]
			sahf;							записываем в регистр флагов процессора
			je error;						переход если a = 0
			fdivp st(1), st;				b / a
			fild c10;						4, b / a
			faddp st(1), st;				b / a + 10
			jmp	endcalc;
	b_bigger:;								(b - a) / b, если a < b
		fldz;								0, a, b
		fcomp st(2);						сравнение b с 0
		fstsw status;						сохраняем регистр флагов сопроцессора
		mov ah, byte ptr[status + 1];
			 sahf;							записываем в регистр флагов процессора
				 je error;					переход если b = 0
				 fsubp st(1), st;
			 fld b
				 fdivp st(1), st;
			 jmp	endcalc;
		 error:
			 fldz;							формируем результат ошибки
				 endcalc :
			 fstp res;						сохранение результата
	}

	return result;
}

double CalcWithCpp(double a, double b)
{
	if (a > b) {
		return ((b / a) + 10);
	}
	else if (a < b) {
		return ((b - a) / b);
	}
	else {
		return -20;
	}
}

int main()
{
	// функция вычисления выражения
	// * (b/a) + 10, если a > b
	// * -20, если a = b
	// * (b - a)/b, если a < b

	setlocale(LC_CTYPE, "rus");
	printf("Задание:\n");
	printf("Вычисление выражения с условием:\n* (b/a) + 10, если a > b\n* -20, если a = b\n* (b - a)/b, если a < b\n\n");

	double a, b;

	printf("Введите a = ");
	cin >> a;

	printf("Введите b = ");
	cin >> b;
	printf("\n");

	double result = CalcWithMasm(a, b);
	if (error == 1) {
		cout << "Ошибка" << endl;
	}
	else {
		printf("Результат на MASM: ");
		printf("%f", result);

		printf("\nРезультат на C++: ");
		printf("%f\n", CalcWithCpp(a, b));
	}

	printf("\n");
	system("PAUSE");
	return 0;
}