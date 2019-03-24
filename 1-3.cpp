//Элементы массива А(N), значения которых – простые числа, расположить в порядке возрастания, 
//не нарушая порядка следования других элементов.
#include<iostream>
#include<time.h>
#include<math.h>
using namespace std;

void giveMemory(int*&A, int N);
void randomInitArray(int*A, int N);
void printArray(int*A, int N);
void deleteMemory(int*&A);
void simpleNumber(int*A, int N, int &i, int &k);
void findSimpleNumbers(int*A, int N);

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int N, i,k;
	cin >> N;
	cout << "Введите размер массива";
	int*A = nullptr;
	giveMemory(A, N);
	randomInitArray(A, N);
	printArray(A, N);
	findSimpleNumbers(A, N);
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
		*(A + i) = rand() %6;
	}
}
void printArray(int*A, int N) {
	int i;
	for (i = 0; i < N; ++i) {
		cout << *(A + i) << ";";
	}
	cout << "\n";
}
void deleteMemory(int*&A) {
	delete []A;
	A=nullptr;
}
void findSimpleNumbers(int*A, int N) {
	int l =1,i,k,j;
	while (l) {
		l = 0;
		for (i = 0; i < N; ++i) {
			if (*(A + i) > 1) {
				k = 0;
				simpleNumber(A, N, i, k);
				if (k == 0) {
					for (j = 0; j < N; ++j) {
						if (*(A + j) > 1) {
							if (i != j) {
								k = 0;
								simpleNumber(A, N, j, k);
								if (k == 0) {
									if (*(A + i) > *(A + j)) {
										if (j > i) {
											swap(*(A + i), *(A + j));
											l = 1;
										}
									}
								}
							}
						}
					}
				}
			}
		}	
	}
}
void simpleNumber(int*A, int N,int &i,int &k) {
	int M = sqrt(*(A + i));
	for (int z =2; z <= M; ++z) {
		if (*(A+i)%z == 0) {
			k = 1;
			break;
		}
	}
}

