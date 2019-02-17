#pragma once
#include"common.h"

//����ģʽ��CentralCache
class CentralCache
{
public:
	static CentralCache* GetInstance()
	{
		return &_inst;
	}

	//��ȡһ��span
	Span* GetOneSpan(SpanList* spanlist, size_t bytes);

	//�����Ļ�ȡһ�������Ķ����threadcache
	size_t FetchRangeObj(void*& start, void*& end, size_t n, size_t bytes);
private:
	//���Ļ�����������
	SpanList _spanlist[NLISTS];
private:
	CentralCache() = default;  //ʹ��Ĭ�ϵĹ��캯��
	CentralCache(const CentralCache&) = delete;
	CentralCache& operator=(const CentralCache&) = delete;

	static CentralCache _inst;
};