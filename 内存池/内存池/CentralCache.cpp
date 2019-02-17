#include"CentralCache.h"
#include"PageCache.h"
//获取一个span
Span* GetOneSpan(SpanList* spanlist, size_t bytes)
{
	Span* span = spanlist->begin();//获取带头双向循环链表头结点的下一个节点
	while (span != spanlist->end())//循环找一个有对象的span
	{
		if (span->_objlist != nullptr)
			return span;
		span = span->_next;
	}

	//在CentralCache中没有找到span，向pagecache申请一个新的合适大小的span

	size_t npage = ClassSize::NumMovePage(bytes);
	Span* newspan = PageCache::GetInstance()->NewSpan(npage);

	//将newspan的内存切割成一个个bytes大小的对象挂起来
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

	//将newspan插入到SpanList中
	spanlist->PushFront(newspan);
	return newspan;
}

//从中心获取一定数量的对象给threadcache
size_t CentralCache::FetchRangeObj(void*& start, void*& end, size_t n, size_t bytes)
{
	size_t index = ClassSize::Index(bytes);//找到该大小内存对应自由链表的位置标识
	SpanList* spanlist = &_spanlist[index];//找到该大小内存对应自由链表的位置

	//获取一个span
	Span* span = GetOneSpan(spanlist, bytes);
}