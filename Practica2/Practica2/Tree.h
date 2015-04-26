#ifndef _TREE_H_
#define _TREE_H_

struct node
{
	char data;
	node* left;
	node* right;
};

class Tree
{
private:
	node* root;
public: 
	Tree(){}
	Tree(node* _root, char _data){ root = _root; data = _data; }
	~Tree();


};
#endif _TREE_H_