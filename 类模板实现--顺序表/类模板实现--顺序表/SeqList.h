#include<iostream>
using namespace std;

template<typename T>
class SeqList
{
public:
	SeqList(T* array, size_t size);
	SeqList(const SeqList& m);
	~SeqList()
	{
		if (_array)
		{
			delete[] _array;
			_size = 0;
			_capacity = 0;
		}
	}
	void AddCapacity();
	void insert(int pos, T m);
	void pushback(T m);
	void pop(T m);
	void ForentPush(T m);
	size_t _size;
	T* _array;
	size_t _capacity;
};

//#define _CRT_SECURE_NO_WARNINGS 1

//#include"Seqlist.h"

//���캯��
template<typename T>
SeqList<T>::SeqList(T* array, size_t size)
:_array(new T[size])
, _size(size)
, _capacity(size)
{
	for (int i = 0; i < size; i++)
		_array[i] = array[i];
}
//�������캯��
template<typename T>
SeqList<T>::SeqList(const SeqList& m)
{
	_size = m._size;
	_array = m._array;
	_capacity = m._capacity;
}

//����
template<typename T>
void SeqList<T>::AddCapacity()
{
	T* p = new T[_capacity * 2];
	memcpy(p, _array, _size*sizeof(T));
	delete[] _array;
	_array = p;
	_capacity = 2 * _capacity;
}
//����Ԫ��--β��
template<typename T>
void SeqList<T>::pushback(T m)
{
	if (_size == _capacity)
	{
		AddCapacity();
	}
	_array[_size] = m;
	_size++;
}

//ɾ��ָ��Ԫ��
template<typename T>
void SeqList<T>::pop(T m)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < _size; i++)
	{
		if (_array[i] == m)
		{
			for (j = i; j < _size; j++)
			{
				_array[j] = _array[j + 1];
			}
			_size--;
		}
	}
	if (j == 0)
	{
		cout << "û�и�Ԫ�أ�" << endl;
		return;
	}
}

//����λ�ò���Ԫ��
template<typename T>
void SeqList<T>::insert(int pos, T m)
{
	int i = 0;
	if (_size == _capacity)
		AddCapacity();
	if (_size == 0)
	{
		pushback(m);
		return;
	}
	for(i = _size; i >= pos; i--)
	{
		_array[i] = _array[i - 1];
	}
	_array[pos - 1] = m;
	_size++;
}

//����Ԫ��--ͷ��
template<typename T>
void SeqList<T>::ForentPush(T m)
{
	if (_size == _capacity)
		AddCapacity();
	int i = 0;
	for (i = _size; i > 0; i--)
	{
		_array[i] = _array[i - 1];
	}
	_array[i] = m;
}
