#ifndef _TREE_H_
#define _TREE_H_

#include "sList.h"

template <class TYPE>
struct Node
{
	TYPE data;
	Node*dad;
	sList son;
};

template <class TYPE>
class Tree
{
private:
	Node* rootNode;
public:

	Tree(TYPE value)
	{
		Node<TYPE>* nou = new Node<TYPE>;
		nou->data = value;
	}

	void Add(const TYPE& value)
	{
		Node<TYPE>* nou = new Node<TYPE>(value);
		rootNode->son.add(nou);
		nou->dad = rootNode;
	}

	void Add(const TYPE& value, const Node* parent)
	{
		Node<TYPE>* nou = new Node<TYPE>(value);
		parent->son.Add(nou);
		nou->dad = parent;
	}

	void VisitAllNodes(sList <TYPE>* list, int option)const
	{

		switch (option)
		{
		case 1: { rootNode PreOrderRecursive(list); break; }
		case 2: { rootNode InOrderRecursive(list); break; }
		case 3: { rootNode PostOrderRecursive(list); break; }
		case 4: { rootNode PreOrderIterative(list, parent); break; }
		case 5: { rootNode InOrderIterative(list, parent); break; }
		case 6: { rootNode PostOrderIterative(list, parent); break; }
		}
		
	}

	void PreOrderRecursive(sList <TYPE>* list)
	{
		list.Add(data);
		for (int i = 0; i < list->count; i++)
			node->VisitAll(list, 1);
	}

	void InOrderRecursive(sList <TYPE>* list)
	{
		for (int i = 0; i < list->count; i++)
		{
			list.Add(data);

		}
		
	}

	void PostOrderRecursive(sList <TYPE>* list)
	{
		node->VisitAll(list, 3);
		for (int i = 0; i < list->count; i++)
			list.Add(data);
	}

	//visit all with iterative functions

	void PreOrderIterative(sList <TYPE>* list, Node<TYPE>* parent)
	{
		list->Add(rootNode);
			for (int i = 0; i < list->count; i++)
			{
				//pila
				list.Add(data);
				if (parent->son = NULL)
				{

				}
			}
		

	}

	void InOrderIterative(sList <TYPE>* list, Node<TYPE>* parent)
	{

	}

	void lPostOrderIterative(sList<TYPE>* list, Node<TYPE> parent)
	{

	}

	void Clear()
	{

	}
};



#endif _TREE_H_