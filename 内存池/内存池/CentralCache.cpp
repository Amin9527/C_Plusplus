#include"CentralCache.h"
#include"PageCache.h"
//��ȡһ��span
Span* GetOneSpan(SpanList* spanlist, size_t bytes)
{
	Span* span = spanlist->begin();//��ȡ��ͷ˫��ѭ������ͷ������һ���ڵ�
	while (span != spanlist->end())//ѭ����һ���ж����span
	{
		if (span->_objlist != nullptr)
			return span;
		span = span->_next;
	}

	//��CentralCache��û���ҵ�span����pagecache����һ���µĺ��ʴ�С��span

	size_t npage = ClassSize::NumMovePage(bytes);
	Span* newspan = PageCache::GetInstance()->NewSpan(npage);

	//��newspan���ڴ��и��һ����bytes��С�Ķ��������
	char* start = (char*)(newspan->_pageid << PAGE_SHIFT);
	char* end = start + (newspan->_npage << PAGE_SHIFT);
	char* cur = start;
	char* next = start+bytes;
	while (next < end)
	{
		NEXT_OBJ(cur) = next;
		cur = next;
		next += bytes;
	}
	NEXT_OBJ(cur) = nullptr;
	newspan->_objlist = start;
	newspan->_objsize = bytes;
	newspan->_usecount = 0;

	//��newspan���뵽SpanList��
	spanlist->PushFront(newspan);
	return newspan;
}

//�����Ļ�ȡһ�������Ķ����threadcache
size_t CentralCache::FetchRangeObj(void*& start, void*& end, size_t n, size_t bytes)
{
	size_t index = ClassSize::Index(bytes);//�ҵ��ô�С�ڴ��Ӧ���������λ�ñ�ʶ
	SpanList* spanlist = &_spanlist[index];//�ҵ��ô�С�ڴ��Ӧ���������λ��

	//��ȡһ��span
	Span* span = GetOneSpan(spanlist, bytes);
}