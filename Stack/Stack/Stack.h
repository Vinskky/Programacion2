#ifndef _STACK_H_
#define _STACK_H_
#include "DLinkedList.h"

template <class TYPE>

class Stack
{
private:
	DLinkedList<TYPE> list;
public:
	Stack(){}

	~Stack(){}

	void Push(const TYPE& data)
	{
		list.PushBack(data);
	}

	bool Pop(TYPE& data)
	{
		return list.PopBack(data);
	}

	/*bool Peek(TYPE& data) const
	{
		if(list.GetFirst() != NULL)
		{
			data = list.GetLast()->data;
			return true;
		}
		return false;
	}*/
};



#endif