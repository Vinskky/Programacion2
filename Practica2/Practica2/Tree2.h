#ifndef _TREE_H_
#define _TREE_H_

#include "DoublyList.h"
#include "Stack.h"

template <class TYPE>
class NodeTree
{
public:
	TYPE data;
	NodeTree* dad;
	DoublyList<NodeTree<TYPE>*> son;

	//constructor
	NodeTree(const TYPE& newdata)
	{
		data = newdata;
		dad = NULL;
		son = NULL;
	}

	NodeTree()
	{
		dad = NULL;
		son = NULL;
	}

	NodeTree(const TYPE& newdata, NodeTree* parent)
	{
		data = newdata;
		dad = parent;
		son = NULL;
	}

	void PreOrderRecursive(DoublyList <TYPE>* list)const
	{
		int i = 0;
		NodeTree* tmp = son->GetFirst()
		list->Add(this->data);

		while (tmp != NULL)
		{
			tmp = PreOrderRecursive(list);
			tmp = son->getByIndex(i);
			i++;
		}	
	}

	void InOrderRecursive(DoublyList <TYPE>* list)
	{


	}

};

template <class TYPE>
class Tree
{
public:
	NodeTree<TYPE>* root;

	Tree() : rootNode(NULL)
	{}

	Tree(TYPE value)
	{
		NodeTree<TYPE>* nou = new NodeTree<TYPE>;
		nou->data = value;
	}

	void Add(const TYPE& value)
	{
		
	}

	void Add(const TYPE& value, const NodeTree<TYPE>* parent)
	{
		
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
		root->PreOrderRecursive(list);
	}

	void InOrderRecursive(DoublyList <TYPE>* list)
	{
		root->InOrderRecursive(list);
	}

	void PostOrderRecursive(DoublyList <TYPE>* list)
	{

		
	}

	//visit all with iterative functions

	void PreOrderIterative(DoublyList <TYPE>* list, NodeTree<TYPE>* parent)
	{
		
	}

	void InOrderIterative(DoublyList <TYPE>* list, NodeTree<TYPE>* parent)
	{

	}

	void PostOrderIterative(DoublyList<TYPE>* list, NodeTree<TYPE> parent)
	{
		

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