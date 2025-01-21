//Дана вещественная матрица B(n,m), n≤10. Поменять местами столбец, содержащий максимальное количество отрицательных элементов, и столбец, содержащий максимальное количество положительных элементов. Если таких столбцов несколько – использовать первые найденные. Вывести на печать исходную матрицу, номера найденных столбцов и найденное количество элементов, а также полученную матрицу.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(){
	srand(time(NULL));
	int n, m, mmax=10, nmax=15, o=0, p=0, jo, jp;
	int omax=-1, pmax=-1;
	printf("Введите количество строк и столбцов: ");
	scanf("%d %d", &n, &m);
	if(n>nmax || n<0 || m>mmax || m<0){
		printf("Oшибка ввода!");
		return 0;}
	float A[n][m], s=0;
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
			if(A[i][j]<0){
				o++;}
			if(A[i][j]>0){
				p++;}}
		if(o>omax){
			omax=o;
			jo=j;}
		if(p>pmax){
			pmax=p;
			jp=j;}
		o=0; p=0;}
	if(omax==0){
		printf("Отрицательные элементы отсутствуют");
		return 0;}
	if(pmax==0){
		printf("Положительные элементы отсутствуют");
		return 0;}
	printf("\nMaxo = %d, %d;\nMaxp = %d, %d;\n", omax, jo+1, pmax, jp+1);
	for(int i=0; i<n; i++){
		s=A[i][jo];
		A[i][jo]=A[i][jp];
		A[i][jp]=s;}
	printf("Новая матрица:\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%4.f", A[i][j]);
		}printf("\n");}
	return 0;}

/*
#include <stdio.h>
#define MAX_ROWS 10
#define MAX_COLS 10
void printMatrix(double matrix[MAX_ROWS][MAX_COLS], int n, int m) {
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
printf("%.2f ", matrix[i][j]);
}
printf("\n");
}
}
int main() {
double matrix[MAX_ROWS][MAX_COLS];
int n, m;
// Ввод размеров матрицы
printf("Введите количество строк (n ≤ 10): ");
scanf("%d", &n);
printf("Введите количество столбцов (m ≤ 10): ");
scanf("%d", &m);
// Ввод элементов матрицы
printf("Введите элементы матрицы (%dx%d):\n", n, m);
for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
scanf("%lf", &matrix[i][j]);
}
}
// Инициализация переменных
int maxNegCol = 0, maxPosCol = 0;
int maxNegCount = 0, maxPosCount = 0;
// Поиск столбцов с максимальным количеством отрицательных и положительных элементов
for (int j = 0; j < m; j++) {
int negCount = 0, posCount = 0;
for (int i = 0; i < n; i++) {
if (matrix[i][j] < 0) {
negCount++;
} else if (matrix[i][j] > 0) {
posCount++;
}
}
if (negCount > maxNegCount) {
maxNegCount = negCount;
maxNegCol = j;
}
if (posCount > maxPosCount) {
maxPosCount = posCount;
maxPosCol = j;
}
}
// Вывод исходной матрицы
printf("\nИсходная матрица:\n");
printMatrix(matrix, n, m);
// Вывод номеров столбцов с их количеством элементов
printf("\nСтолбец с максимальным количеством отрицательных элементов: %d (кол-во = %d)\n", maxNegCol + 1, maxNegCount);
printf("Столбец с максимальным количеством положительных элементов: %d (кол-во = %d)\n", maxPosCol + 1, maxPosCount);
// Обмен столбцов
for (int i = 0; i < n; i++) {
double temp = matrix[i][maxNegCol];
matrix[i][maxNegCol] = matrix[i][maxPosCol];
matrix[i][maxPosCol] = temp;
}
// Вывод полученной матрицы
printf("\nПолученная матрица:\n");
printMatrix(matrix, n, m);
return 0;
}
*/

