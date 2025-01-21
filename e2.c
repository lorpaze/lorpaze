//Дана матрица A(n,m), n≤15,m≤10. Поменять местами строку, содержащую минимальную сумму элементов, и строку, содержащую максимальную сумму элементов. Если таких строк несколько – использовать первые найденные. Вывести на консоль исходную матрицу, номера найденных строк и их суммы, а также полученную матрицу.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
int main(){
	srand(time(NULL));
	int n, m, mmax=10, nmax=15, s=0, imax, imin;
	float max=-INFINITY, min=INFINITY;
	printf("Введите количество строк и столбцов: ");
	scanf("%d %d", &n, &m);
	if(n>nmax || n<0 || m>mmax || m<0){
		printf("Oшибка ввода!");
		return 0;}
	float A[n][m];
	printf("Исходная матрица:\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			A[i][j]=rand()%21-10;}}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%4.f", A[i][j]);
		}printf("\n");}
	//
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			s+=A[i][j];}
		if(s>max){
			max=s;
			imax=i;}
		if(s<min){
			min=s;
			imin=i;}
		s=0;}
	printf("\nMaxstr = %4.f, %d;\nMinstr = %4.f, %d;", max, imax+1, min, imin+1);
       	printf("\n\nНовая матрица:\n");
	for(int j=0; j<m; j++){
		s=A[imax][j];
		A[imax][j]=A[imin][j];
		A[imin][j]=s;}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%4.f", A[i][j]);
		}printf("\n");}
	return 0;}


/*
#include <stdio.h>
#define MAX_ROWS 15
#define MAX_COLS 10
void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int n, int m) {
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
printf("%d ", matrix[i][j]);
}
printf("\n");
}
}
int main() {
int matrix[MAX_ROWS][MAX_COLS];
int n, m;
// Ввод размеров матрицы
printf("Введите количество строк (n ≤ 15): ");
scanf("%d", &n);
printf("Введите количество столбцов (m ≤ 10): ");
scanf("%d", &m);
// Ввод элементов матрицы
printf("Введите элементы матрицы (%dx%d):\n", n, m);
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
scanf("%d", &matrix[i][j]);
}
}
// Инициализация переменных
int minRow = 0, maxRow = 0;
int minSum = 0, maxSum = 0;
// Рассчёт суммы элементов первой строки для инициализации
for (int j = 0; j < m; j++) {
minSum += matrix[0][j];
maxSum += matrix[0][j];
}
// Поиск строк с минимальной и максимальной суммой
for (int i = 0; i < n; i++) {
int currentSum = 0;
for (int j = 0; j < m; j++) {
currentSum += matrix[i][j];
}
if (currentSum < minSum) {
minSum = currentSum;
minRow = i;
}
if (currentSum > maxSum) {
maxSum = currentSum;
maxRow = i;
}
}
// Вывод исходной матрицы
printf("\nИсходная матрица:\n");
printMatrix(matrix, n, m);
// Вывод номеров строк и их сумм
printf("\nСтрока с минимальной суммой: %d (сумма = %d)\n", minRow + 1, minSum);
printf("Строка с максимальной суммой: %d (сумма = %d)\n", maxRow + 1, maxSum);
// Обмен строк
for (int j = 0; j < m; j++) {
int temp = matrix[minRow][j];
matrix[minRow][j] = matrix[maxRow][j];
matrix[maxRow][j] = temp;
}
// Вывод полученной матрицы
printf("\nПолученная матрица:\n");
printMatrix(matrix, n, m);
return 0;
}
*/			
