#include<iostream>
#include<time.h>
//В массиве размера N, заполненного случ.числами от 0 до 10, подсчитать количество элементов, встречающихся более одного раза.

using namespace std;
void givememory(int*&A, int N);
void randominitarray(int*A, int N);
void howmanycopies(int* A, int N);
void printArray(int*A, int N);
void deletememory(int*A);

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int N;
	cout << "Введите количество элементов в массиве:";
	cin >> N;
	int*A = nullptr;
	givememory(A, N);
	randominitarray(A, N);
	printArray(A, N);
	howmanycopies(A,N);
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
		*(A + i) = rand() % 11;
	}
}
void howmanycopies(int* A, int N) {
	int*B = nullptr;
	B = new(nothrow)int[N];
	int i,j,cop;
	for (i = 0,j=0; i < N; ++i,++j) {
		*(B + j) = *(A + i);
	}
	for (i = 0; i < N; ++i) {
		cop = 0;
		for (j = 0; j < N; ++j) {
			if (*(A + i) == *(B + j)) {
				cop++;
				*(B + j) = 11;
			}
		}
		if (cop > 1) {
			cout << *(A+i) << " встречается " << cop << " раз(а)" << "\n";
		}
	}
	delete B;
}
void printArray(int*A, int N) {
	int i;
	for (i = 0; i < N; ++i) {
		cout << *(A + i) << ";";
	}
	cout << "\n";
}
void deletememory(int*A) {
	delete A;
}

