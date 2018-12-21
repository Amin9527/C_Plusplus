#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<assert.h>
using namespace std;
typedef char T;

//打印
void print_list(list<T> s1)
{
	if (s1.size() == 0)
	{
		cout << "链表为空！" << endl;
		return;
	}
	list<T>::iterator it = s1.begin();
	for (it; it != s1.end();++it)
		cout << *it << " ";
	cout << endl;

}

//查找元素-返回该元素地址
T* find_node(list<T> s1,T n)
{
	list<T>::iterator it = s1.begin();
	for (it; it != s1.end(); ++it)
	{
		if (*it == n)
		{
			return &(*it);
		}
	}
	cout << "未找到该元素！" << endl;
	return NULL;
}

int main()
{
	T arr[] = { 'a','b','c','d','e' };
	T arr1[] = { 'f','g','h'};
	list<T> s1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	list<T> s2(3, 'z');
	list<T> s3{ 'g','x' };
	list<T> s4(s1);

	

	//头插
	s1.push_front('m');
	print_list(s1);//打印

	//头删
	s1.pop_front();
	print_list(s1);

	//尾插
	s1.push_back('j');
	print_list(s1);

	//尾删
	s1.pop_back();
	print_list(s1);


	//迭代器
	list<T>::iterator it = s1.begin();

	//任意位置插入
	s1.insert(++it, 'p');//第一个参数为插入的地址，第二个参数为要插入的元素
	print_list(s1);

	//插入list
	s1.insert(s1.end(), s2.begin(), s2.end());//第一个参数为插入的起始位置，第二个参数为插入链表的起始位置，第三个参数为插入链表的结束位置
	print_list(s1);

	//插入数组
	s1.insert(s1.begin(),arr1,arr1+2);//第一个参数为插入的起始位置，第二个参数为插入数组的起始位置，第三个参数为插入数组的结束位置
	print_list(s1);

	//清空链表
	//s1.clear();
	//print_list(s1);

	//删除指定元素
	s1.remove(5);
	print_list(s1);

	//拼接链表
	s1.splice(s1.begin(), s2);//在第一个参数之前拼接链表（第二个参数）
	print_list(s1);

	//查找元素-返回该元素地址
	T* ret = find_node(s1, 'c');
	cout << *ret << endl;

	//链表排序--默认升序
	s1.sort();
	print_list(s1);

	//删除元素--按地址
	s1.erase(++s1.begin());
	print_list(s1);

	system("pause");
	return 0;
}