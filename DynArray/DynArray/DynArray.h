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
			printf("you cant put this position\n");
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

	TYPE operator[](uint position)const
	{
		if (position > capacity)
			return NULL;
		return data[position];
	}

	TYPE Pop_Back()
	{
		return data[--numElements];
	}

	void Flip()
	{
		TYPE* tmp = data;
		data = new TYPE[capacity];
		uint tmp2 = 0;
		for (uint i = (numElements - 1); i >= 0; i--)
		{
			data[tmp2++] = tmp[i];
		}
		delete[]tmp;
	}

	void Shrink_to_fit()
	{
		if (numElements != capacity)
		{
			TYPE* tmp = data;
			data = new TYPE[numElements];
			memcpy(data, tmp, numElements*sizeof(TYPE));
			delete[]tmp;
		}
	}

	void Insert(uint position, TYPE item)
	{
		numElements++;
		TYPE* tmp = data;
		if (numElements > capacity)
		{
			capacity += BLOCK;
			memcpy(data, tmp, (position - 1) *sizeof(TYPE));
			for (uint i = numElements; i > position; i--)
			{
				data[i] = tmp[i - 1];
			}
			delete[]tmp;
		}
		else
		{	
			for (uint i = (numElements - 1); i > position; i--)
			{
				data[i] = tmp[i - 1];
			}

		}
		data[position] = item;
	}
};



#endif _DYNARRAY_H_