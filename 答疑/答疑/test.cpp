//#define _CRT_SECURE_NO_WARNINGS 1
#include<map>
#include<vector>
#include<string>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>

#include"zm.h"

using namespace std;

//---------------逢七过(7的倍数，或者个位数为7)
//七个人，每次都是自己开始喊数，第一次喊数的范围为1-6；
/*
typedef struct node
{
	int element;
	int count;
}node;

void fun(int count, int &pn)
{
	if (count < 200)
	{
		if (count % 7 == 0 || count % 10 == 7)
		{
			pn++;
			fun(count + 7, pn);
		}
		else
			fun(count + 7, pn);
	}
}

node func(int pn)
{
	node n;
	int min = 200;
	for (int i = 1; i<7; ++i)
	{
		int count = 0;
		fun(i, count);
		cout << i << "->" << count << endl;
		if (count < min)
		{
			min = count;
			n.count = min;
			n.element = i;
		}
		//min = min < count ? min : count;
	}
	return n;
}

int main()
{
	node less = func(7);
	cout << "element: " << less.element << endl;
	cout << "count: " << less.count << endl;
	system("pause");
	return 0;
}
*/

//-------------------数组旋转---

/*
void shift(int *input, int len, int dist)
{
	int t = 0;
	//int end = len - 1;
	while (dist)
	{
		t = input[len - 1];
		int end = len - 1;
		while (end != 0)
		{
			input[end] = input[end - 1];
			end--;
		}
		input[end] = t;
		--dist;
	}

	for (int j = 0; j < 5; j++)
	{
		cout << input[j] << " ";
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	shift(arr, 5, 6);
	system("pause");
	return 0;
}
*/
/*

//---------------------堆排序--heap--

class Heap
{
public:
	Heap(int *arr, int size) :_arr(arr), _size(size)
	{
		int child = _size - 1, parent = (child - 1) / 2;
		while (parent >= 0)
		{
			AdjustDown(parent, _size);
			--parent;
		}
	}

	void swap(int *a, int *b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}

	void AdjustDown(int parent, int size)
	{
		int child = parent * 2 + 1;
		while (child < size)
		{
			if ((child + 1) < size && _arr[child] < _arr[child + 1])
				child = child + 1;
			if (_arr[child] > _arr[parent])
			{
				swap(&_arr[child], &_arr[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				parent = child;
				child = parent * 2 + 1;
			}
		}
	}

	void upsort()
	{
		int count = _size - 1;
		int parent = 0;
		while (count)
		{
			swap(&_arr[0], &_arr[count]);
			AdjustDown(0, count);
			--count;
		}
	}
private:
	int *_arr;
	int _size;
};

int main()
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(arr) / sizeof(int);
	Heap h(arr, len);
	for (int i = 0; i < len; ++i)
		cout << arr[i] << " ";
	cout << endl;
	h.upsort();
	for (int i = 0; i < len; ++i)
		cout << arr[i] << " ";
	system("pause");
	return 0;
}

*/
//----------不创建变量，交换两个数----
/*
int main()
{
	int a = 1, b = 2;
	cout << " " << a << " " << b << endl;
	//缺陷：a = a + b；时，可能会超出表示范围
	a = a + b;
	b = a - b;
	a = a - b;
	cout << " " << a << " " << b << endl;

	//异或：二进制位相同为0，不同为1
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	cout << " " << a << " " << b << endl;
	system("pause");
	return 0;
}
*/
//-----------------------------
/*
int main()
{
	cout << 1 / 2 << endl;  //0
	cout << 1 % 2 << endl;  //1
	cout << -1 / 2 << endl; //0
	cout << -1 % 2 << endl; //-1
	cout << -3 / 2 << endl; //-1
	cout << -3 % 2 << endl; //-1
	system("pause");
	return 0;
}
*/
//------------冒泡排序------
/*
void fun(int arr[10])
{
	int i = 0, j = 0;
	for (i = 0; i < 10; ++i)
	{
		for (j = 1; j < 10 - i; ++j)
		{
			int s = 0;
			if (arr[j] < arr[j-1])
			{
				s = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = s;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arr[10] = { 3, 6, 2, 1, 5, 7, 4, 9, 0, 8 };
	fun(arr);
	system("pause");
	return 0;
}
*/




