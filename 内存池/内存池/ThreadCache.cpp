#include"ThreadCache.h"
#include"CentralCache.h"

//�����Ŀ�ȡ�ڴ�
void* ThreadCache::FetchFromCentralCache(size_t index, size_t bytes)
{
	FreeList* freelist = &_freelist[index];
	size_t num_to_move = min(ClassSize::NumMoveSize(bytes), freelist->MaxSize());//num_to_move����Ҫ�������ĸ���
	void *start, *end;
	size_t fetchnum = CentralCache::GetInstance()->FetchRangeObj(start, end, num_to_move, bytes);//fetch��ʵ������Ķ������
	if (fetchnum > 1)
	{
		freelist->PushRange(NEXT_OBJ(start), end, fetchnum - 1);
	}

	return start;
}


void* ThreadCache::Allocate(size_t size)
{
	assert(size <= MAXBYTES);

	//����ȡ��
	size = ClassSize::Roundup(size);
	//����ȡ�����ڴ���Ӧfreelist�����е�λ��
	size_t index = ClassSize::Index(size);
	FreeList* freelist = &_freelist[index];
	if (!freelist->Empty())
	{
		return freelist->Pop();//ȡ����Ӧλ���ڴ�鲢����
	}
	else
	{
		return FetchFromCentralCache(index, size);//�����Ŀ�ȡ�ڴ�
	}
}