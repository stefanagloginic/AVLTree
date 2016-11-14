#ifndef BST_H_
#define BST_H_
#define Element int

struct BinaryNode {
	Element elem;
	BinaryNode *left;
	BinaryNode *right;

	BinaryNode(): elem(0), left(NULL), right(NULL) {}
	BinaryNode(const Element & e, BinaryNode *lt, BinaryNode *rt): elem(e), left(lt), right(rt) {}
};

class BinarySearchTree
{
public:
	BinarySearchTree(): root() {}
	~BinarySearchTree() { makeEmpty(root);}

	bool Insert(const Element e);
	bool Access(const Element e);
	bool Delete(const Element e);

private:

	BinaryNode *root;

	BinaryNode * findMin(BinaryNode *t);
	void makeEmpty(BinaryNode * & t);
	bool Insert(const Element e, BinaryNode * & t);
	bool Access(const Element e, BinaryNode * & t);
	bool Delete(const Element e, BinaryNode * & t);
};

#endif /* BST_H_ */
