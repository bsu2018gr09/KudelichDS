#include<iostream>
#include<iomanip>
//В массиве А(N, M) расположить столбцы по возрастанию количества чётных элементов в столбце
using namespace std;

void giveMemory(int **&A, int N, int M);
void initArray(int **A, int N, int M);
void printArray(int**A, int N, int M);
int counting(int **A, int j, int N);
void shift(int **A, int N, int M);
void freeArray(int **&A, int N);
int main() {
	setlocale(LC_ALL, "rus");
	int N, M;
	cout << "Введите число строк(N): ";
	cin >> N;
	cout << "Введите число столбцов(M): ";
	cin >> M;
	int**A = nullptr;
	giveMemory(A, N, M);
	initArray(A, N, M);
	printArray(A, N, M);
	shift(A, N, M);
	freeArray(A, N);
	system("pause");
}
void giveMemory(int **&A, int N, int M) {
	A = new(nothrow)int*[N];
	for (int i = 0; i < N; ++i) {
		A[i] = new(nothrow)int[M];
		if (!A[i]) {
		cout << "error" << "\n";
	}
	}
}
void initArray(int **A, int N, int M) {
	for (int i = 0, b = 1; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			A[i][j] = b;
			++b;
		}
	}
}
void printArray(int**A, int N, int M) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << setw(2) << A[i][j] << ";";
		}
		cout << "\n";
	}
	cout << "\n";
}
int counting(int **A, int j, int N) {
	int c=0;
	for (int i= 0; i < N; ++i) {
		if (!(A[i][j] % 2)) {
			c++;
		}
	}
	return c;
}
void shift(int **A, int N, int M) {
	int f = 1;
	while (f) {
		f = 0;
		for (int j1 = 0, j2 = 1; j2 < M; ++j1, ++j2) {
			int a = counting(A, j1, N);
			int b = counting(A, j2, N);
			if (a > b) {
				f = 1;
				for (int i = 0; i < N; ++i) {
					swap(A[i][j1], A[i][j2]);
				}
			}
		}
	}
	printArray(A, N, M);
}
void freeArray(int **&A, int N) {
	for (int i = 0; i < N; i++) {
		A[i] = nullptr;
	}
	delete[]A;
	A=nullptr;
}
