#include<iostream>
#include<map>
#include<string>

using namespace std;

void testmap()
{
	map<string, string> m = { {"apple","苹果"},{"banan","香蕉"},{"zhangmin","二丢"},{"zhangmin","张敏"} };
	
	cout << "元素个数为：" << m.size() << endl;

	cout << m["gaoxing"] << endl;  //operator[]返回value的引用,如果没有key值，将自动增加
	m["return"] =  "返回" ;
	m.insert(make_pair("mother", "妈妈"));

	map<string, string>::iterator it = m.begin();
	for (; it != m.end(); ++it)
	{
		cout << (*it).first << "--->"<<(*it).second<<endl;
	}
	
	cout << m["zhangmin"] << endl;

	cout << m.size() << endl;
	for (auto e : m)
	{
		cout << e.first<< endl;
	}
}

int main()
{
	testmap();
	system("pause");
	return 0;
}