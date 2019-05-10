﻿//Определить, сколько слов в строке содержат хотя бы одну букву A. Вывести такие слова на экран.
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
const int MAX = 255;
using namespace std;

void giveMemory( char*&str);
void fingingWords( char*str );
void findingWordsWithSymbol( char*str , int k,int &i,int &N);
void deleteMemory( char*&str );

int main() {
	char*str = nullptr;
	giveMemory(str);
	cin.getline(str,MAX);
	fingingWords(str);	
	deleteMemory( str );// и где печатает "сколько" слов???
	system( "pause" );
}
void giveMemory( char*&str) {
	str = new(nothrow) char[MAX];
	if ( !str ) {
		cout << "error" << "\n";
	}
}
void fingingWords( char*str ) {
	int k = -1;
	int N = 0;
	for ( int i = 0; i < strlen( str ); i++ ) {
		if ( *( str + i ) != ' ' ) {
			if ( k == -1 ) {
				k = i;
			}
			findingWordsWithSymbol(str,k,i,N);
		}
		else {
			k = -1;
		}
	}
	cout<<N<<"\n";
}
void findingWordsWithSymbol( char*str , int k , int &i ,int &N) {
	if ( *( str + i ) == 'A') {
		while ( ( *( str + k ) != ' ' ) && ( k < strlen( str ) ) ) {
			cout << *( str + k );
			k++;
		}
		i = k-1;
		N++;
		cout << "\n";
	}
}
void deleteMemory( char*&str ) {
	delete[] str;
	str = nullptr;
}
