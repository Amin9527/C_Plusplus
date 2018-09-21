#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class student
{
public:
	student(string, int, char);
	void virtual display();
private:
	string name;
	int age;
	char sex;
};
student::student(string nam, int ag, char se):name(nam),age(ag),sex(se)
{
}
void student::display()
{
	cout << name << endl;
	cout << age << endl;
	cout << sex << endl;
}
class student1 :public student
{
public:
	student1(string, int, char, int);
	void display();
private:
	int hight;
};
student1::student1(string nam, int ag, char se, int high) :student(nam, ag, se), hight(high)
{

}
void student1::display()
{
	student::display();
		cout << hight << endl;

}
//class A
//{
//public:
//	void display();
//	int a;
//};
//class B :virtual public A
//{
//public:
//	void display();
//	int b;
//};
//class B1 :virtual public A
//{
//public:
//	void display();
//	int b1;
//};
//class C :public B,public B1
//{
//public:
//	void display();
//	int c;
//};
//int main()
//{
//	B bn;
//	B1 bn1;
//	C n;
//	n.a = 1;
//	n.b = 2;
//	n.b1 = 3;
//	n.c = 4;
//	cout << sizeof(A) << endl;
//	system("pause");
//}
int main()
{
	student stu("zhangmin", 22, 'M');
	student1 stu1("gaoxing", 20, 'W', 168);
	student* p = &stu;
	p->display();
	p = &stu1;
	p->display();
	system("pause");
}