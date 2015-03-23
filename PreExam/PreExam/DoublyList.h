#include <stdio.h>

#ifndef _DoublyList_H_
#define _DoublyList_H_

template <class tdata>
struct  node
{
	tdata data;
	node<tdata>* next;
	node<tdata>* prev;
	inline node(const tdata& _data)
	{
		data = _data;
		next = prev = NULL;
	}

	~node(){}
};

template <class tdata>
class DoublyList
{
private:

	unsigned int size;

public:

	node<tdata>* start;
	node<tdata>* end;

	//constructors
	inline DoublyList()
	{
		size = 0;
		start = end = NULL;
	}

	~DoublyList()
	{
		Clear();
	}

	unsigned int Add(const tdata& item)
	{
		node<tdata>* = data_item;
		data_item = new node < tdata >(item);

		if (start == NULL)
		{
			start = end = data_item;
		}
		else
		{
			data_item->prev = end;
			end->next = data_item;
			end = data_item;
		}

		return(++size);
	}

	/**
	* Deletes an item from the list
	*/
	bool del(node<tdata>* item)
	{
		if (item == NULL)
		{
			return (false);
		}

		// Now reconstruct the list
		if (item->prev != NULL)
		{
			item->prev->next = item->next;

			if (item->next != NULL)
			{
				item->next->prev = item->prev;
			}
			else
			{
				end = item->prev;
			}
		}
		else
		{
			if (item->next)
			{
				item->next->prev = NULL;
				start = item->next;
			}
			else
			{
				start = end = NULL;
			}
		}

		delete item;
		--size;
		return(true);
	}


	void Clear()
	{
		node<tdata>*   p_data;
		node<tdata>*   p_next;
		p_data = start;

		while (p_data != NULL)
		{
			p_next = p_data->next;
			delete p_data;
			p_data = p_next;
		}

		start = end = NULL;
		size = 0;
	}

};

#endif _DoublyList_H_