/*Даны точки плоскости своими координатами в виде двух одномерных массивов (случайные числа). 
Точки плоскости рассортировать по возрастанию расстояния до прямой ax + by + c = 0.
*/
#include<iostream>
#include<time.h>
#include<math.h>

using namespace std;

void giveMemory(int*&A, int N);
void randomInitArray(int*A, int N);
void printArray(int*A, int N);
void findDistance(int *d, int * X, int *Y, int A, int B, int C, int N);
void sortCoords(int * d, int * X, int * Y, int N);
void deleteMemory(int*A);

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int N;
	cin >> N;
	int *X = new int[N];
	if (!X) { cout << "Error"; return 0; }
	int *Y = new int[N];
	if (!Y) { cout << "Error"; return 0; }
	giveMemory(X, N);
	randomInitArray(X, N);
	giveMemory(Y, N);
	randomInitArray(Y, N);
	printArray(X, N);
	printArray(Y, N);
	int A, B, C;
	cin >> A >> B >> C;
	int *d = new int[N];
	findDistance(d, X, Y, A, B, C, N);
	sortCoords(d, X, Y, N);
	printArray(X, N);
	printArray(Y, N);
	deleteMemory(X);
	deleteMemory(Y);
	deleteMemory(d);
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
		*(A + i) = rand() % 11;
	}
}
void printArray(int*A, int N) {
	int i;
	for (i = 0; i < N; ++i) {
		cout << *(A + i) << ";";
	}
	cout << "\n";
}
void deleteMemory(int*A) {
	delete[] A;
	A = nullptr;
}
void findDistance(int *d, int * X, int *Y, int A, int B, int C, int N) {
	for (int i = 0; i < N; ++i) {
		d[i] = abs((A *( *(X+i)) + B * (*(Y + i)) + C) / sqrt(A * A + B * B));
	}
}
void sortCoords(int * d, int * X, int * Y, int N) {
	for (int j = 0; j < N - 1; ++j) {
		int f = 0;
		for (int i = 0; i < N - j - 1; ++i) {
			if (*(d+i) > *(d+i+1))
			{
				swap(*(d + i), *(d + i + 1));
				swap(*(X + i), *(X + i + 1));
				swap(*(Y + i), *(Y + i + 1));
				f++;
			}
		}
		if (!f) { break; }
	}
}