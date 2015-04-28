#ifndef _TREE_H_
#define _TREE_H_

#include "DoublyList.h"
#include "Stack.h"

template <class TYPE>
struct NodeTree
{
	TYPE data;
	NodeTree*dad;
	DoublyList<TYPE> son;
};

template <class TYPE>
class Tree
{
private:
	NodeTree<TYPE>* rootNode;
public:

	Tree() : rootNode(NULL)
	{}

	Tree(TYPE value)
	{
		NodeTree<TYPE>* nou = new NodeTree<TYPE>;
		nou->data = value;
	}

	void Add(const TYPE& value)
	{
		NodeTree<TYPE>* nou = new NodeTree<TYPE>(value);
		rootNode->son.Add(nou);
	}

	void Add(const TYPE& value, const NodeTree<TYPE>* parent)
	{
		NodeTree<TYPE>* nou = new NodeTree<TYPE>(value);
		parent->son.Add(nou);
		nou->dad = parent;
	}

	void VisitAllNodes(DoublyList <TYPE>* list, int option)const
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

	void PreOrderRecursive(DoublyList <TYPE>* list)
	{
		list.Add(data);
		for (int i = 0; i < list->count; i++)
			rootNode->data->VisitAllNodes(list, 1);
	}

	void InOrderRecursive(DoublyList <TYPE>* list)
	{
		unsigned int medium = rootNode->son.count() / 2;
		
		for (unsigned int i = 0; i < medium; i++)
		{
			rootNode->data->VisitAllNodes(list, 2);
		}


		for (int i = 0; i < list->count; i++)
			rootNode->data->VisitAllNodes(list, 2);

	}

	void PostOrderRecursive(DoublyList <TYPE>* list)
	{
		
		for (int i = 0; i < list->count; i++)
			rootNode->data->VisitAllNodes(list, 3);

		list.Add(data);
	}

	//visit all with iterative functions

	void PreOrderIterative(DoublyList <TYPE>* list, NodeTree<TYPE>* parent)
	{
		p2Stack<TYPE>* stack;
		NodeTree<TYPE>* tmp;

		for (int i = 0; i < list->count; i++)
		{
			if (parent->son->start != NULL )
			{
				stack->Push(parent->data);
				//tmp->data = list->start->data;
			}
			else 
			{
				if (list->start->next != NULL)
				{
					parent->data = list->start->next->data;
					stack->Push(parent->data);
					tmp->data = parent->data;
				}
			}
			tmp = stack->Pop(parent->data);
			//parent->data = tmp->data;
		}
	}

	void InOrderIterative(DoublyList <TYPE>* list, NodeTree<TYPE>* parent)
	{

	}

	void PostOrderIterative(DoublyList<TYPE>* list, NodeTree<TYPE> parent)
	{
		p2Stack<TYPE>* stack;
		NodeTree<TYPE>* tmp;

		for (int i = 0; )
		
	}

	void Clear()
	{

	}

	//Utils

	const bool IsEmpty()
	{
		return rootNode = NULL;
	}

	const NodeTree<TYPE>* GetRoot()
	{
		return rootNode;
	}
};



#endif _TREE_H_