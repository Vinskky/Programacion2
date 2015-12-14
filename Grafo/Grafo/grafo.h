#ifndef _GRAFO_H_
#define _GRAFO_H_
#include "DynArray.h"
#include "definitions.h"

template <class TYPE>

class Grafo
{
private:

	struct node
	{
		TYPE data;
		DynArray<node*> links;

		bool AddLink(node* n)
		{
			if (n != NULL)
			{
				links.PushBack(n);
				return true;
			}
			return false;
		}

		node(const TYPE& data) : data(data){}

		
		
	};
	
	DynArray<node*> nodes;

public:

	

	~Grafo(){}


	void AddNode(const TYPE& data)
	{	
		node* Gnode = new node(data);
		nodes.PushBack(Gnode);
	}

	bool Conect(node* a, node* b)
	{
		if (n != NULL)
		{
			a->Addlink(b);
			return true;
		}
		return false;
	}

	bool IsConnected(node* a, node* b)
	{
		if (a != NULL && b != NULL)
		{
			if (a->links == NULL)
				return false;
			if (a == b)
			{
				return true;
			}

		}
		return false;
	}
};



#endif