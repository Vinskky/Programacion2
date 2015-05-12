//Dynamic Array class
#include <stdio.h>
#include <assert.h>

#ifndef _DynamicArray_H_
#define _DynamicArray_H_

#define SIZE_MEM_BUFF 16

template <class TYPE>
class DynamicArray
{
private:
	TYPE* data;
	unsigned int numElements;
	unsigned int memCapacity;

	void Realloc(unsigned int newMem)
	{
		TYPE* tmp = data;
		memCapacity = newMem;
		data = new TYPE[memCapacity];
		if (numElements > memCapacity)
			numElements = memCapacity;

		if (tmp != NULL)
		{
			for (unsigned int i = 0; i < numElements; ++i)
				data[i] = tmp[i];

			delete[] tmp;
		}
	}

public:
	//Constructors
	DynamicArray():numElements(0), memCapacity(0), data(NULL)
	{
		Realloc(SIZE_MEM_BUFF);
	}

	DynamicArray( unsigned int cap) 
	{
		unsigned int numElements = 0;
		unsigned int memCapacity(cap);
		TYPE* data = NULL;
	}

	//destructor
	~DynamicArray()
	{
		delete data;
	}

	unsigned int GetCapacity()
	{
		return memCapacity;
	}

	//put value to the last place of the list
	void PushBack(const TYPE& value)
	{
		if (numElements >= memCapacity)
			Realloc(memCapacity + SIZE_MEM_BUFF);
		data[numElements] = value;
		numElements++;
	}

	//Remove the las numElements from the Dynamic Array
	bool Pop(TYPE& value)
	{
		if (numElements > 0)
		{
			value = data[numElements - 1];
			numElements--;
			return true;
		}
		return false;
	}

	//Remove all numElements
	void Clear()
	{
		numElements = 0;
	}
	
	bool Insert(unsigned int position, const TYPE& value)
	{
		if (position > numElements)
		{
			return false;
		}

		if (position == numElements)
		{
			PushBack(value);
			return true;
		}

		if (numElements + 1 > memCapacity)
			Alloc(memCapacity + SIZE_MEM_BUFF);

		for (unsigned int i = numElements; i > position; --i)
		{
			data[i] = data[i - 1];
		}

		data[position] = element;
		numElements++;

		return true;		
	}

	const int RemoveWastedMemory()
	{
		 if(numElements < memCapacity)
			{
				Realloc(numElements);
				int memRemoved = memCapacity - numElements;
				return memRemoved;
			}		
	}
	TYPE* At(unsigned int index)
	{
		TYPE* result = NULL;
		if (index < numElements)
			return result = &data[index];
		return result;
	}

	void Swap(TYPE& a, TYPE& b)
	{
		TYPE tmp;
		tmp = a;
		a = b;
		b = tmp;
	}

	int Bubble()
	{
		int counter = 0;

		bool end = false;

		while (end == false)
		{
			end = true;

			for (unsigned int i = 0; i < numElements - 1; i++)
			{
				counter++;
				if (data[i] > data[i + 1])
				{
					Swap(data[i], data[i + 1]);
					end = false;
				}
			}
		}
		return counter;
	}

	int BubbleOptim()
	{
		int counter = 0;

		bool end = false;

		while (end == false)
		{
			end = true;

			for (unsigned int i = 0; i < numElements - 1; i++)
			{
				counter++;
				if (data[i] > data[i + 1])
				{
					Swap(data[i], data[i + 1]);
					end = false;
				}
			}
		}
		return counter;
	}

	// Operators
	TYPE& operator[](unsigned int index)
	{
		assert(index < numElements);
		return data[index];
	}

	const TYPE& operator[](unsigned int index) const
	{
		assert(index < numElements);
		return data[index];
	}
	
	int GetNumElements()
	{
		return numElements;
	}
};



#endif _DynamicArray_H_