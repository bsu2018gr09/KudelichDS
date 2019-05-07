/*
Возвратное кубическое уравнение. решение возвратного кубического уравнения (Ax^3+Bx^2+Bx+A=0)
*/
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class RCE
{
private: 
	double A;
	double B;
	int f;
	/*
	f=1-1 корень
	f=2-2 корня
	f=3-3 корня
	f=4-бесконечное количество корней
	*/
	double x1;
	double x2;
	double x3;
public:
	RCE() :A{ 1 }, B{ 1 }, f{ 1 }, x1{ -1 }, x2{ 0 }, x3{ 0 }{
		cout << "Default constructor is working" << '\n';
	}
	RCE(double A, double B) :A{ A }, B{ B }, f{ 2 }, x1{ 0 }, x2{ 0 }, x3{ 0 }{
		getRoots(A, B,f,x1,x2,x3);
		cout << "Constructor with your coefficients A,B is working" << '\n';
	}
	double getRoots(double A,double B,int &f,double &x1, double &x2, double &x3) {
		if ((A == 0) && (B == 0)) {
			f = 4;
			return f;
		}
		else
		{
			if ((A == 0) && (B != 0)) {
				f = 2;
				x1 = -1;
				x2 = 0;
				return f, x1, x2;
			}
			else if ((B == 0) && (A != 0)) {
				f = 1;
				x1 = -1;
				return f, x1;
			}
			else {
				f = 1;
				x1 = -1;
				double D = pow((B - A), 2) - 4 * pow(A, 2);
				double d = sqrt(D);
				if (D > 0) {
					f = 3;
					x2 = (-(B - A) + d) / (2 * A);
					x3 = (-(B - A) - d) / (2 * A);
					return f, x1,x2,x3;
				}
				else if (D == 0) {
					f = 2;
					x2 = (-(B - A)) / (2 * A);
					return f, x1,x2;
				}
				else {
					return f, x1;
				}
			}
		}
	}
	RCE(const RCE& t) :A{ t.A }, B{ t.B }, f{ t.f }, x1{ t.x1 }, x2{ t.x2 }, x3{ t.x3 } {
		cout << "Copy constructor is working" << '\n';
	}
	~RCE() {
		cout << "Destructor is working" << '\n';
	}
	const RCE operator =(const RCE& e) {
		return RCE(e.A, e.B);
	}
	RCE operator +(RCE& a) {
		return RCE(A + a.A, B + a.B);
	}
	RCE operator -(RCE& a) {
		return RCE(A - a.A, B - a.B);
	}
	RCE operator *(double q) {
		return RCE(A*q, B*q);
	}
	RCE operator /(double q) {
		if (q != 0) {
			return RCE(A/q, B/q);
		}
		else {
			cout << "We can't divide by zero" << "\n";
			return RCE(A, B);
		}
	}
	friend ostream& operator << (ostream & stream, const RCE& d)
	{
		if (d.f == 4) {
			stream << d.A << ";" << d.B << ";" << "Infinite number of roots"<< '\n';
		}
		if (d.f == 2) {
			stream << d.A << ";" << d.B <<";" << d.x1<< ";" << d.x2 << '\n';
		}
		if (d.f == 1) {
			stream << d.A << ";" << d.B << ";" << d.x1 << '\n';
		}
		if (d.f == 3) {
			stream << d.A << ";" << d.B << ";" << d.x1 << ";" << d.x2 << ";" << d.x3<<'\n';
		}
		return stream;
	}
	friend istream& operator >> (istream & stream, RCE& w)
	{
		stream >> w.A >> w.B;
		return stream;
	}
};
int main() {
	RCE p1(1, 2),p2(p1),p3;
	RCE Arr[5];
	
	double tmp;
	cin >> tmp;
	cout << p1+p2;
	cout << p1-p2;
	cout << p1 * tmp;
	cout << p1 / tmp;
	
	Arr[0] =p1;
	cout << Arr[0];
	cout << Arr[0] + Arr[0];
	cout << Arr[0] - Arr[0];
	cout << Arr[0] * tmp;
	cout << Arr[0] / tmp;
	
	cin >> p3;
	cout<< p3;
	system("pause");
}