/*
int main()
{
	int *p = new int[5]();
	cout << p[0] << endl;
	cout << p[1] << endl;
	delete p;
	cout << p[0] << endl;
	cout << p[1] << endl;
	system("pause");
	return 0;
}
*/
/*
class Test
{
public:
	static void fun(){ fun2() } //error
	void fun1(){ fun(); }
	void fun2(){}
private:
public:
	static int a;
	int b;
};

int main()
{
	Test t;
	t.fun();
	Test::fun();
	Test::fun2(); //error
	Test::a;
	Test::b; //error
	t.b;
	t.a;
	return 0;
}
*/
//--------------------------------------------
//将B字符串插入到A字符串中的任意位置，使之构成回文字符串，计算插入方法
/*
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int sum = 0;
	for (int i = 0; i < (s1.size() + 1); ++i)
	{
		string s3;
		if (i == 0) //在s1的头部插入
		{
			s3 = s2 + s1;
		}
		else if (i == s1.size()) //在s1的尾部插入
		{
			s3 = s1 + s2;
		}
		else  //在s1的中间插入
		{
			s3 = s1.substr(0, i) + s2 + s1.substr(i);
		}
		int start = 0, end = s3.size() - 1;
		while (start < end)  //检测s3是不是回文
		{
			if (s3[start] == s3[end])
			{
				start++;
				end--;
			}
			else
				break;
		}
		if (start >= end)
			sum++;
	}
	cout << sum << endl;
	return 0;
}
*/

//-------------------------------------
//计算数组中最长的相邻两数和是0的长度
/*
int main()
{
	int s;
	cin >> s;
	int arr[] = {1,1,-1,1,-1};
	int max = 0;
	int count = 0;
	for (int i = 1; i < s; i+=2)
	{
		if (arr[i - 1] + arr[i] == 0)
		{
			count += 2;
		}
		else
		{
			max = max>count ? max : count;
			count = 0;
			i--;
		}
	}
	if (count == 0)
		cout << max << endl;
	else
		cout << count << endl;
	system("pause");
	return 0;
}
*/

//---------------------------
//计算最少的合成很赞数的次数
//1、2  5（两次）--2、3--3、5--

/*
int main()
{
	int x, y, m;
	cin >> x >> y >> m;
	int max = 0;
	int count = 0;
	while ((x < m) && (y < m))
	{
		max = x > y ? x : y;

		
		if (x >= y)
		{
			max = x;
			x = x + y;
			y = max;
			count++;
		}
		else
		{
			max = y;
			y = x + y;
			x = max;
			count++;
		}
	
	}
	cout << count << endl;
	system("pause");
	return 0;
}
*/

//-----------------------------------------------------------------
//“斗牛”是一种热门的扑克游戏，每个人5张牌，其中A当1，JQK都当10。要求：从5张牌中选出3张牌（必须刚好3张），如果存在3张牌加起来是10或者20或者30，就称为“有牛”，否则就是“没牛”。
//有牛的情况下，剩余两张牌加起来除以10后：
//? 余数为0就是“牛牛”，是最大的一手牌。
//? 如果余数为9就是“牛九”，是第二大的，依次类推，“牛一”就是最小。
//? “有牛”都大于“没牛”。
//? 两人都是没牛的情况下，比最大的一张牌谁大（注意A最大，2最小），最大一张牌一样则比较第二张牌，依次类推。
//请写一段代码，验证两手牌哪一个最大。
//输入是长度为5的两个字符串，表示两手牌。字符串内容是23456789TJQKA，注意为了让字符串长度一致，我们用T代表10。
//请输出一个值：1表示第一手牌大， - 1表示后一手牌更大，0表示一样大。
//示例：
//输入 "4579K", "AAAA2", 输出：1
//因为4 + 7 + 9 = 20（有牛），剩下两张牌5 + K是牛五，后一手牌没牛，所以前者更大。

