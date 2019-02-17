#pragma once

#include"common.h"

class ThreadCache
{
public:
	//��ȡһ��size��С���ڴ�
	void* Allocate(size_t size);

	//�����Ŀ�ȡ�ڴ�
	void* FetchFromCentralCache(size_t index, size_t size);
private:
	FreeList _freelist[NLISTS];
};