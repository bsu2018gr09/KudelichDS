//Массив чисел размера N проинициализировать случайными числами из промежутка от - N до N.
//Написать функцию циклического сдвига элементов массива вправо на k элементов.
#include<iostream>
#include<time.h>
using namespace std;

void givememory(int*&A, int N);
void randominitarray(int*A, int N);
void shiftarray(int*A, int N,int k);
void printArray(int*A, int N);
void deletememory(int*&A);

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int N,k;
	cout << "Введите количество элементов в массиве:";
	cin >> N;
	cout << "Введите,на сколько элементов нужно сдвинуть массив вправо:";
	cin >> k;
	int*A = nullptr;
	givememory(A, N);
	randominitarray(A, N);
	printArray(A,N);
	shiftarray(A, N,k);
	printArray(A, N);
	deletememory(A);
	system("pause");
}

void givememory(int*&A, int N) {
	A = new(nothrow)int[N];
	if (!A) {
		cout << "error" << "\n";
	}
}
void randominitarray(int*A, int N) {
	int i;
	for (i = 0; i < N; ++i) {
		*(A + i) = -N+rand() %(2*N) ;
	}
}
void shiftarray(int*A, int N,int k) {
	int cop,i,j;
	for (i = 0,j=N-1; i < N/2; ++i,--j) {
		swap(*(A + i), *(A + j));
	}
	for (i = 0,j=k-1; i < k / 2; ++i,--j) {
		swap(*(A + i), *(A + j));
	}
	for (i = k, j = N - 1;i<(N-k)/2+k;++i,--j) {
		swap(*(A + i), *(A + j));
	}
}
void printArray(int*A, int N) {
	int i;
	for (i = 0; i < N; ++i) {
		cout << *(A + i) << ";";
	}
	cout << "\n";
}
void deletememory(int*&A) {
	delete[] A;
	A=nullptr;
}
