#pragma once

#include"common.h"

class PageCache
{
public:
	static PageCache* GetInstance()
	{
		return &_inst;
	}

	//获取一个span
	Span* NewSpan(size_t npage);
private:
	SpanList _pagelist[NPAGES];
private:
	PageCache() = default;
	PageCache(const PageCache&) = delete;
	PageCache& operator=(const PageCache&) = delete;

	static PageCache _inst;
};