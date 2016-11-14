#include <iostream>
#include <sstream>
#include "bst.h"
using namespace std;

// Public Methods

bool BinarySearchTree::Insert(const Element e)
{
	return Insert(e, root);
}

bool BinarySearchTree::Access(const Element e)
{
	return Access(e, root);
}

bool BinarySearchTree::Delete(const Element e)
{
	return Delete(e, root);
}

// Privte Methods

BinaryNode * BinarySearchTree::findMin(BinaryNode *t)
{
	if(t != NULL)
		while(t->left != NULL)
			t = t->left;
	return t;
}

void BinarySearchTree::makeEmpty(BinaryNode * & t)
{
	if(t != NULL) {
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = NULL;
}

bool BinarySearchTree::Insert(const Element e, BinaryNode * & t)
{
	if(t == NULL) {
		t = new BinaryNode(e, NULL, NULL);
    return true;
	}	else if(e == t->elem)
		return false;
	else if(e < t->elem)
		return Insert(e, t->left);
	else if(e > t->elem)
		return Insert(e, t->right);
  else
    return false;
}

bool BinarySearchTree::Access(const Element e, BinaryNode * & t)
{
	if(t == NULL)
		return false;
	else if(e == t->elem)
		return true;
	else if(e < t->elem)
		return Access(e, t->left);
	else
    return Access(e, t->right);
}

bool BinarySearchTree::Delete(const Element e, BinaryNode * & t)
{
	if(t == NULL) {
//		cout << "case 1: t->elem= " << t->elem << endl;
		return false;
	}
	else if(e < t->elem) {
//		cout << "case 2: t->elem= " << t->elem << endl;
		return Delete(e, t->left);
	}
	else if(e > t->elem) {
//		cout << "case 3: t->elem= " << t->elem << endl;
		return Delete(e, t->right);
	}
	else {
		if(t->left != NULL && t->right != NULL) {
//			cout << "case 4_1: t->elem= " << t->elem << endl;
			t->elem = findMin(t->right)->elem;
//			cout << "case 4_1: t->elem= " << t->elem << endl;
			return Delete(t->elem, t->right);
		}
		else {
//			cout << "case 4_2: t->elem= " << t->elem << endl;
			BinaryNode *oldNode = t;
			t = (t->left != NULL) ? t->left : t->right;
			delete oldNode;
			return true;
		}
	}
}

