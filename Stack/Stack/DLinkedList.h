#ifndef _DLINKEDLIST_H_
#define _DLINKEDLIST_H_

#define NULL 0

typedef unsigned int uint;

template <class TYPE>
class DLinkedList;

template <class TYPE>

struct node
{
private:
	TYPE data;
	node* next;
	node* prev;

	friend DLinkedList<TYPE>;
};

template <class TYPE>

class DLinkedList
{
private:
	node<TYPE>* start;

public:

	DLinkedList() : start(NULL)
	{}

	uint Size()const
	{
		uint size = 0;
		node<TYPE>* tmp = start;
		while (tmp->next)
		{
			tmp = tmp->next;
			size++;
		}
	}

	bool Empty()const
	{
		return (start == NULL);
	}

	void Clear()
	{
		node<TYPE>* tmp = start;

		while (start->next)
		{
			tmp = tmp->next;
			delete start;
			start = tmp;
		}

		delete tmp;
		start = NULL;
	}

	bool Front(TYPE& dList)
	{
		if (start)
		{
			dList = start->data;
			return true;
		}
		return false;
	}

	bool Back(TYPE& dList)
	{
		if (start)
		{
			node<TYPE>* tmp = start;

			while (start->next)
			{
				tmp = tmp->next;
			}
			dList = tmp->data;
			return true;
		}
		return false;
	}

	void PushBack(TYPE data)
	{
		if (start)
		{
			node<TYPE>* tmp = start;

			while (tmp->next)
			{
				tmp = tmp->next;
			}

			tmp->next = new node<TYPE>;
			tmp->next->data = data;
			tmp->next->prev = tmp;
		}
		else
		{
			start = new node<TYPE>;
			start->data = data;
		}
		
	}

	void PushFront(TYPE data)
	{
		if (start)
		{
			start->prev = new node<TYPE>;
			start->prev->data = data;
			start->prev->next = start;
			start = start->prev;
		}
		else
		{
			start = new node;
			start->data = data;
		}
	}

	bool PopBack(TYPE data)
	{
		if (start)
		{
			if (start->next)
			{
				node<TYPE> *tmp = start;

				while (tmp->next)
				{
					tmp = tmp->next;
				}
				data = tmp->data;
				tmp->prev->next = NULL;
				delete tmp;
				return true;
			}//if only exist one node do..
			data = start->data;
			delete start;
			start = NULL;
			return true;
		}
		return false;
	}

	bool PopFront(TYPE data)
	{
		if (start)
		{
			if (start->next)
			{
				node<TYPE>* tmp = start;
				data = tmp->data;
				start = start->next;
				delete tmp;
				start->prev = NULL;
				return true;
			}
			data = start->data;
			delete start;
			start = NULL;
			return true;
		}
		return false;
	}

	/*bool Insert(uint position, const DATA& data)
	{
		if (start && position != 0)
		{
			if (start->next)
			{

			}

		}
		
		if (position == 0)
		{
			start->prev = new node;
			start->prev->data = data;
			start->prev->next = start;
			start = start->prev;
			start->prev = NULL;
			return true;
		}
		return false;
	}

	Erase(){}*/
};


#endif