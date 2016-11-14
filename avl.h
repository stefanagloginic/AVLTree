#ifndef AVL_H_
#define AVL_H_

#include <string>

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

  struct Node{
    Node * left;
    Node * right;
    int32_t data;
    uint32_t height;
    Node(int32_t data){
      this.left = NULL;
      this.right = NULL;
      this.data = data;
      this.height = 1;
    }
  };

  uint32_t getHeight(Node * node);
  uint32_t heightBalance(Node * node);
  bool isBalanced(Node * node);
  void changeHeight(Node * node);
};
#endif /* end of include guard: AVL_H_ */
