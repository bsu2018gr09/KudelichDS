#include<iostream>
#include<fstream>  
using namespace std;
struct color { unsigned char r; unsigned char g; unsigned char b; } c;

int main() {
	ifstream fff( "d:\\1.bmp" , ios::binary ); //  ios::binary влияет ТОЛЬКО на endl.
	ofstream ggg( "d:\\rez.bmp" , ios::binary );//сюда пишем (поток типа ofstream= output file stream)
	if ( !fff ) { cout << "No file d:\\1.bmp. Can't open\n"; exit( 1 ); }
	if ( !ggg ) { cout << " file d:\\rez.bmp. Can't create\n"; exit( 1 ); }

	char buf[ 30 ];// куда читать байты
	int r1=255 , g1=255 , b1=255;
	int r2=0, g2=0 , b2=0;
	int step=80;
	unsigned char r , g , b;//компоненты цвета
	color c;
	unsigned int w , h;//надеемся. что тут 4 байта

	fff.read( ( char * )&buf , 18 );   //чтение 18 байт заголовка bmp
	ggg.write( ( char * )&buf , 18 );    //запись 18 байт заголовка bmp
	fff.read( ( char * )&w , 4 ); cout << "w=" << w;   //чтение width из заголовка bmp
	fff.read( ( char * )&w , 4 ); cout << ", h=" << w; //чтение height из заголовка bmp
	w = 128; ggg.write( ( char * )&w , 4 );    //запись width в заголовок bmp ( w кратно 4, обязательно для нас, чтобы не делать выравнивание)
	h = 100; ggg.write( ( char * )&h , 4 );    //запись height в заголовок bmp
	fff.read( ( char * )&buf , 28 );   //чтение 28 байт заголовка bmp
	ggg.write( ( char * )&buf , 28 );    //запись 28 байт заголовка bmp

	c.r = r1; c.g = g1; c.b = b1;
	double dr = ( r2 - r1 ) / step;
	double dg = ( g2 - g1 ) / step;
	double db = ( b2 - b1 ) / step;
	int l = 0;
	for(int i=1;i<=h;++i){
		for ( int j = 1; j <= w; ++j ) {
			if ( l < step ) {
				c.b = c.b + db;
				c.g = c.g + dg;
				c.r = c.r + dr;
				l++;
			}
			ggg.write( ( char * )&c , 3 );     //запись сразу всего цвета
		}
		c.r = r1; 
		c.g = g1; 
		c.b = b1;
		l = 0;
	}
	fff.close();//закрыли файл
	ggg.close();//закрыли файл
	return 1;
}