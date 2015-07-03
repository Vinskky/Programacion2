#include <stdio.h>
#include <assert.h>

#ifndef slist 
#define slist

template <class TYPE3>

struct node
{
	TYPE3 value;
	node* next;
};

template <class TYPE3>

class sList
{
private:

	node* start;

public:

	sList(){ start = NULL; }

	void Add(TYPE3 valor)
	{
		node* tmp = start;
		if (tmp != NULL)
		{
			tmp = tmp->next;
		}
		node* a = new node;
		a->next = NULL;
		a->value = valor;
		tmp->next = a;
		delete a;
	}

	unsigned int count()const
	{
		unsigned int result = 0;
		node* tmp = start;
		while (tmp != NULL)
		{
			result++;
		}
		return result;

	}

	void delet(node* delN)
	{
		if (delN != NULL && start != NULL)
		{
			if (delN != start)
			{
				node* nextN = start;
				while (nextN && nextN->next != delN)
				{
					nextN = nextN->next;
				}
				nextN->next = delN->next;
			}
			else
			{
				start = start->next;
			}
			delete delN;
		}
	}

	void removeList()
	{
		if (start != NULL)
		{
			node* tmp = start;
			delete start;

			while (tmp->next != NULL)
			{
				delete tmp->next;
				tmp->next = tmp->next->next;

			}
			delete tmp;
			start = NULL;
		}

	}

	TYPE3& operator[](unsigned int index)
	{
		assert(index < numElements);
		return data[index];
	}

	const TYPE3& operator[](unsigned int index) const
	{
		assert(index < numElements);
		return data[index];
	}

	void Flip()
	{
		sList aux;
		for (int i = count(); i > count(); i--)
		{
			aux.Add(start->value[i]);
		}
		for (int z = 0; z < count(); z++)
		{
			aux.start->value[z] = start->value[z];
		}
		aux.removeList();
	}
};

#endif slist

