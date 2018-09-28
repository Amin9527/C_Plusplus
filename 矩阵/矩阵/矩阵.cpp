#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//¸´ÊýÀà 
class Complex
{
private:
	int s[2][3];
public:
	Complex();
    void input();
	friend Complex& operator +(Complex &, Complex &);
	friend void pint(Complex &c);
};
Complex::Complex()
{
	for (int i = 0; i<2; i++)
	{
		for (int j = 0; j<3; j++)
		{
			s[i][j] = 0;
		}
	}
}
void Complex::input()
{
	for (int i = 0; i<2; i++)
	for (int j = 0; j<3; j++)
		cin >> s[i][j];
}
Complex& operator +(Complex &a, Complex &b)
{
	Complex p;
	for (int i = 0; i<2; i++)
	{
		for (int j = 0; j<3; j++)
		{
			p.s[i][j] = a.s[i][j] + b.s[i][j];
		}
	}
	return p;
}

void pint(Complex &c)
{
	for (int i = 0; i<2; i++)
	{
		for (int j = 0; j<3; j++)
		{
			cout << c.s[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	Complex  a, b, c;
	cout << "ÇëÊäÈëa¾ØÕó" << endl;
	a.input();
	cout << endl;
	cout << "ÇëÊäÈëb¾ØÕó" << endl;
	b.input();
	cout << endl;
	c = a + b;
	pint(c);
	system("pause");
}