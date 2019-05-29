/*
Преобразовать каждое слово в строках, удалив в них заданную букву. Отсортировать строки по количеству удалённых букв.
*/
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int Counting(int N) {
	ifstream fffff("d:\\date1.txt");
	if (!fffff) {
		cout << "No file d:\\date1.txt. Can't open\n";
		exit(1);
	}
	char *buff = new char[N];
	if (!buff) {
		cout << "Error";
		exit(1);
	}
	int c=0;
	while (1) {
		fffff.getline(buff, N - 1);
		if (fffff.fail()) fffff.clear();
		cout << buff << '\n';
		c++;
		if (fffff.eof()) break;
	}
	delete[] buff;
	fffff.close();
	return c;
}
void WritingInArray(int N, char**str) {
	ifstream fffff("d:\\date1.txt");
	if (!fffff) {
		cout << "No file d:\\date1.txt. Can't open\n";
		exit(1);
	}
	int i = 0;
	while (1) {
		str[i] = new char[N];
		if (!str[i]) {
			cout << "Error";
			exit(1);
		}
		fffff.getline(str[i], N - 1);
		if (fffff.fail()) fffff.clear();
		i++;
		if (fffff.eof()) break;
	}
	fffff.close();
}
void WritingArray(int count, char**str) {
	for (int i = 0; i < count; i++) {
		cout << str[i] << "\n";
	}
	cout << "----------" << '\n';
}
void DeleteSymbols(int count, int*C, char**str, char s, int N) {
	int i, j = 0, k = 0, f, n;
	for (i = 0; i < count; i++) {
		f = 1, n = 0;
		while (f) {
			f = 0;
			for (j = 0; j < strlen(str[i]); j++) {
				if (str[i][j] == s) {
					for (j, k = j + 1; k < N; j++, k++) {
						swap(str[i][j], str[i][k]);
					}
					n++;
					f = 1;
				}
			}
		}
		C[i] = n;
	}
}
void SortStrings(int count, int*C, char**str) {
	int f = 1;
	while (f) {
		f = 0;
		for (int i = 0, k = 1; k < count; i++, k++) {
			if (C[k] > C[i]) {
				swap(str[i], str[k]);
				swap(C[i], C[k]);
				f = 1;
			}
		}
	}
}
void WritingInFile(int count, char **str) {
	ofstream ggggg("d:\\date2.txt");
	if (!ggggg) {
		cout << "No file d:\\date2.txt. Can't create\n";
		exit(1);
	}
	for (int i = 0; i < count; i++) {
		ggggg << str[i] << '\n';
	}
	ggggg.close();
}
void DeleteArray(int count,char**str) {
	for (int i = 0; i < count; i++) {
		str[i] = nullptr;
	}
	delete[]str;
}
int main() {
	char s = 'A';
	const int N = 200;
	int count = Counting(N);
	cout << "-----In file " << count << " lines" << '\n';
	char**str = new char*[count];
	if (!str) {
		cout << "Error";
		exit(1);
	}
	WritingInArray(N, str);
	WritingArray(count, str);
	int* C = new int[count];
	if (!C) {
		cout << "Error";
		exit(1);
	}
	DeleteSymbols(count, C, str, s, N);
	SortStrings(count, C, str);
	WritingArray(count, str);
	WritingInFile(count, str);
	DeleteArray(count, str);
	delete[]C;
	system("pause");
}