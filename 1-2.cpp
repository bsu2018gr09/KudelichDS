//Положительные элементы массива А(N) переставить в конец массива, сохраняя порядок следования. 
//Отрицательные элементы расположить в порядке убывания. Дополнительный массив не использовать.
#include<iostream>
#include<time.h>
using namespace std;

void giveMemory(int*&A, int N);
void randomInitArray(int*A, int N);
void printArray(int*A, int N);
void deleteMemory(int*&A);
void shiftPositive(int*A, int N);
void shiftArray(int*A, int N, int &k);
void descendingNegative(int *A, int N, int &k);

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int N;
	cout << "Введите размер массива";
	cin >> N;
	int*A = nullptr;
	giveMemory(A,N);
	randomInitArray(A, N);
	printArray(A, N);
	shiftPositive(A,N);
	printArray(A, N);
	deleteMemory(A);
	system("pause");
}

void giveMemory(int*&A, int N) {
	A = new(nothrow)int[N];
	if (!A) {
		cout << "error" << "\n";
	}
}
void randomInitArray(int*A, int N) {
	int i;
	for (i = 0; i < N; ++i) {
		*(A + i) = rand() % 21-10;
	}
}
void printArray(int*A, int N) {
	int i;
	for (i = 0; i < N; ++i) {
		cout << *(A + i) << ";";
	}
	cout << "\n";
}
void shiftPositive(int*A, int N) {
	int i = 0, k = 0;
	for (; i < N; ++i) {
		if (*(A + i) >= 0) {
			swap(*(A + i), *(A + k));
			++k;
		}
	}
	shiftArray(A, N, k);
	descendingNegative(A, N, k);
	
}
void descendingNegative(int *A, int N, int &k) {
	int l = 1,j,i;
	while (l) {
		l = 0;
		for (i = 0, j = 1; j < k; ++i, ++j) {
			if (*(A + i) < *(A + j)) {
				swap(*(A + i), *(A + j));
				l = 1;
			}
		}
	}
}
void shiftArray(int*A, int N, int &k) {
	int  i, j;
	k = N - k;
	for (i = 0, j = N - 1; i < N / 2; ++i, --j) {
		swap(*(A + i), *(A + j));
	}
	for (i = 0, j = k - 1; i < k / 2; ++i, --j) {
		swap(*(A + i), *(A + j));
	}
	for (i = k, j = N - 1; i < (N - k) / 2 + k; ++i, --j) {
		swap(*(A + i), *(A + j));
	}
}
void deleteMemory(int*&A) {
	delete []A;
	A=nullptr;
}
