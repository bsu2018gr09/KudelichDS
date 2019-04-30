/*
Возвратное кубическое уравнение. решение возвратного кубического уравнения (Ax^3+Bx^2+Bx+A=0)
*/
//RCE-Returnable Cubic Equation-Возвратное кубическое уравнение
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
	int f;//это флаг для определения того, сколько корней в конечном счёте выводить на экран
	double x1;
	double x2;
	double x3;
public:
	RCE() :A{ 1 }, B{ 1 }, f{ 3 }, x1{ 0 }, x2{ 0 }, x3{ 0 }{
		cout << "Default constructor is working" << '\n';
	}
	RCE(double A, double B) :A{ A }, B{ B }, f{ 2 }, x1{ 0 }, x2{ 0 }, x3{ 0 }{
		getRoots(A, B);
		cout << "Constructor with your coefficients A,B is working" << '\n';
	}
	double getRoots(double A,double B) {
		if ((A == 0) && (B == 0)) {
			f = 1;
			return f;
		}
		else
		{
			if ((A == 0) && (B != 0)) {
				f = 2;
				x1 = 0;
				x2 = -1;
				return f, x1, x2;
			}
			else if ((B == 0) && (A != 0)) {
				f = 3;
				x1 = -1;
				return f, x1;
			}
			else {
				x1 = -1;
				double D = pow((B - A), 2) - 4 * pow(A, 2);
				double d = sqrt(D);
				if (D > 0) {
					f = 4;
					x2 = (-(B - A) + d) / (2 * A);
					x3 = (-(B - A) - d) / (2 * A);
					return f, x1,x2,x3;
				}
				else if (D == 0) {
					f = 5;
					x2 = (-(B - A)) / (2 * A);
					return f, x1,x2;
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
	double getA() {
		return A;
	}
	double getB() {
		return B;
	}
	RCE operator =(const RCE& e) {
		return RCE(e.A, e.B);
	}
	RCE operator +(RCE& a) {
		return RCE(getA() + a.getA(), getB() + a.getB());
	}
	RCE operator -(RCE& a) {
		return RCE(getA() - a.getA(), getB() - a.getB());
	}
	RCE operator *(double q) {
		return RCE(getA()*q, getB()*q);
	}
	RCE operator /(double q) {
		if (q != 0) {
			return RCE(getA() / q, getB() / q);
		}
		else {
			cout << "We can't divide by zero" << "\n";
		}
	}
	friend ostream& operator << (ostream & stream, const RCE& d)
	{
		if (d.f == 1) {
			stream << d.A << ";" << d.B << ";" << "Infinite number of roots"<< '\n';
		}
		if (d.f == 2) {
			stream << d.A << ";" << d.B <<";" << d.x1<< ";" << d.x2 << '\n';
		}
		if (d.f == 3) {
			stream << d.A << ";" << d.B << ";" << d.x1 << '\n';
		}
		if (d.f == 4) {
			stream << d.A << ";" << d.B << ";" << d.x1 << ";" << d.x2 << ";" << d.x3<<'\n';
		}
		if (d.f == 5) {
			stream << d.A << ";" << d.B << ";" << d.x1 << ";" << d.x2 << '\n';
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
	RCE p1(1, 2);
	RCE p2(p1);
	RCE p3;
	cout << p1;
	cout << p2;
	cout << p3;
	cout << p1 + p2;
	cout << p1 - p2;
	double tmp;
	cin >> tmp;
	cout << p1 * tmp;
	cout << p1 / tmp;
	system("pause");
}

