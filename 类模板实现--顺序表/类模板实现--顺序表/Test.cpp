#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

int main()
{
	int array[] = { 1, 3, 5, 7 };
	int size = sizeof(array) / sizeof(array[0]);
	SeqList<int> s1(array, size);
    s1.pushback(9);
	s1.pop(1);
	s1.insert(3, 3);
	s1.ForentPush(1);
	char array1[] = {'a','b','c','d','e','f'};
	int size_c = sizeof(array1) / sizeof(array1[0]);
	SeqList<char> s2(array1, size_c);
	s2.pushback('g');
	s2.pop('c');
	system("pause");
	return 0;
}
