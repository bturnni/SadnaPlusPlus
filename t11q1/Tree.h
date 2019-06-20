#pragma once
#include <iostream>
using namespace std;

//--------------------------------------------------------
//  inner class Node
//      a single Node from a binary tree
//--------------------------------------------------------
template <class T>
class Node
{
public:
	Node* left;
	Node* right;
	T value;
	Node(T val) : value(val), left(NULL), right(NULL) {}
	Node(T val, Node<T>* l, Node<T>* r)
		: value(val), left(l), right(r) {}
};		//end of Node class


//-----------------------------------
//  class Tree (Binary Trees)
// process nodes in Pre/In/Post  order
//-----------------------------------
template <class T>
class Tree
{
protected:
	//data member of tree
	Node<T>* root;
public:
	Tree() { root = NULL; }	 // initialize tree
	~Tree();
	int isEmpty() const;
	void clear() { clear(root); root = NULL; }
	void preOrder() { preOrder(root); }
	void inOrder() { if(root)inOrder(root); }
	void postOrder() { postOrder(root); }

	virtual void process(T val) { cout << val << " "; }
	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T val) = 0;

	/*
		added Help functions	
	*/
	bool isLeaf(Node<T>* node)
	{
		return (!node->right && !node->left);
	}
	/*HomeWork*/
	int leaves() { return leaves(root); };
	int height() { return height(root); };
	void reflect() { reflect(root); };
	int onlyLeftSon() { if (root) { return onlyLeftSon(root); } };

private:
	void  clear(Node<T>* current);
	void  preOrder(Node<T>* current);
	void  inOrder(Node<T>* current);
	void  postOrder(Node<T>* current);
	/*added help functions*/
	int leaves(Node<T>* node);
	int height(Node<T>* node);
	void reflect(Node<T>* node);
	int onlyLeftSon(Node<T>* node);
};


//template <class T>
//Tree<T>::Node<T>::Node(T val): value(val), left(NULL), right(NULL){}
//----------------------------------------------------------
//  class Tree implementation
//----------------------------------------------------------
template <class T>
Tree<T>::~Tree() // deallocate tree
{
	if (root != NULL)
		clear(root);
}
template <class T>
void Tree<T>::clear(Node<T>* current)
{
	if (current)
	{    // Release memory associated with children
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}

template <class T>
int Tree<T>::isEmpty() const
{
	return  root == NULL;
}

// preOrder processing of tree rooted at current
template <class T>
void Tree<T>::preOrder(Node<T>* current)
{    // visit Node, left child, right child
	if (current)
	{   // process current Node
		process(current->value);
		// then visit children
		preOrder(current->left);
		preOrder(current->right);
	}
}

// inOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(Node<T>* current)
{   
	// visit left child, Node, right child
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}

// postOrder processing of tree rooted at current
template <class T>
void Tree<T>::postOrder(Node<T>* current)
{    // visit left child, right child, node
	if (current)
	{
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);
	}
}


template<class T>
int Tree<T>::leaves(Node<T>* node)
{
	if (node == NULL)
		return 0;
	if (node->left == NULL && node->right == NULL)
		return 1;
	else
		return leaves(node->left) +
		leaves(node->right);
}

template<class T>
inline int Tree<T>::height(Node<T>* node)
{
	//height is 0
	if (isLeaf(node))
		return 1;

	int right = 0, left = 0;
	// right tree
	if (node->right)
		right = height(node->right);

	// left tree
	if (node->left)
		left = height(node->left);

	return (right > left ? right : left) + 1;
}

template<class T>
inline void Tree<T>::reflect(Node<T>* node)
{
	if (node == NULL)
		return;
	else
	{
		Node<T>* temp;

		/* do the subtrees */
		reflect(node->left);
		reflect(node->right);

		/* swap the pointers in this node */
		temp = node->left;
		node->left = node->right;
		node->right = temp;
	}
}

template<class T>
inline int Tree<T>::onlyLeftSon(Node<T>* node)
{
	if (!node || isLeaf(node))
		return 0;

	int num = 0;
	//left avalible AND right not
	if (!node->right && node->left)
		num++;

	num += (onlyLeftSon(node->left) + onlyLeftSon(node->right));

	return num;
}
