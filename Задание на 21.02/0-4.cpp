#include<iostream>
#include<time.h>
//����������� � ������� ����������� �������� ������� �(N), ������� � k-�� ��������.
using namespace std;
void giveMemory(int*&A, int N);
void randomInitArray(int*A, int N);
void printArray(int*A, int N);
void deleteMemory(int*A);
void ascendingArray(int*A, int N, int k);

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int N,k;
	cout << "������� ������ �������: ";
	cin >> N;
	cout << "������� �������, � �������� ��������� ������ ����������: ";
	cin >> k;
	int*A = nullptr;
	giveMemory(A, N);
	randomInitArray(A, N);
	printArray(A, N);
	ascendingArray(A, N, k);
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
		*(A + i) = rand() % 21 - 10;
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
	delete A;
}
void ascendingArray(int*A, int N, int k) {
	int l = 1, i,j;
	while (l) {
		l = 0;
		for (i=k,j=k+1; j < N; ++i,++j) {
			if (*(A + i) > *(A + j)) {
				swap(*(A + i), *(A + j));
				l = 1;
			}
		}
	}
}