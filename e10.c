//С клавиатуры вводится символьная строка, состоящая из слов, разделенных пробелами. Определить максимальное и минимальное слова и их номера в строке. Если таких слов несколько - взять первые из них. Вывести на печать исходную строку, найденный слова и их номера

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(){
	float maxl=-INFINITY, minl=INFINITY;
	char A[500], *maxw, *minw;
	printf("Введите символьную строку:\n");
	gets(A);
	puts(A);
	char *b = strtok(A, " \n");
	int i=1, iM, im;
	while (b != NULL){
		float l = strlen(b);
		if(l<minl){
			minl=l;
			minw=b;
			im=i;}
		if(l>maxl){
			maxl=l;
			maxw=b;
			iM=i;}
		i++;
		b = strtok(NULL, " \n");}
	printf("Максимальное слово - %s (%d)\nМинимальное слово - %s (%d)\n", maxw, iM, minw, im);
	return 0;}

/*
#include <stdio.h>: Подключение стандартной библиотеки для ввода/вывода (функции printf, gets, puts).
#include <stdlib.h>: Подключение стандартной библиотеки (в данной программе не используется, можно убрать).
#include <string.h>: Подключение библиотеки для работы со строками (функции strlen, strtok).
#include <math.h>: Подключение библиотеки математических функций (используется для INFINITY).
Функция main — точка входа в программу.
Инициализация переменных
float maxl = -INFINITY: Переменная для хранения длины самого длинного слова. Изначально установлена в -INFINITY (математическая отрицательная бесконечность, чтобы любое значение было больше).
float minl = INFINITY: Переменная для хранения длины самого короткого слова. Изначально установлена в INFINITY (математическая положительная бесконечность, чтобы любое значение было меньше).
char A[500]: Массив символов длиной 500 для хранения введенной строки.
char *maxw: Указатель для хранения самого длинного слова.
char *minw: Указатель для хранения самого короткого слова.
Ввод строки
printf: Вывод приглашения для ввода строки.
gets(A): Считывает строку, введенную пользователем, и сохраняет ее в массив A. Важно: использование gets небезопасно, так как функция не проверяет длину вводимой строки. Лучше использовать fgets.
puts(A): Выводит введенную строку на экран.
Разделение строки на слова
strtok(A, " \n"): Функция strtok делит строку A на слова, используя пробел (" ") и символ новой строки ("\n") в качестве разделителей.
Возвращает указатель на первое слово строки.
Если слов больше нет, возвращает NULL.
int i = 1: Счетчик (i) для отслеживания номера текущего слова в строке. Начинается с 1.
int iM, im: Переменные для хранения номеров самого длинного (iM) и самого короткого (im) слов.
Цикл обработки слов
Цикл выполняется, пока b содержит указатель на очередное слово (т.е. пока есть слова для обработки).
Определение длины текущего слова
strlen(b): Вычисляет длину текущего слова (количество символов).
Результат сохраняется в переменной l (тип float).
Проверка на минимальное слово
if (l < minl): Проверяется, является ли длина текущего слова l меньше текущего минимального значения minl.
Если условие выполняется:
minl = l: Обновляется значение минимальной длины.
minw = b: Указатель minw теперь указывает на текущее слово (самое короткое на данный момент).
im = i: Сохраняется номер текущего слова i (чтобы знать, какое из слов является самым коротким).
Проверка на максимальное слово
if (l > maxl): Проверяется, является ли длина текущего слова l больше текущего максимального значения maxl.
Если условие выполняется:
maxl = l: Обновляется значение максимальной длины.
maxw = b: Указатель maxw теперь указывает на текущее слово (самое длинное на данный момент).
iM = i: Сохраняется номер текущего слова i (чтобы знать, какое из слов является самым длинным).
Переход к следующему слову
i++: Увеличивается счетчик слов (переход к следующему слову).
strtok(NULL, " \n"): Функция strtok вызывается снова для получения следующего слова. Если слов больше нет, возвращается NULL, и цикл завершается.
Вывод результатовprintf: Выводит результаты:
maxw: Самое длинное слово.
iM: Номер самого длинного слова.
minw: Самое короткое слово.
im: Номер самого короткого слова.
*/