//Äàíû òî÷êè ïëîñêîñòè ñâîèìè êîîðäèíàòàìè â âèäå äâóõ îäíîìåðíûõ ìàññèâîâ (ñëó÷àéíûå ÷èñëà).
//Òî÷êè ïëîñêîñòè ðàññîðòèðîâàòü ïî âîçðàñòàíèþ ðàññòîÿíèÿ äî ïðÿìîé ax + by + c = 0.
#include <iostream>
#include <ctime>
using namespace std;
void initCords( int * arr , int N ) {
	for ( int i = 0; i < N; ++i ) {
		arr[ i ] = rand() % 10;
	}
}
void printArray( int * arr , int N ) {
	for ( int i = 0; i < N; ++i ) {
		cout << arr[ i ] << " | ";
	}
}
void findDistance( int *d , int * X , int *Y , int A , int B , int C , int N ) {
	for ( int i = 0; i < N; ++i ) {
		d[ i ] = abs( ( A * X[ i ] + B * Y[ i ] + C ) / sqrt( A * A + B * B ) );//плохо. Никакой оптимизации
	}
}
void sortCoords( int * d , int * X , int * Y , int N ) {
	for ( int j = 0; j < N - 1; ++j ) {
		int f = 0;
		for ( int i = 0; i < N - j - 1; ++i ) {
			if ( d[ i ] > d[ i + 1 ] )
			{
				swap( d[ i ] , d[ i + 1 ] );
				swap( X[ i ] , X[ i + 1 ] );
				swap( Y[ i ] , Y[ i + 1 ] );
				f++;
			}
		}
		if ( !f ) { break; }
	}
}
void freeMemory( int * arr ) {
	delete[] arr;
	arr = nullptr;
}
int main()
{
	srand( time( NULL ) );
	setlocale( LC_ALL , "Russian" );
	int N;
	cout << "Ââåäèòå êîëè÷åñòâî òî÷åê ";
	cin >> N;
	int *X = new int[ N ]; 
	if ( !X ) { cout << "Error"; return 0; }
	int *Y = new int[ N ]; 
	if ( !Y ) { cout << "Error"; return 0; }
	initCords( X , N );
	initCords( Y , N );
	cout << "x: | ";
	printArray( X , N ); 
	cout << '\n';
	cout << "y: | "; 
	printArray( Y , N ); 
	cout << '\n';
	int A = 0 , B = 0 , C = 0;
	cout << "Ââåäèòå A , B , C  = 0\n";
	cin >> A >> B >> C; 
	cout << '\n';
	int *d = new int[ N ];
	findDistance( d , X , Y , A , B , C , N );
	sortCoords( d , X , Y , N ); cout << '\n';
	cout << "x: | "; 
	printArray( X , N ); 
	cout << '\n';
	cout << "y: | "; 
	printArray (Y , N ); 
	cout << '\n';
	freeMemory( X );
	freeMemory( Y );
	freeMemory( d );
	system( "pause" );
}
