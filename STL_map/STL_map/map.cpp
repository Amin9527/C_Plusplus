#include<iostream>
#include<map>
#include<string>

using namespace std;

void testmap()
{
	map<string, string> m = { {"apple","ƻ��"},{"banan","�㽶"},{"zhangmin","����"},{"zhangmin","����"} };
	
	cout << "Ԫ�ظ���Ϊ��" << m.size() << endl;

	cout << m["gaoxing"] << endl;  //operator[]����value������,���û��keyֵ�����Զ�����
	m["return"] =  "����" ;
	m.insert(make_pair("mother", "����"));

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