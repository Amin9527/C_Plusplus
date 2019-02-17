#include"ThreadCache.h"
#include"CentralCache.h"

//到中心块取内存
void* ThreadCache::FetchFromCentralCache(size_t index, size_t bytes)
{
	FreeList* freelist = &_freelist[index];
	size_t num_to_move = min(ClassSize::NumMoveSize(bytes), freelist->MaxSize());
	void *start, *end;
	size_t fetchnum = CentralCache::GetInstance()->FetchRangeObj(start, end, num_to_move, bytes);
}


void* ThreadCache::Allocate(size_t size)
{
	assert(size <= MAXBYTES);

	//对齐取整
	size = ClassSize::Roundup(size);
	//计算取整后内存块对应freelist链表中的位置
	size_t index = ClassSize::Index(size);
	FreeList* freelist = &_freelist[index];
	if (!freelist->Empty)
	{
		return freelist->Pop();//取出相应位置内存块并返回
	}
	else
	{
		return FetchFromCentralCache(index, size);//到中心块取内存
	}
}