#ifndef AVL_H_
#define AVL_H_

#include <string>

struct Node{
  Node * left;
  Node * right;
  int32_t data;
  uint32_t height;
  Node(int32_t data){
    this->left = NULL;
    this->right = NULL;
    this->data = data;
    this->height = 1;
  }
};

class AVLTree
{
public:
  AVLTree ();
  virtual ~AVLTree ();
  void Insert (int32_t val);
  // choose smallest node on the right subtree when deleting a node with two children
  void Delete (int32_t val);
  bool Access (int32_t val);
  std::string PrintPreOrder () const;
  std::string PrintInOrder () const;

private:
  Node * root;

  uint32_t getHeight(Node * node);
  bool isBalanced(Node * node);
  void changeHeight(Node * node);
  void Insert(Node * &node, int32_t val);
  void Balance(Node * &currNode);
  int32_t balanceFactor(Node * currNode);
  void leftLeftShift(Node * &currNode);
  void rightRightShift(Node * &currNode);
  void leftRightShift(Node * &currNode);
  void rightLeftShift(Node * &currNode);
  Node * findValue(Node * currNode, int32_t val);
  void Delete(Node * &currNode, int32_t val);
  void deleteTree(Node * currNode);
  Node * findMin(Node * currNode);
  std::string preOrderTraversal(Node * currNode, std::string tree) const;
  std::string inOrderTraversal(Node * currNode, std::string tree) const;
};
#endif /* end of include guard: AVL_H_ */
