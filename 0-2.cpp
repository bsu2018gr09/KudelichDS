//В массиве размера N, заполненного случ.числами от 0 до 10, определить максимальную длину последовательности равных элементов.
#include<iostream>
#include<time.h>
using namespace std;

void givememory(int*&A, int N);
void randominitarray(int*A, int N);
void findlonger(int*A, int N);
void deletememory(int*&A);
void printArray(int*A, int N);

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int N;
	cout << "Введите количество элементов в массиве:";
	cin >> N;
	int*A = nullptr;
	givememory(A, N);
	randominitarray(A, N);
	printArray(A,N);
	findlonger(A, N);
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
void findlonger(int*A, int N) {
	int i,k,cnt=1,Mcnt=1,mcnt=1,num=0,Num=0;
	for (i = 1, k = 0; i <= N; ++i,++k) {
		if (*(A + i) == *(A + k)) {
			++cnt;
		}
		else {
			mcnt = cnt;
			num = *(A + k);
			cnt = 1;
		}
		if (mcnt > Mcnt) {
			Mcnt = mcnt;
			Num = num;
		}
	}
	if (Mcnt > 1) {
		cout << Num << " составляет последовательность,повторяясь " << Mcnt << " раз(а)" << "\n";
	}
	else {
		cout << "Нет чисел,составляющих последовательность " << "\n";
	}
}
void deletememory(int*&A) {
	delete[] A;
	A=nullptr;
}
void printArray(int*A, int N) {
	int i;
	for (i = 0; i < N; ++i) {
		cout << *(A + i) << ";";
	}
	cout << "\n";
}
