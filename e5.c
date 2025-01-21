//Дана целочисленная матрица A(n,m), n≤20. Вычеркнуть из матрицы все строки, первый элемент которых кратен 2. Если таких строк нет – вывести соответствующее сообщение. Вывести на печать исходную и полученную матрицы.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(){
	srand(time(NULL));
	int n, m, mmax=20, nmax=20, k=0;
	printf("Введите количество строк и столбцов: ");
	scanf("%d %d", &n, &m);
	if(n>nmax || n<0 || m>mmax || m<0){
		printf("Oшибка ввода!");
		return 0;}
	int A[n][m];
	printf("Исходная матрица:\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			A[i][j]=rand()%9+1;}}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%4.d", A[i][j]);
		}printf("\n");}
	//
	int B[nmax][mmax];
	for(int i=0; i<n; i++){
		if(A[i][0]%2!=0){
			for(int j=0; j<m; j++){
				B[k][j]=A[i][j];}
			k++;}}
			
	if(k==n){
		printf("\nНет удовлетворяющих условию строк");
		return 0;}
	printf("\nНовая матрица:\n");
	for(int i=0; i<k; i++){
		for(int j=0; j<m; j++){
			printf("%4.d", B[i][j]);
		}printf("\n");}
	return 0;}


/*
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(){
srand(time(NULL));
int n, m, mmax=20, nmax=20, k=0;
printf("Введите количество строк и столбцов: ");
scanf("%d %d", &n, &m);
if(n>nmax || n<0 || m>mmax || m<0){
printf("Oшибка ввода!");
return 0;}
int A[n][m];
printf("Исходная матрица:\n");
for(int i=0; i<n; i++){
for(int j=0; j<m; j++){
A[i][j]=rand()%9+1;}}
for(int i=0; i<n; i++){
for(int j=0; j<m; j++){
printf("%4.d", A[i][j]);
}printf("\n");}
//
int B[nmax][mmax];
for(int i=0; i<n; i++){
if(A[i][0]%2!=0){
for(int j=0; j<m; j++){
B[k][j]=A[i][j];}
k++;}}

if(k==n){
printf("\nНет удовлетворяющих условию строк");
return 0;}
printf("\nНовая матрица:\n");
for(int i=0; i<k; i++){
for(int j=0; j<m; j++){
printf("%4.d", B[i][j]);
}printf("\n");}
return 0;}
*/

