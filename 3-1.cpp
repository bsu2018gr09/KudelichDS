//Определить, сколько слов в строке содержат хотя бы одну букву A. Вывести такие слова на экран.
#include<iostream>
#include <cstring>
const int MAX = 255;
using namespace std;

void giveMemory( char*&str);
void findingWords( char*str );
void findingWordsWithSymbol( char*str , int k, int &i,int &cnt );
void deleteMemory( char*&str );

int main() {
	setlocale(LC_ALL, "rus");
	char*str = nullptr;
	giveMemory( str );
	cin.getline( str, MAX );
	findingWords( str );	
	system( "pause" );
}

void giveMemory( char*&str ) {
	str = new ( nothrow ) char[MAX];
	if  ( !str ) {
		cout << "error" << "\n";
	}
}
void findingWords( char*str ) {
	int k = -1;//k необходимо для запоминания начала слова
	int cnt = 0;//счетчик слов
	for ( int i = 0; i < strlen( str ); i++ ) {//i бежит по символам строки 
		if ( *( str + i ) != ' ' ) {
			if ( k == -1 ) {
				k = i;//запоминаем начало слова
			}
			findingWordsWithSymbol(str,k,i,cnt);
		}
		else {
			k = -1;//"обнуляем" переменную k, чтобы в ней не содержался адрес
		}
	}
	cout <<"В строке найдено слов с символом А:"<< cnt;
}
void findingWordsWithSymbol( char*str , int k , int &i ,int &cnt) {
	if ( *( str + i ) == 'A') {
		while ( ( *( str + k ) != ' ' ) && ( k < strlen( str ) ) ) {//Печатаем, пока не закончится слово или не закончится строка
			cout << *( str + k );//Печатаем слово, в котором есть слово
			k++;
		}
		i = k-1;//присваиваем i адрес конца слова, чтобы в findingWords оно продолжило идти по строке с конца этого же слова
		cnt++;
		cout << "\n";
	}
}
void deleteMemory( char*&str ) {
	delete[] str;
	str = nullptr;
}
