# Архитектура ЭВМ и ВС (2017)

## Лабораторная работа №1. Арифметические и логические команды
1)	В программе необходимо реализовать функцию вычисления целочисленного выражения на встроенном ассемблере MASM в среде Microsoft Visual Studio на языке C++.
2)	Значения переменных передаются в качестве параметров функции.
3)	Результат выводить в консольном приложении (проект консольное приложение Win32).
4)	В программе реализовать ввод переменных из командной строки и вывод результата на экран.
5)	Все параметры функции 32 битные числа (знаковые и беззнаковые).
6)	Первые строки функции вычисления выражения заносят значения аргументов функции в соответствующие регистры.
7)	Где необходимо реализовать проверки вводимых данных и вычисления отдельных операций. Например, проверка деления на 0.
8)	В качестве комментария к каждой строке необходимо указать, какой промежуточный результат, в каком регистре формируется.
9)	По возможности использовать команды сдвига.

## Лабораторная работа № 2
1)	В программе необходимо реализовать функцию вычисления заданного условного целочисленного выражения, используя команды сравнения, условного и безусловного переходов на встроенном ассемблере.
2)	Результат X – целочисленный, возвращается из функции регистре eax.
3)	Значения переменных передаются в качестве параметров функции.
4)	В программе реализовать вывод результата на экран.
5)	Все параметры функции 32 битные числа.
6)	Проверку деления на 0 реализовать также на встроенном ассемблере.
7)	В качестве комментария к каждой строке необходимо указать, какой промежуточный результат, в каком регистре формируется.
8)	По возможности использовать команды сдвига.

## Лабораторная работа № 3
1)	В программе необходимо реализовать функцию обработки элементов массива используя команды сравнения, переходов и циклов на встроенном ассемблере.
2)	Результат – целочисленный, возвращается из функции регистре eax.
3)	Массив и количество элементов передаются в качестве параметров функции.
4)	В программе реализовать вывод результата на экран.
5)	В качестве комментария к каждой строке необходимо указать, какое действие выполняет команда относительно массива.

## Лабораторная работа № 4
1)	В программе необходимо реализовать функцию вычисления заданного условного выражения на языке ассемблера с использованием команд арифметического сопроцессора.
2)	Значения переменных передаются в качестве параметров функции.
3)	В программе реализовать вывод результата на экран.
4)	Все параметры функции имеют тип double.
5)	Проверку деления на 0 реализовать также на встроенном ассемблере.
6)	В качестве комментария к каждой строке необходимо указать, какой промежуточный результат, в каком регистре формируется.
7)	В качестве комментария к строкам, содержащим команды сопроцессора необходимо указать состояние регистров сопроцессора.
8)	Результат можно возвращать из функции в вершине стека сопроцессора.

## Лабораторная работа № 5
1)	В программе необходимо реализовать функцию определения значения некоторой элементарной функции  , зависящей от аргумента   на языке ассемблера с использованием команд арифметического сопроцессора.
2)	Значения переменных передаются в качестве параметров функции.
3)	Составить таблицу значений функции на указанном отрезке с шагом h = 0,1.
4)	Номер вычисления №, значения x и f(x) вывести для контроля на экран.
5)	Все параметры функции имеют тип double.
6)	Проверку деления на 0 реализовать также на встроенном ассемблере.
7)	В качестве комментария к каждой строке необходимо указать, какой промежуточный результат, в каком регистре формируется.
8)	В качестве комментария к строкам, содержащим команды сопроцессора необходимо указать состояние регистров сопроцессора.
9)	Результат можно возвращать из функции в вершине стека сопроцессора.

## Лабораторная работа № 6
1)	В программе необходимо реализовать функцию определения значения некоторой элементарной функции y, зависящей от аргумента x на языке ассемблера с использованием команд арифметического сопроцессора.
2)	Функция вычисляется в виде суммы ряда. Вычисления прекращаются если |Sk+1 - Sk| <= eps, где Sk+1 – последующий член ряда; Sk - предыдущий член ряда. Кроме того, на случай плохой сходимости следует ограничить количество слагаемых сверху некоторым наперёд заданным N, т.е. выход их вычислительной процедуры может произойти не по условию |Sk+1 - Sk| <= eps, а по условию k > N. Значение функции и количество итераций вывести для контроля на экран.
3)	Значение параметров x, eps и N передаются в качестве аргументов функции.
4)	В программе необходимо также реализовать функцию вычисления значения элементарной функции на основе аналитического выражения, также с использованием команд арифметического сопроцессора. Значение функции вывести для контроля на экран. 
5)	Необходимо определить достигнутую погрешность, вычислив отклонение аналитического значения от значения, вычисленного с помощью ряда. Значение погрешности также вывести для контроля на экран.
6)	В качестве комментария к строкам, содержащим команды сопроцессора необходимо указать состояние регистров сопроцессора.
