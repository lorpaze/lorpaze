//Дана целочисленная матрица T(n,m), n,m<=20. Вычеркнуть из матрицы все столбцы, содержащие хотя бы один нулевой элемент. Если таких столбцов нет – выдать соответствующее сообщение. Вывести на печать исходную и полученную матрицы.

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
	for(int j=0; j<m; j++){
	       for(int i=0; i<n; i++){
		       if(A[i][j]==0){
			       a++;}}
	       if(a==0){
		       for(int g=0; g<n; g++){
			       B[g][k]=A[g][j];}
		       k++;}
	       a=0;}   
	if(k==m){
		printf("Нет столбцов удовлетворяющих условию");
		return 0;}
	printf("\nНовая матрица:\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<k; j++){
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
// Массив для отслеживания столбцов с нулями
int removeCol[MAX_COLS] = {0};
// Проверка столбцов на наличие нулевых элементов
for (int j = 0; j < m; j++) {
for (int i = 0; i < n; i++) {
if (matrix[i][j] == 0) {
removeCol[j] = 1; // Отметить столбец для удаления
break;
}
}
}
// Создание новой матрицы, исключая столбцы с нулями
int newMatrix[MAX_ROWS][MAX_COLS];
int newColCount = 0; // Количество столбцов в новой матрице
for (int j = 0; j < m; j++) {
if (removeCol[j] == 0) { // Если столбец не содержит нулевых элементов
for (int i = 0; i < n; i++) {
newMatrix[i][newColCount] = matrix[i][j];
}
newColCount++;
}
}
// Проверяем, есть ли столбцы, которые нужно было вычеркнуть
if (newColCount == m) {
printf("\nВ матрице нет столбцов, содержащих нулевые элементы.\n");
} else {
// Вывод полученной матрицы
printf("\nПолученная матрица:\n");
printMatrix(newMatrix, n, newColCount);
}
return 0;
}
*/


