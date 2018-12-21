#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<assert.h>
using namespace std;
typedef char T;

//��ӡ
void print_list(list<T> s1)
{
	if (s1.size() == 0)
	{
		cout << "����Ϊ�գ�" << endl;
		return;
	}
	list<T>::iterator it = s1.begin();
	for (it; it != s1.end();++it)
		cout << *it << " ";
	cout << endl;

}

//����Ԫ��-���ظ�Ԫ�ص�ַ
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
	cout << "δ�ҵ���Ԫ�أ�" << endl;
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

	

	//ͷ��
	s1.push_front('m');
	print_list(s1);//��ӡ

	//ͷɾ
	s1.pop_front();
	print_list(s1);

	//β��
	s1.push_back('j');
	print_list(s1);

	//βɾ
	s1.pop_back();
	print_list(s1);


	//������
	list<T>::iterator it = s1.begin();

	//����λ�ò���
	s1.insert(++it, 'p');//��һ������Ϊ����ĵ�ַ���ڶ�������ΪҪ�����Ԫ��
	print_list(s1);

	//����list
	s1.insert(s1.end(), s2.begin(), s2.end());//��һ������Ϊ�������ʼλ�ã��ڶ�������Ϊ�����������ʼλ�ã�����������Ϊ��������Ľ���λ��
	print_list(s1);

	//��������
	s1.insert(s1.begin(),arr1,arr1+2);//��һ������Ϊ�������ʼλ�ã��ڶ�������Ϊ�����������ʼλ�ã�����������Ϊ��������Ľ���λ��
	print_list(s1);

	//�������
	//s1.clear();
	//print_list(s1);

	//ɾ��ָ��Ԫ��
	s1.remove(5);
	print_list(s1);

	//ƴ������
	s1.splice(s1.begin(), s2);//�ڵ�һ������֮ǰƴ�������ڶ���������
	print_list(s1);

	//����Ԫ��-���ظ�Ԫ�ص�ַ
	T* ret = find_node(s1, 'c');
	cout << *ret << endl;

	//��������--Ĭ������
	s1.sort();
	print_list(s1);

	//ɾ��Ԫ��--����ַ
	s1.erase(++s1.begin());
	print_list(s1);

	system("pause");
	return 0;
}