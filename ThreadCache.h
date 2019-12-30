#include"common.h"


class TheadCache
{
public:
	void* ALLocte(size_t size);//取内存
	void DealLocte(void* ptr, size_t size);//释放内存

	void* FetchFromCentralCache(size_t index,size_t size);//向CentralCache取
private:
	FreeList _freeLists[FREELIST_SIZE];
};