/*
int GetMax(int a, int b, int c, int d, int e)
{
	int max = 0;
	max = a > b ? a : b;
	max = max > c ? max : c;
	max = max > d ? max : d;
	max = max > e ? max : e;
	return max;
}

int T(char a, char b, char c, char d, char e, int &index)
{
	int a1, b1, c1, d1, e1;

	if (a == 'T' || a == 'J' || a == 'Q' || a == 'K')
		a1 = 10;
	else if (a == 'A')
		a1 = 11;
	else
		a1 = a - '0';

	if (b == 'T' || b == 'J' || b == 'Q' || b == 'K')
		b1 = 10;
	else if (b == 'A')
		b1 = 11;
	else
		b1 = b - '0';

	if (c == 'T' || c == 'J' || c == 'Q' || c == 'K')
		c1 = 10;
	else if (c == 'A')
		c1 = 11;
	else
		c1 = c - '0';

	if (d == 'T' || d == 'J' || d == 'Q' || d == 'K')
		d1 = 10;
	else if (d == 'A')
		d1 = 11;
	else
		d1 = d - '0';

	if (e == 'T' || e == 'J' || e == 'Q' || e == 'K')
		e1 = 10;
	else if (e == 'A')
		e1 = 11;
	else
		e1 = e - '0';

	if ((a1 + b1 + c1) / 10 != 0 && (a1 + b1 + c1) % 10 == 0)
	{
		index = 1;
		return (d1 + e1) % 10;
	}
	int max = GetMax(a1, b1, c1, d1, e1);
	return max;
}

int Test(string &s, int &index)
{
	int a1 = 0;
	int a = T(s[0], s[1], s[2], s[3], s[4], a1);
	int b1 = 0;
	int b = T(s[0], s[1], s[3], s[2], s[4], b1); 
	int c1 = 0;
	int c = T(s[0], s[1], s[4], s[3], s[2], c1);
	int d1 = 0;
	int d = T(s[0], s[3], s[2], s[1], s[4], d1);
	int e1 = 0;
	int e = T(s[0], s[4], s[2], s[3], s[1], e1);
	int f1 = 0;
	int f = T(s[0], s[4], s[3], s[0], s[1], e1);
	int g1 = 0;
	int g = T(s[1], s[4], s[2], s[3], s[0], e1);
	int h1 = 0;
	int h = T(s[1], s[2], s[3], s[0], s[4], e1);
	int i1 = 0;
	int i = T(s[1], s[3], s[4], s[0], s[2], e1);
	int j1 = 0;
	int j = T(s[2], s[3], s[4], s[0], s[1], e1);

	int max = 0;
	if (a1 == 1 || b1 == 1 || c1 == 1 || d1 == 1 || e1 == 1 || f1 == 1 || g1 == 1 || h1 == 1 || i1 == 1 || j1 == 1)
	{
		index = 1;
		if (a1 == 1)
			max = a;
		if (b1 == 1)
			max = max > b ? max : b;
		if (c1 == 1)
			max = max > c ? max : c;
		if (d1 == 1)
			max = max > d ? max : d;
		if (e1 == 1)
			max = max > e ? max : e;
		if (f1 == 1)
			max = max > f ? max : f;
		if (g1 == 1)
			max = max > g ? max : g;
		if (h1 == 1)
			max = max > h ? max : h;
		if (i1 == 1)
			max = max > i ? max : i;
		if (j1 == 1)
			max = max > j ? max : j;
	}
	else
	{
		max = a > b ? a : b;
		max = max > c ? max : c;
		max = max > d ? max : d;
		max = max > e ? max : e;
		max = max > f ? max : f;
		max = max > g ? max : g;
		max = max > h ? max : h;
		max = max > i ? max : i;
		max = max > j ? max : j;
	}
	return max;
}

int main()
{
	string s1, s2;
	cin >> s1;
	cin >> s2;
	int index_s1 = 0;
	int index_s2 = 0;
	int m1 = Test(s1, index_s1);
	int m2 = Test(s2, index_s2);
	if (index_s1 > index_s2)
		cout << "前者大，前面有牛、后面无牛" << endl;
	else if (index_s1 == index_s2 && index_s1 == 0)
	{
		if (m1 > m2)
			cout << "前者大，都无牛" << endl;
		else if (m1 == m2)
			cout << "一样大，都无牛" << endl;
		else
			cout << "后者大，都无牛"<<endl;
	}
	else if (index_s1 == index_s2 && index_s1 == 1)
	{
		if (m1 > m2)
			cout << "前者大，都有牛" << endl;
		else if (m1 == m2)
			cout << "一样大，都有牛" << endl;
		else
			cout << "后者大，都有牛" << endl;
	}
	else
		cout << "后者大,前者无牛、后者有牛" << endl;
	system("pause");
	return 0;
}
*/

