#include <iostream>
#include <cmath>


AVLTree::AVLTree (){
  root = NULL;
}
AVLTree::~AVLTree (){

}
void AVLTree::Insert (int32_t val){

}// choose smallest node on the right subtree when deleting a node with two children
void AVLTree::Delete (int32_t val){

}
bool AVLTree::Access (int32_t val){

}
std::string AVLTree::PrintPreOrder () const{

}
std::string AVLTree::PrintInOrder () const{

}
uint32_t AVLTree::getHeight(Node * node){
  if(node == NULL){
    return 0;
  }

  return node->height;
  
}
uint32_t AVLTree::balanceFactor(Node * node){
  return std::abs(getHeight(node->left)-getHeight(node->right));
}
bool AVLTree::isBalanced(Node * node){
  uint32_t BF = balanceFactor(node);
  if(BF > 1){
    return false;
  }
  return true;
}
void AVLTree::changeHeight(Node * node){//assumes node was inserted
  uint32_t leftHeight = getHeight(node->left);
  uint32_t rightHeight = getHeight(node->right);
  
  if(leftHeight > rightHeight){
    node->height = leftHeight+1;
    return;
  }
  node->height = rightHeight+1; //either right is greater or equal to the left nodes height.
  
}

