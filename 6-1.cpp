/*
Возвратное кубическое уравнение. решение возвратного кубического уравнения (Ax^3+Bx^2+Bx+A=0)
*/
//RCE-Returnable Cubic Equation
#include<iostream>
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class RCE
{
private:
	double A;
	double B;
	double x1;
	double x2;
	double x3;
public:
	RCE() :A{ 0 } , B{ 0 }{
		cout << "Default constructor is working" << '\n';
	}
	RCE( double A , double B ) :A{ A } , B{ B }{
		cout << "Constructor with your coefficients A,B is working" << '\n';
	}
	RCE( const RCE& t ) :A{ t.A } , B{ t.B } {
		cout << "Copy constructor is working" << '\n';
	}
	~RCE() {
		cout << "Destructor is working" << '\n';
	}
	double getA() {
		return A;
	}
	double getB() {
		return B;
	}
	RCE operator =( const RCE& e ) {
		return RCE( e.A , e.B );
	}
	RCE operator +( RCE& a ) {
		return RCE( getA() + a.getA() , getB() + a.getB() );
	}
	RCE operator -( RCE& a ) {
		return RCE( getA() - a.getA() , getB() - a.getB() );
	}
	RCE operator *( double q ) {
		return RCE( getA()*q , getB()*q );
	}
	RCE operator /( double q ) {
		if ( q != 0 ) {
			return RCE( getA() / q , getB() / q );
		}
		else {
			cout << "We can't divide by zero" << "\n";
		}
	}
	void getRoots() {
		if ( ( A == 0 ) && ( B == 0 ) ) {
			cout << "Infinite number of roots" << "\n";
		}
		else
		{
			if ( ( A == 0 ) && ( B != 0 ) ) {
				x1 = 0;
				x2 = -1;
				cout << "x1=" << x1 << ";" << "x2=" << "x2" << ";" << "\n";
			}
			else if ( ( B == 0 ) && ( A != 0 ) ) {
				x1 = -1;
				cout << "x1=" << x1 << ";" << "\n";
			}
			else {
				x1 = -1;
				double D = pow( ( B - A ) , 2 ) - 4 * pow( A , 2 );
				double d = sqrt( D );
				if ( D > 0 ) {
					x2 = ( -( B - A ) + d ) / ( 2 * A );
					x3 = ( -( B - A ) - d ) / ( 2 * A );
					cout << "x1=" << x1 << ";" << "x2=" << x2 << ";" << "x3=" << x3 << ";" << "\n";
				}
				else if ( D == 0 ) {
					x2 = ( -( B - A ) ) / ( 2 * A );
					cout << "x1=" << x1 << ";" << "\n";
				}
				else {
					cout << "x1=" << x1 << " " << "\n";
				}
			}
		}

	}
	friend ostream& operator << ( ostream & stream , const RCE& d )
	{
		stream << d.A << ";" << d.B << '\n';
		return stream;
	}
	friend istream& operator >> ( istream & stream , RCE& w )
	{
		stream >> w.A >> w.B;
		return stream;
	}

};
int main() {
	RCE p1( 1 , 2 );
	RCE p2( p1 );
	RCE p3;
	cout << p1 + p2;
	cout << p1 - p2;
	double tmp;
	cin >> tmp;
	cout << p1 * tmp;
	cout << p1 / tmp;
	p1.getRoots();
	system( "pause" );
}

