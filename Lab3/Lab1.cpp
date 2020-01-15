#include <stdio.h>
#include <iostream>
#include <locale.h> 
using namespace std;

int CalcWithMasm(int arr[], int size, int b, int d)
{
	int result = 0;

	__asm {
		xor	esi, esi;				подготовим регистр индекса в массиве
		xor	edi, edi;				счётчик количества элементов
		mov	ebx, arr;				указывает на начало массива
		mov ecx, size;				счётчик цикла по всем элементам массива
		jcxz	exit_1;				завершить, если длина массива 0
		begin_loop:
		mov	eax, [ebx + esi * 4];	определяем текущий элемент
			cmp	eax, 0;				сравниваем текущий элемент с нулём
			jle end_loop;			определяем положительный ли(больше нуля)
			mov	edx, d;				подготовка сравнения с d
			cmp	eax, edx;			сравнение a[i] и d
			jg end_loop;			если больше, то завершаем цикл
			mov	edx, b;				подготовка сравнения с b
			cmp	eax, edx;			сравнение a[i] и b
			jl end_loop;			если меньше, то завершаем цикл
			inc	edi;				элемент удовлетворяет условию, увеличиваем счётчик
			end_loop :
		inc	esi;					переходим к следующему элементу
			loop begin_loop;		повторяем цикл для всех элементов массива
			exit_1 :
		mov	result, edi;			возвращаем количество элементов
	}

	return result;
}

int CalcWithCpp(int arr[], int size, int b, int d)
{
	int counter = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > 0 &&
			arr[i] >= b &&
			arr[i] <= d)
			counter++;
	}

	return counter;
}

int main()
{
	// В одномерном массиве A = {a[i]} целых чисел вычислить количество положительных элементов массива, 
	// которые удовлетворяют условию: b <= a[i] <= d.

	setlocale(LC_CTYPE, "rus");
	printf("Задание:\n");
	printf("В одномерном массиве A={a[i]} целых чисел вычислить количество положительных элементов массива,\n");
	printf("которые удовлетворяют условию: b <= a[i] <= d.\n\n");

	int size;
	do
	{
		cout << "Введите размер массива не больше 10: " << endl;
		cin >> size;
	} while (size < 0 || size > 10);
	printf("\n");

	cout << "Введите массив: " << endl;
	int arr[10];
	for (int i = 0; i < size; i++)
		cin >> arr[i];
	printf("\n");

	cout << "Введите условия для задачи: " << endl;
	int b, d;
	do
	{
		cout << "b = ";
		cin >> b;

		cout << "d = ";
		cin >> d;
		printf("\n");

		if (d < b)
		{
			cout << "Ошибка! d не может быть меньше b." << endl;
			cout << "Введите значение снова: " << endl;
		}
	} while (d < b);
	printf("\n");

	int res = CalcWithMasm(arr, size, b, d);

	printf("Количество элементов больше или равно b, но меньше или равно d: ");
	printf("\n");

	printf("Ассемблер: ");
	printf("%d", res);
	printf("\n");

	printf("C++: ");
	printf("%d", CalcWithCpp(arr, size, b, d));
	printf("\n");

	system("PAUSE");
	return 0;
}