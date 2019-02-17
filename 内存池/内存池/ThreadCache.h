#pragma once

#include"common.h"

class ThreadCache
{
public:
	//获取一块size大小的内存
	void* Allocate(size_t size);

	//到中心块取内存
	void* FetchFromCentralCache(size_t index, size_t size);
private:
	FreeList _freelist[NLISTS];
};