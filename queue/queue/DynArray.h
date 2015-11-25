#ifndef _DYNARRAY_H_
#define _DYNARRAY_H_
#include "definitions.h"
#include <assert.h>

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

	bool At(uint position, TYPE& item) const
	{
		if (position < numElements)
		{
			item = data[position];
			return true;
		}
		return false;
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

	const DynArray& operator += (const DynArray& Array)
	{
		if (capacity < numElements + Array.numElements)
		{
			TYPE* tmp = data;
			capacity = numElements + Array.numElements;
			data = new TYPE[capacity];
			memcpy(data, tmp, numElements*sizeof(TYPE));
			delete[]tmp;
		}
			memcpy(data + numElements, Array.data, Array.numElements * sizeof(TYPE));
			numElements += Array.numElements;	
			return *this;
	}

	//to do operator = / [] /  Flip() /Pop_back() / Shrink_to_fit() / Inster()
	DynArray& operator = (const DynArray& Array)
	{
		if (capacity < Array.numElements)
		{
			TYPE* tmp = data;
			capacity = Array.numElements;
			data = new TYPE[capacity];
			memcpy(data, tmp, Array.numElements * sizeof(TYPE));
			delete[]tmp;
		}
		memcpy(data, Array.data, Array.numElements*sizeof(TYPE));
		return *this;
	}

	const TYPE& operator[](uint position)const
	{
		assert(position < numElements)
			return data[position];
	}

	TYPE& operator[](uint position)
	{
		assert(position < numElements)
			return data[position];
	}

	bool Pop_Back(TYPE& value)
	{
		if (numElements > 0)
		{
			value = data[--numElements];
			return true;
		}
		return false;
	}

	void Flip()//ok
	{
		for (uint i = 0; i < (numElements / 2); i++)
		{
			TYPE* tmp = data[i];
			data[i] = data[numElements - 1 - i];
			data[numElements - 1 - i] = tmp;
		}
	}

	void Shrink_to_fit()
	{
		if (numElements != capacity)
		{
			TYPE* tmp = data;
			data = new TYPE[numElements];
			capacity = numElements;
			memcpy(data, tmp, numElements*sizeof(TYPE));
			delete[]tmp;
		}
	}

	void Insert(uint position, TYPE item)
	{
		if (numElements >= capacity)
		{
			TYPE* tmp = data;
			capacity += BLOCK;
			data = new TYPE[capacity];
			memcpy(data, tmp, numElements*sizeof(TYPE));
			delete[]tmp;
		}
		for (uint i = numElements; i > position; i--)
		{
			data[i] = data[i - 1];
		}
		data[position] = item;
	}
};



#endif _DYNARRAY_H_