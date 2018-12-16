#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>//vector库的头文件
using namespace std;
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };

	//构造两个0的顺序表
	vector<int> s1(2, 0);

	//通过地址区域构造顺序表
	vector<int> s2(arr, arr+sizeof(arr) / sizeof(arr[0]));

	//通过拷贝构造顺序表
	vector<int> s3(s2);

	s3.push_back(0);//尾插0
	s3.push_back(8);//尾插8
	s3.pop_back();//尾删

	//迭代器
	vector<int>::iterator it = s3.begin();

	s3.insert(it+2,0);

	vector<int>::iterator is = s3.end();

	//任意位置插入（位置，元素）
	s3.insert(is - 3, 10);

	for (int i = 0; i<s3.size(); i++)
		cout << s3[i] << " ";
	cout << endl;

	//任意位置删除
	s3.erase(s3.end()-1);

	//打印顺序表每个元素
	for (int i = 0; i < s3.size(); i++)
		cout << s3[i] << " ";
	cout << endl;

	//s3.clear();//清空

	for (int i = 0; i < s3.size(); i++)
		cout << s3[i] << " ";
	cout << endl;

	cout << s3.front() << endl;//返回第一个元素的引用
	cout << s3.back() << endl;//返回最后一个元素的引用
	cout << *s3.begin() << endl;//返回第一个元素的地址
	cout << *(s3.end()-1) << endl;//返回最后一个元素下一个位置的地址，顾访问最后一个元素用s3.end（）-1


	system("pause");
	return 0;
}