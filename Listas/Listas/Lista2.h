#ifndef Lista
#define Lista

struct node
{
	int value;
	node* next;
	node* previous;

};

class Lista2
{
private:
	node* start;
	
public:

	Lista2(){ start = NULL; }

	void Add(int val)
	{
		node* tmp = start;
		if (tmp != NULL)
		{
			tmp = tmp->next;
		}
		node* a = new node;
		a->previous=NULL;
		a->next = tmp;
		a->value = val;
		tmp->next = a;
		delete a;
	}



};

#endif Lista