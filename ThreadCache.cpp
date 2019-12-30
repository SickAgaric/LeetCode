#pragma once

#include"ThreadCache.h"

void*  TheadCache::ALLocte(size_t size)
{
	size_t index = 0;//= Index(size);
	FreeList& freeList = _freeLists[index];

	if (!freeList.Empty())//自由链表有，从自己的地方取
	{
		return freeList.Pop();
	}
	else//没有从中心cache取
	{
		size_t num = 20;
		return FetchFromCentralCache(index, num);
	}
}
void TheadCache::DealLocte(void* ptr, size_t size)
{
	size_t index = SizeClass::ListIndex(size);
	FreeList& freeList = _freeLists[index];
	freeList.Push(ptr);

	//if ()
	{
		//自由链表太长之后归还给CentralCache
	}
}

void* TheadCache::FetchFromCentralCache(size_t index, size_t num)
{
	size_t size = (index + 1) * 8;
	char* start = (char*)malloc(size*num);
	char* cur = start;
	for (size_t i = 0; i < num; ++i)
	{
		char* next = cur + size;
		NextObj(cur) = next;

		cur = next;
	}

	NextObj(cur) = nullptr;

	void* head = NextObj(start);
	void* tail = cur;

	_freeLists[index].PushRange(head,tail);

	return start;
}
