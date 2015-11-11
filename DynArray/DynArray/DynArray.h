#ifndef _DYNARRAY_H_
#define _DYNARRAY_H_
#include "definitions.h"

#define BLOCK 16

template <class TYPE>

class DynArray
{
private:
	uint capacity;
	uint numElements;
	TYPE* data;
public:
	DynArray() :capacity(BLOCK), numElements(0)
	{
		data = new TYPE[capacity];
	}

	DynArray(uint nCapaity) :capacity(nCapaity), numElements(0)
	{
		data = new TYPE[capacity];
	}

	DynArray(const DynArray& Array) :numElements(Array.numElements)
	{
		capacity = MIN(Array.capacity, BLOCK);
		data = new TYPE[capacity];
		memcpy(data, Array.data, numElements*sizeof(TYPE));
	}

	~DynArray()
	{
		if (data != NULL)
			delete[] data;
	}

	void PushBack(const TYPE& item)
	{
		if (numElements >= capacity)
		{
			TYPE* tmp = data;
			capacity += BLOCK;
			data = new TYPE[capacity];
			memcpy(data, tmp, numElements * sizeof(TYPE));
			delete[]tmp;
		}
		data[numElements++] = item;
	}

	TYPE At(uint position)const
	{
		if (position > capacity)
		{
			printf("you cant put this position");
			return NULL;
		}
		return data[position];
	}

	uint Capacity() const
	{
		return capacity;
	}

	uint Size() const
	{
		return numElements;
	}

	void Clear()
	{
		if (numElements != NULL)
		{
			numElements = 0;
		}
	}

	bool Empty() const
	{
		return numElements == 0;
	}
};



#endif _DYNARRAY_H_