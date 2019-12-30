#include"common.h"


class TheadCache
{
public:
	void* ALLocte(size_t size);//取内存
	void DealLocte(void* ptr, size_t size);//释放内存

	void* FetchFromCentralCache(size_t index,size_t size);//向CentralCache取
private:
	FreeList _freeLists[FREELIST_SIZE];//公共代码模块


#include<iostream>
using namespace std;

//不用宏，这种便于调试
const size_t MAX_SIZE = 64 * 1024;
const size_t FREELIST_SIZE = MAX_SIZE / 8;

inline void*& NextObj(void* obj)//避免频繁的调用产生过多消耗，使用内联
{
	return *((void**)obj);
}

class FreeList
{
public:
	void Push(void* obj)//不用了还给链表
	{
		//存下一个指针
	}

	void* Pop()//取
	{
		void* obj = _freelist;
		_freelist = NextObj(obj);
		return obj;
	}
	void PushRange(void* head, void* tail)
	{
		NextObj(tail) = _freelist;
		_freelist = head;
	}

	bool Empty()
	{
		return _freelist == nullptr;
	}
private:
	void* _freelist = nullptr;//这块不是对象，只管指针
	//因为没有构造函数，会生成默认的构造函数，默认的缺省值会初始化它
};

class SizeClass
{
public:
	static size_t ListIndex(size_t size)
	{
		if (size % 8 == 0)
		{
			return size / 8 - 1;
		}
		else
		{
			return size / 8;
		}
	}
};