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

	void VisitAllNodes(sList <TYPE>* list)const
	{
		rootNode VisitAll(list);
	}

	void VisitAll(sList <TYPE>* list)
	{
		list.Add(data);
		for (int i = 0; i < list->count; i++)
			node->VisitAll(list);
	}

};



#endif _TREE_H_