//-----------------------------------------------------------------------
//#define SUM 5
//
//void GetArr(int *&arr1, int *&arr2)
//{
//	arr1 = new int[SUM];
//	arr2 = new int[SUM];
//	for (int i = 0; i < SUM; ++i)
//	{
//		cin >> arr1[i];
//	}
//	for (int i = 0; i < SUM; ++i)
//	{
//		cin >> arr2[i];
//	}
//}
//
//int main()
//{
//	int *arr1, *arr2;
//	GetArr(arr1, arr2);
//	int k = 0;
//	for (int i = 0; i < SUM; ++i)
//	{
//		for (int j = k; j < SUM; ++j)
//		{
//			if (arr1[i] == arr2[j])
//			{
//				k = j;
//				cout << arr1[i] << " ";
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}

/*
class Test
{
public:
	Test(){}
	//Test(int x = 0, int y = 1):a(x),b(y){}
	//Test(int x, int y) :a(x), b(y){}
	Test(int x){}
	Test(int x , int y = 0) :a(x), b(y){}
private:
	int a;
	int b;
};

int main()
{
	Test t;
	return 0;
}
*/
////---------------map、nultimap、set、nultiset---
///*
//void MapTest()
//{
//	map<int, char> m{ { 1, 'a' }};
//	cout << m[1] << endl;
//	cout << m.size() << endl;
//	m.insert({ 2, 'a' });
//	cout << m[2] << endl;
//	cout << m.size() << endl;
//}
//
//int main()
//{
//	MapTest();
//	system("pause");
//	return 0;
//}
//*/
/////////数组、指针在内存中的情况------------
///*
//int main()
//{
//	char arr1[] = "abc";//arr1、arr2都在栈上，各自保存着各自的“abc”
//	char arr2[] = "abc";
//	char *p1 = "abc"; //p1、p2为栈上的两个变量，p1、p2指向堆上相同的一块地址
//	char *p2 = "abc";
//	return 0;
//}
//*/
///////////////////////////////////////////////////
///*
//#include<stdio.h>
//void fun()
//{
//	int b = 10;
//	*(((int*)*(&b + 2)) - 2) = 20;
//}
//
//int main()
//{
//	int a = 0;
//	fun();
//	printf("%d\n", a);
//	return 0;
//}
//*/
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


//-----------------找字符串中最长数字串---
/*

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int len = 0;
	char *start = nullptr, *end = nullptr;
	char *str = new char[256];
	cin >> str;
	cout << str;
	//auto it = str.begin();
	char *it = nullptr;
	char *ptr = nullptr;
	int index = 0;
	for (it = str; *it != '\0'; ++it)
	{

		if ('9' - (*it) <= 9 && '9' - (*it) >= 0 && index == 0)
		{
			ptr = it;
			index = 1;
		}
		if ('9' - (*it) > 9 || '9' - (*it) < 0 && index == 1)
		{
			if ((it - ptr) > len)
			{
				start = ptr;
				end = it;
				len = it - ptr;
				index = 0;
			}
		}
	}
	string s(start, end);
	cout << s;
	return 0;
}
*/