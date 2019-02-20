//#define _CRT_SECURE_NO_WARNINGS 1
#include<map>
#include<vector>
#include<string>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;

//---------------map、nultimap、set、nultiset---
void MapTest()
{
	map<int, char> m{ { 1, 'a' }};
	cout << m[1] << endl;
	cout << m.size() << endl;
	m.insert({ 2, 'a' });
	cout << m[2] << endl;
	cout << m.size() << endl;
}

int main()
{
	MapTest();
	system("pause");
	return 0;
}

///////数组、指针在内存中的情况------------
/*
int main()
{
	char arr1[] = "abc";//arr1、arr2都在栈上，各自保存着各自的“abc”
	char arr2[] = "abc";
	char *p1 = "abc"; //p1、p2为栈上的两个变量，p1、p2指向堆上相同的一块地址
	char *p2 = "abc";
	return 0;
}
*/
/////////////////////////////////////////////////
/*
#include<stdio.h>
void fun()
{
	int b = 10;
	*(((int*)*(&b + 2)) - 2) = 20;
}

int main()
{
	int a = 0;
	fun();
	printf("%d\n", a);
	return 0;
}
*/
//-------------------------auto迭代器的糖果询问
//void test1()
//{
//	string s1 = "abcdefgh";
//	for (auto& e : s1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	test1();
//	system("pause");
//	return 0;
//}


//-----------------------------------------拷贝构造、类对象赋值
/*
class stu
{
public:
	stu(int n=9, char* st=" ") :i(n)
	{ 
		str = new char[strlen(st)+1];
		strcpy(str, st); 
	}
	void print()
	{
		cout << i << endl;
		cout << str << endl;
	}

	void change()
	{
		cin >> i;
		str[0] = 'z';
	}
private:
	int i;
	char *str;
	//char str[6];
};

int main()
{
	stu s4;
	stu s1(1, "abcd");
	s1.print();
	stu s2(s1);
	s2.print();
	stu s3=s1;
	s3.print();
	cout << endl << endl;
	s1.change();
	s1.print();
	s2.print();
	s3.print();
	s1.~stu();
	s2.~stu();
	system("pause");
	return 0;
}
*/
//----------------------------------继承-----------------------
//问题一

//class zm
//{
//public:
//	/*zm(char* c, int i, int j)
//	{
//		c= c;
//		a = i;
//		b = j;
//	}*/
//	~zm()
//	{
//		cout << "析构函数" << endl;
//	}
//	int a;
//private:
//		char* c;
//		int b;
//};
//
//class zm_1 :public zm
//{
//public:
//
//	zm_1(int x,int y) 
//	{
//		a = x;
//		d = y;
//	}
//	void test();
//private:
//	int d;
//};
//void zm_1::test()
//{
//	cout << a << endl;
//	cout << d << endl;
//}


//问题二

//class student
//{
//public:
//	void get_value();
//    void display();
//private:
//	string name;
//	int age;
//	char sex;
//};
//void student::get_value()
//{
//	cin >> name >> age >> sex;
//}
//void student::display()
//{
//	cout << "name:" << name << endl;
//	cout << "age:" << age << endl;
//	cout << "sex:" << sex << endl;
//}
//class student_1 :private student
//{
//public:
//	void get_value_1()
//	{
//		get_value();
//		cin >> addr>>number;
//	}
//	void display_1()
//	{
//		display();
//		cout << "addr:" << addr << endl;
//		cout << "number:" << number << endl;
//	}
//private:
//	string addr;
//	long long int number;
//};
//int main()
//{
//	student_1 s1;
//	s1.get_value_1();
//	s1.display_1();
//	system("pause");
//	return 0;
//}

//class A
//{
//public:
//	virtual void TestFun1()
//	{
//		cout << "A:TestFun1" << endl;
//	}
//	int _a;
//};
//class B :virtual public A
//{
//public:
//	virtual void TestFun1()
//	{
//		cout << "B:TestFun1" << endl;
//	}
//	virtual void TestFun2()
//	{
//		cout << "B:TestFun2" << endl;
//	}
//	int _b;
//};
//
//int main()
//{
//	B b;
//	cout << sizeof(b) << endl;
//	b._a = 1;
//	b._b = 2;
//	system("pause");
//	return 0;
//}
//--------------------------------------函数重载-----------------------
////返回值，参数类型均为int型的Max函数
//int Max(int a, int b)
//{
//	if (a > b)
//		return a;
//	return b;
//}

