//Дана целочисленная матрица T(n,m), n,m<=20. Вычеркнуть из матрицы все строки, содержащие хотя бы один нулевой элемент. Если таких строк нет – выдать соответствующее сообщение. Вывести на печать исходную и полученную матрицы.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(){
	srand(time(NULL));
	int n, m, mmax=20, nmax=20;
	printf("Введите количество строк и столбцов: ");
	scanf("%d %d", &n, &m);
	if(n>nmax || n<0 || m>mmax || m<0){
		printf("Oшибка ввода!");
		return 0;}
	float A[n][m];
	printf("Исходная матрица:\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			A[i][j]=rand()%6;}}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%4.f", A[i][j]);
		}printf("\n");}
	//
	int a=0, k=0;
	float B[nmax][mmax];
	for(int i=0; i<n; i++){
	       for(int j=0; j<m; j++){
		       if(A[i][j]==0){
			       a++;}}
	       if(a==0){
		       for(int g=0; g<m; g++){
			       B[k][g]=A[i][g];}
		       k++;}
	       a=0;}   
	if(k==n){
		printf("Нет строк удовлетворяющих условию");
		return 0;}
	printf("\nНовая матрица:\n");
	for(int i=0; i<k; i++){
		for(int j=0; j<m; j++){
			printf("%4.f", B[i][j]);
		}printf("\n");}
	return 0;}

/*
#include <stdio.h>
#define MAX_ROWS 20
#define MAX_COLS 20
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
printf("Введите количество строк (n ≤ 20): ");
scanf("%d", &n);
printf("Введите количество столбцов (m ≤ 20): ");
scanf("%d", &m);
// Ввод элементов матрицы
printf("Введите элементы матрицы (%dx%d):\n", n, m);
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
scanf("%d", &matrix[i][j]);
}
}
// Вывод исходной матрицы
printf("\nИсходная матрица:\n");
printMatrix(matrix, n, m);
// Создание новой матрицы, исключая строки с нулевыми элементами
int newMatrix[MAX_ROWS][MAX_COLS];
int newRowCount = 0; // Количество строк в новой матрице
for (int i = 0; i < n; i++) {
int hasZero = 0;
for (int j = 0; j < m; j++) {
if (matrix[i][j] == 0) {
hasZero = 1; // Найден нулевой элемент
break;
}
}
if (!hasZero) { // Если строка не содержит нулевых элементов
for (int j = 0; j < m; j++) {
newMatrix[newRowCount][j] = matrix[i][j];
}
newRowCount++;
}
}
// Проверяем, есть ли строки, которые нужно было вычеркнуть
if (newRowCount == n) {
printf("\nВ матрице нет строк, содержащих нулевые элементы.\n");
} else {
// Вывод полученной матрицы
printf("\nПолученная матрица:\n");
printMatrix(newMatrix, newRowCount, m);
}
return 0;
}
*/	
	
