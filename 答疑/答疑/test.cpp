//#define _CRT_SECURE_NO_WARNINGS 1
#include<map>
#include<vector>
#include<string>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;

//---------------map��nultimap��set��nultiset---
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

///////���顢ָ�����ڴ��е����------------
/*
int main()
{
	char arr1[] = "abc";//arr1��arr2����ջ�ϣ����Ա����Ÿ��Եġ�abc��
	char arr2[] = "abc";
	char *p1 = "abc"; //p1��p2Ϊջ�ϵ�����������p1��p2ָ�������ͬ��һ���ַ
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
//-------------------------auto���������ǹ�ѯ��
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


//-----------------------------------------�������졢�����ֵ
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
//----------------------------------�̳�-----------------------
//����һ

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
//		cout << "��������" << endl;
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


//�����

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
//--------------------------------------��������-----------------------
////����ֵ���������;�Ϊint�͵�Max����
//int Max(int a, int b)
//{
//	if (a > b)
//		return a;
//	return b;
//}

////����ֵ���������;�Ϊdouble�͵�Max����
//double Max(double a, double b)
//{
//	if (a > b)
//		return a;
//	return b;
//}
//
////����ֵ���������;�Ϊchar�͵�Max����
//char Max(char a, char b)
//{
//	if (a > b)
//		return a;
//	return b;
//}
//
//int main()
//{
//	//int Max(int a, int b);//��������
//	//int Max��double a, int b);//��������
//	//int Max��char a, char b��;//��������
//	int i1, i2, i;
//	cin >> i1 >> i2;//������������
//	i = Max(i1, i2);//���������
//	cout<<"int_Max: " << i << endl;
//	double d1, d2, d;
//	cin >> d1 >> d2;//��������������
//	d = Max(d1, d2);//����󸡵���
//	cout << "double_Max: "<<d << endl;
//	char c1, c2, c;
//	cin >> c1 >> c2;//���������ַ�
//	c = Max(c1, c2);//������ַ�
//	cout <<"char_Max: "<< c << endl;
//	system("pause");
//	return 0;
//}
//------------------------------------------------------------
//����ֵ���������;�Ϊint�͵�Max������2��������
//int Max(int a, int b)
//{
//	if (a > b)
//		return a;
//	return b;
//}
//
////����ֵ���������;�Ϊint�͵�Max������3��������
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
//	i = Max(i1, i2);//�������������
//	i = Max(i1, i2, i3);//�������������
//	cout << "int_Max(i1,i2): " << Max(i1,i2) << endl;//�������������
//	cout << "int_Max(i1,i2��i3): " << Max(i1,i2,i3) << endl;//�������������
//	system("pause");
//	return 0;
//}


////����һ������ֵ����Ϊint������Ϊһ��int a��Test����
//int Test(int a)
//{
//	return a;
//}
//
////����һ������ֵ����Ϊdouble������Ϊһ��int a��Test����
//double Test(int a)
//{
//	return a;
//}
//
////����һ������ֵ����Ϊchar������Ϊһ��int a��Test����
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



//----------------------------------------��ģ��ʵ��һ������-----------------------------
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