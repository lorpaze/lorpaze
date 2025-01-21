//Дана матрица A(n,m), n≤10,m≤15. Поменять местами столбец, содержащий минимальную сумму элементов, и столбец, содержащий максимальную сумму элементов. Если таких столбцов несколько – использовать первые найденные. Вывести на печать исходную матрицу, номера найденных столбцов и их суммы, а также полученную матрицу.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
int main(){
	srand(time(NULL));
	int n, m, mmax=15, nmax=10, s=0, jmax, jmin;
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
	for(int j=0; j<m; j++){
		for(int i=0; i<n; i++){
			s+= A[i][j];}
		if (s>max){
			max=s;
			jmax=j;}
		if (s<min){
			min=s;
			jmin=j;}
		s=0;}
	printf("\nMaxstl = %4.f, %d;\nMinstl = %4.f, %d;", max, jmax+1, min, jmin+1);
	//
	for(int i=0; i<n; i++){
		s=A[i][jmin];
		A[i][jmin]=A[i][jmax];
		A[i][jmax]=s;}
	printf("\nНoвая матрица:\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%4.f", A[i][j]);
		}printf("\n");}


			
			
			
	return 0;}

/*
#include <stdio.h>
#define MAX_ROWS 10
#define MAX_COLS 15
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
printf("Введите количество строк (n ≤ 10): ");
scanf("%d", &n);
printf("Введите количество столбцов (m ≤ 15): ");
scanf("%d", &m);
// Ввод элементов матрицы
printf("Введите элементы матрицы (%dx%d):\n", n, m);
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
scanf("%d", &matrix[i][j]);
}
}
// Инициализация переменных
int minCol = 0, maxCol = 0;
int minSum = 0, maxSum = 0;

// Рассчёт суммы элементов первого столбца для инициализации
for (int i = 0; i < n; i++) {
minSum += matrix[i][0];
maxSum += matrix[i][0];
}
// Поиск столбцов с минимальной и максимальной суммой
for (int j = 0; j < m; j++) {
int currentSum = 0;
for (int i = 0; i < n; i++) {
currentSum += matrix[i][j];
}
if (currentSum < minSum) {
minSum = currentSum;
minCol = j;
}
if (currentSum > maxSum) {
maxSum = currentSum;
maxCol = j;
}
}
// Вывод исходной матрицы
printf("\nИсходная матрица:\n");
printMatrix(matrix, n, m);
// Вывод номеров столбцов и их сумм
printf("\nСтолбец с минимальной суммой: %d (сумма = %d)\n", minCol + 1, minSum);
printf("Столбец с максимальной суммой: %d (сумма = %d)\n", maxCol + 1, maxSum);
// Обмен столбцов
for (int i = 0; i < n; i++) {
int temp = matrix[i][minCol];
matrix[i][minCol] = matrix[i][maxCol];
matrix[i][maxCol] = temp;
}
// Вывод полученной матрицы
printf("\nПолученная матрица:\n");
printMatrix(matrix, n, m);
return 0;
}
*/
