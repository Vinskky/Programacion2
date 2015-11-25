#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "DynArray.h"

template <class TYPE>

class Queue
{
private:
	DynArray<TYPE> dynArray;
public:
	
	void Push(const TYPE& data)
	{
		dynArray.PushBack(data);
	}

	Peek()const
	{

	}

	bool Pop(TYPE& data)
	{

	}
};


#endif