////返回值，参数类型均为double型的Max函数
//double Max(double a, double b)
//{
//	if (a > b)
//		return a;
//	return b;
//}
//
////返回值，参数类型均为char型的Max函数
//char Max(char a, char b)
//{
//	if (a > b)
//		return a;
//	return b;
//}
//
//int main()
//{
//	//int Max(int a, int b);//函数声明
//	//int Max（double a, int b);//函数声明
//	//int Max（char a, char b）;//函数声明
//	int i1, i2, i;
//	cin >> i1 >> i2;//输入两个整数
//	i = Max(i1, i2);//求最大整数
//	cout<<"int_Max: " << i << endl;
//	double d1, d2, d;
//	cin >> d1 >> d2;//输入两个浮点数
//	d = Max(d1, d2);//求最大浮点数
//	cout << "double_Max: "<<d << endl;
//	char c1, c2, c;
//	cin >> c1 >> c2;//输入两个字符
//	c = Max(c1, c2);//求最大字符
//	cout <<"char_Max: "<< c << endl;
//	system("pause");
//	return 0;
//}
//------------------------------------------------------------
//返回值，参数类型均为int型的Max函数（2个参数）
//int Max(int a, int b)
//{
//	if (a > b)
//		return a;
//	return b;
//}
//
////返回值，参数类型均为int型的Max函数（3个参数）
//int Max(int a, int b, int c)
//{
//	if (a > b)
//		b = a;
//	if (c > b)
//		b = c;
//	return b;
//}
//
//int main()
//{
//	int i1 = 9, i2 = 11, i3 = 8, i;
//	i = Max(i1, i2);//求两个数最大数
//	i = Max(i1, i2, i3);//求三个数最大数
//	cout << "int_Max(i1,i2): " << Max(i1,i2) << endl;//求两个数最大数
//	cout << "int_Max(i1,i2，i3): " << Max(i1,i2,i3) << endl;//求三个数最大数
//	system("pause");
//	return 0;
//}


////定义一个返回值类型为int，参数为一个int a的Test函数
//int Test(int a)
//{
//	return a;
//}
//
////定义一个返回值类型为double，参数为一个int a的Test函数
//double Test(int a)
//{
//	return a;
//}
//
////定义一个返回值类型为char，参数为一个int a的Test函数
//char Test(int a)
//{
//	return a;
//}
//
//int main()
//{
//	Test(10);
//	return 0;
//}



//----------------------------------------类模板实现一个坐标-----------------------------
//template<typename T1,typename T2>
//class point
//{
//public:
//	point<T1, T2>::point(T1 x, T2 y) :map_x(x), map_y(y){}
//	T1 Set_x(T1 x);
//	T2 Set_y(T2 y);
//friend ostream& operator<<(ostream& out, point<T1,T2>& p)
//{
//	out << "(" << p.map_x << "," << p.map_y << ")";
//		return out;
//}
//private:
//	T1 map_x;
//	T2 map_y;
//};
//
//template<typename T1,typename T2>
//T1 point<T1, T2>::Set_x(T1 x)
//{
//	map_x = x;
//	return map_x;
//}
//
//template<typename T1,typename T2>
//T2 point<T1, T2>::Set_y(T2 y)
//{
//	map_y = y;
//	return map_y;
//}
////template<typename T1,typename T2>
////ostream& operator<<(ostream &out, point<T1,T2> &p)
////{
////	out << "(" << p.map_x << "," << p.map_y << ")"
////		return out;
////}
//int main
//()
//{
//	point<int, int> p1(0,0);
//	point<double, double> p2(0, 0);
//	point<char, char> p3(0, 0);
//	point<char*, char*> p4(0, 0);
//	point<int, double> p5(0, 0);
//
//	cout << "( x = "<<p1.Set_x(10)<<" . "<<"y = "<<p1.Set_y(20)<<" )"<<endl;
//	cout << "( x = " << p2.Set_x(11.9) << " . " << "y = " << p2.Set_y(8.13) << " )" << endl;
//	cout << "( x = " << p3.Set_x(98) << " . " << "y = " << p3.Set_y('a') << " )" << endl;
//	cout << "( x = " << p4.Set_x("zm") << " . " << "y = " << p4.Set_y("gx") << " )" << endl;
//	cout << "( x = " << p5.Set_x(119) << " . " << "y = " << p5.Set_y(8.13) << " )" << endl;
//	cout << p2 << endl;
//	cout << p4 << endl;
//	system("pause");
//	return 0;
//}