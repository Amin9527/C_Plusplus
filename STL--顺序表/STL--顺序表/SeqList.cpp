#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>//vector���ͷ�ļ�
using namespace std;
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };

	//��������0��˳���
	vector<int> s1(2, 0);

	//ͨ����ַ������˳���
	vector<int> s2(arr, arr+sizeof(arr) / sizeof(arr[0]));

	//ͨ����������˳���
	vector<int> s3(s2);

	s3.push_back(0);//β��0
	s3.push_back(8);//β��8
	s3.pop_back();//βɾ

	//������
	vector<int>::iterator it = s3.begin();

	s3.insert(it+2,0);

	vector<int>::iterator is = s3.end();

	//����λ�ò��루λ�ã�Ԫ�أ�
	s3.insert(is - 3, 10);

	for (int i = 0; i<s3.size(); i++)
		cout << s3[i] << " ";
	cout << endl;

	//����λ��ɾ��
	s3.erase(s3.end()-1);

	//��ӡ˳���ÿ��Ԫ��
	for (int i = 0; i < s3.size(); i++)
		cout << s3[i] << " ";
	cout << endl;

	//s3.clear();//���

	for (int i = 0; i < s3.size(); i++)
		cout << s3[i] << " ";
	cout << endl;

	cout << s3.front() << endl;//���ص�һ��Ԫ�ص�����
	cout << s3.back() << endl;//�������һ��Ԫ�ص�����
	cout << *s3.begin() << endl;//���ص�һ��Ԫ�صĵ�ַ
	cout << *(s3.end()-1) << endl;//�������һ��Ԫ����һ��λ�õĵ�ַ���˷������һ��Ԫ����s3.end����-1


	system("pause");
	return 0;
}