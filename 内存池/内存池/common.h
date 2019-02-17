#pragma once
#include<iostream>
#include<assert.h>

#ifdef _WIN32
#include<windows.h>
#endif

using std::cout;
using std::endl;

//������������ĳ���
const size_t NLISTS = 240;
const size_t MAXBYTES = 64 * 1024;
const size_t PAGE_SHIFT = 12;
const size_t NPAGES = 129;

static inline void*& NEXT_OBJ(void *obj)
{
	return *((void**)obj);
}

class FreeList
{
public:
	bool Empty()
	{
		return _list == nullptr;
	}

	void* Clear()
	{
		_size = 0;
		void *list = _list;
		_list = nullptr;
		return list;
	}

	void *Pop()
	{
		void *obj = _list;
		_list = NEXT_OBJ(obj);
		--_size;
		return obj;
	}


	void push(void* obj)
	{
		NEXT_OBJ(obj) = _list;
		_list = obj;
		++_size;
	}

	size_t Size()
	{
		return _size;
	}

	size_t MaxSize()
	{
		return _maxsize;
	}
private:
	void *_list = nullptr;
	size_t _size = 0;
	size_t _maxsize = 1;
};


struct Span
{
	size_t _pageid = 0;  //ҳ��
	size_t _npage = 0;   //ҳ������

	Span* _prev = nullptr;  //ָ��ǰһ������ָ��
	Span* _next = nullptr;  //ָ���һ���ڵ��ָ��
	
	void* _objlist = nullptr;  //������������
	size_t _objsize = 0;       //�����С
	size_t _usecount = 0;      //ʹ�ü���

};

//��ͷ˫��ѭ������span
class SpanList
{
public:
	SpanList()
	{
		_head = new Span();
		_head->_next = _head;
		_head->_prev = _head;
	}

	Span* begin()
	{
		return _head->_next;
	}

	Span* end()
	{
		return _head->_prev;
	}

	bool Empty()
	{
		return _head = _head->_next;
	}

	void Insert(Span* cur, Span* newspan)
	{
		assert(cur);
		Span* prev = cur->_prev;

		//prev  newspan  next
		prev->_next = newspan;
		newspan->_prev = prev;
		cur->_prev = newspan;
		newspan->_next = cur;
	}

	void Erase(Span* cur)
	{
		assert(cur && cur != _head);
		Span* prev = cur->_prev;
		Span* next = cur->_next;

		prev->_next = next;
		next->_prev = prev;
	}

	void PushFront(Span* span)
	{
		Insert(begin(), span);
	}
	Span* PopFront()
	{
		Span* span = begin();
		Erase(span);
		return span;
	}

	~SpanList()
	{

	}
private:
	Span* _head = nullptr;
};

class ClassSize
{
	//������12%���ҵ�����Ƭ�˷�
	//��1 ,128��           8�ֽڶ��� freelist��0,16��
	//��129 , 1024��       16�ֽڶ��� freelist��16,72��
	//��1025,8*1024��      128�ֽڶ��� freelist��72,128��
	//��8*1024+1,64*1024�� 512�ֽڶ��� freelist��128,240��

public:
	//���ֽ�������ȡ��
	static inline size_t _Roundup(size_t size, size_t align)
	{
		return (size + align - 1) & ~(align - 1);
	}

	static inline size_t Roundup(size_t size)
	{
		assert(size <= MAXBYTES);

		if (size <= 128)
		{
			return _Roundup(size, 8);
		}
		else if (size <= 1024)
		{
			return _Roundup(size, 16);
		}
		else if (size <= 8192)
		{
			return _Roundup(size, 128);
		}
		else if (size <= 65536)
		{
			return _Roundup(size, 512);
		}
		else
		{
			return -1;
		}
	}

	static inline size_t _Index(size_t bytes, size_t align_shift)
	{
		return bytes >> align_shift-1;
	}

	static inline size_t Index(size_t bytes)
	{
		assert(bytes <= MAXBYTES);

		//ÿ������������������
		static int group_array[4] = { 16 ,56 ,56 ,112 };

		if (bytes <= 128)
		{
			return _Index(bytes, 3);
		}
		else if (bytes <= 1024)
		{
			return _Index(bytes - 128, 4) + group_array[0];
		}
		else if (bytes <= 8192)
		{
			return _Index(bytes - 1024, 7) + group_array[0] + group_array[1];
		}
		else if (bytes <= 65536)
		{
			return _Index(bytes - 8192, 9) + group_array[0] + group_array[1]
				+ group_array[2];
		}
		else
		{
			return -1;
		}
	}

	//�����ڴ��ĸ���
	static size_t NumMoveSize(size_t bytes)
	{
		if (bytes == 0)
		{
			return 0;
		}
		size_t num = MAXBYTES / bytes;
		if (num <= 1)
		{
			return 2;
		}
		else if (num >= 512)
		{
			return 512;
		}
		return num;
	}
	
	//������Ҫ����ҳ�ĸ���
	static size_t NumMovePage(size_t bytes)
	{
		size_t num = NumMoveSize(bytes);
		size_t npage = num * bytes;
		npage >>= 12;
		if (npage == 0)
			npage = 1;
		return npage;
	}
};