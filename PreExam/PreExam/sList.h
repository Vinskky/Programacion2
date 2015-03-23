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

	sList(){ start = NULL;}
	
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

			while  (tmp->next != NULL)
			{
				delete tmp->next;
				tmp->next = tmp->next->next;
							
			}
			delete tmp;
			start = NULL;
		}
			
	}
};

#endif slist

