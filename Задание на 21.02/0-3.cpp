#include<iostream>
#include<time.h>
using namespace std;
//������ ����� ������� N ������������������� ���������� ������� �� ���������� �� - N �� N.
//�������� ������� ������������ ������ ��������� ������� ������ �� k ���������.

void givememory(int*&A, int N);
void randominitarray(int*A, int N);
void shiftarray(int*A, int N,int k);
void printArray(int*A, int N);
void deletememory(int*A);

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int N,k;
	cout << "������� ���������� ��������� � �������:";
	cin >> N;
	cout << "������� �������� ������ �������:";
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
		*(A + i) = rand() % 11;
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
void deletememory(int*A) {
	delete A;
}
