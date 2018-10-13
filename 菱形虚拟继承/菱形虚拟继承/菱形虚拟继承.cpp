#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class A
{
public:
	virtual void TestFun1()
	{
		cout << "A:TestFun1" << endl;
	}
	virtual void TestFun2()
	{
		cout << "A:TestFun2" << endl;
	}
	int _a;
};

class B1 :virtual public A
{
public:
	virtual void TestFun1()
	{
		cout << "B1:TestFun1" << endl;
	}
	virtual void TestFun3()
	{
		cout << "B1:TestFun3" << endl;
	}
	int _b1;
};

class B2 :virtual public A
{
public:
	virtual void TestFun2()
	{
		cout << "B2:TestFun2" << endl;
	}
	virtual void TestFun4()
	{
		cout << "B2:TestFun4" << endl;
	}
	int _b2;
};

class C :public B1, public B2
{
public:
	virtual void TestFun1()
	{
		cout << "C:TestFun1" << endl;
	}
	virtual void TestFun3()
	{
		cout << "C:TestFun3" << endl;
	}
	virtual void TestFun4()
	{
		cout << "C:TestFun4" << endl;
	}
	virtual void TestFun5()
	{
		cout << "C:TestFun5" << endl;
	}
	int _c;
};
typedef void(*p)();
void PrintTestFun(C &c)
{
	p* p1 = NULL;
	p1=(p*)(*((int*)(&c)));
	while (*p1)
	{
		(*p1)();
		p1 = (p*)((int*)p1 + 1);
	}
}
int main()
{
	C c;
	cout << sizeof(c) << endl;
	c._a = 1;
	c._b1 = 2;
	c._b2 = 3;
	c._c = 4; 
	PrintTestFun(c);
	system("pause");
	return 0;
}