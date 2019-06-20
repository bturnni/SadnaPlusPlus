#ifndef SEARCH_TREE_H
#define SEARCH_TREE_H

#include "Tree.h"
#include <iostream>
using namespace std;


template<class T>
class SearchTree : public Tree<T>
{

public:
	// protocol for search trees
	void add(T value);
	bool  search(T value)
	{
		return search(this->root, value);
	}
	//added help func
	Node<T>* FindMin(Node<T>* root);
	/*HomeWork*/
	void remove(T value) { this->root = remove(this->root, value); };
	int level(T value);
private:
	Node<T>* remove(Node<T>* root, T data);
	void add(Node<T>* current, T val);
	bool  search(Node<T>* current, T val);
};

//template <class T>
//Tree<T>::Node<T>* SearchTree<T>::searchNew(T value)
//{
//	return new Node<T>();
//}


template <class T>
void SearchTree<T>::add(T val)
{
	// add value to binary search tree 
	if (!this->root)
	{
		this->root = new Node<T>(val);
		return;
	}
	add(this->root, val);
}

template <class T>
bool SearchTree<T>::
search(Node<T>* current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		return false;	// not found
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}

template<class T>
inline int SearchTree<T>::level(T value)
{
	Node<T>* curr = this->root;
	int count = 0;
	while (true)
	{
		if (!curr)
		{
			return -1;
		}
		if (curr->value > value)
		{

			curr = curr->left;
			count++;
		}
		else if (curr->value == value)
		{
			return count;
		}
		else
		{
			curr = curr->right;
			count++;
		}
	}
}

template<class T>
inline Node<T>* SearchTree<T>::remove(Node<T>* root, T data)
{
	if (root == NULL) return root;
	else if (data < root->value) root->left = remove(root->left, data);
	else if (data > root->value) root->right = remove(root->right, data);
	// found	
	else {
		// Case 1:  No child
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if (root->left == NULL) {
			Node<T>* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			Node<T>* temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else {
			Node<T>* temp = FindMin(root->right);
			root->value = temp->value;
			root->right = remove(root->right, temp->value);
		}
	}
	return root;
}



//Function to find minimum in a tree. 
template <class T>
Node<T>* SearchTree<T>::FindMin(Node<T>* root)
{
	while (root->left != NULL) root = root->left;
	return root;
}

template <class T>
void SearchTree<T>::add(Node<T>* current, T val)
{
	if (current->value < val)
		// add to right subtree
		if (!current->right)
		{
			current->right = new Node<T>(val);
			return;
		}
		else add(current->right, val);
	else
		// add to left subtree
		if (!current->left)
		{
			current->left = new Node<T>(val);
			return;
		}
		else add(current->left, val);
}

#endif