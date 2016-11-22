#include <iostream>
#include <cmath>


AVLTree::AVLTree (){
  root = NULL;
}

AVLTree::~AVLTree (){
  deleteTree(root);
  root = NULL;
}

void deleteTree(Node * curr){
  if(curr == NULL){
    delete curr;
  }
  
  deleteTree(curr->left);
  deleteTree(curr->right);

}

void AVLTree::Insert (int32_t val){
  Insert(root, val);
}

void AVLTree::Insert(Node * &node, int32_t val){
  if(node == NULL){ //take care of case if a new root is created. 
    Node * newNode = new Node(val);
    node = newNode;
    return;
  }
  else if(val > node->data){
    Insert(node->right, val);
  }
  else if(val < node->data){
    Insert(node->left, val);
  }
  else{//currently don't accept duplicates
    return;
  }
  Balance(node);
}
// choose smallest node on the right subtree when deleting a node with two children

void AVLTree::Delete (int32_t val){
  Delete(root, val);
  
}

void AVLTree::Delete(Node * &currNode, int32_t val){
  if(currNode == NULL){
    return;
  }
  
  else if(currNode == val){
    if(currNode->left == NULL && currNode->right == NULL){
      delete currNode;
      currNode = NULL;
    }
    
    else if(currNode->left == NULL && currNode->right != NULL){
      Node * temp = currNode;
      currNode = currNode->right;
      delete temp;
      temp = NULL;
    }
    
    else if(currNode->right == NULL && currNode->left != NULL){
      Node * temp = currNode;
      currNode = currNode->left;
      delete temp;
      temp = NULL;
    }
    
    else{//have 2 children
     Node * rightMinNode = findMin(currNode->right);
     currNode->data = rightMinNode->data;
     delete rightMinNode;
     rightMinNode = NULL;
    }
    
    return;

  }

  else if(currNode->data < val){
    Delete(currNode->right, val); 
  }

  else{
    Delete(currNode->left, val);
  }

}

Node * findMin(Node * currNode){
  if(currNode->left == NULL){
    return currNode;
  }
  return findMin(currNode->left);
}

bool AVLTree::Access (int32_t val){
  Node * nodeWithValue = findValue(root, val);
  if(nodeWithValue != NULL) {
    return true;
  }
  return false;
}

Node * AVLTree::findValue(Node * currNode, int32_t val){
  if(currNode == NULL){
    return currNode;
  }
  
  else if(currNode->data == val){
    return currNode;
  }
  
  else if(currNode->data < val){
    return findValue(currNode->left, val);
  }
  
  else{
    return findValue(currNode->right, val);
  }
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
  return getHeight(node->right)-getHeight(node->left);
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

void AVLTree::Balance(Node * &currNode){//assumes insert & will change height &  maintain AVLTree's balance
  changeHeight(currNode);
  
  if(!isBalanced(currNode)){
    
    int32_t currBalanceFactor = balanceFactor(currNode);

    if(currBalanceFactor <= -2){//indicates inbalance is on the left

      int32_t secondaryBalanceFactor = balanceFactor(currNode->left);

      if(secondaryBalanceFactor < 0){ //indicates LL shift is needed
	leftLeftShift(currNode);
      }
      else{//indicates LR shift is needed
	leftRightShift(currNode);
      }
    }

    else{//indicates inbalance is on the right.

      int32_t secondaryBalanceFactor = balanceFactor(currNode->right);

      if(secondaryBalanceFactor < 0){//indicates RL shift is needed.
	rightLeftShift(currNode);
      }
      else{ //indicates RR shift is needed
	rightRightShift(currNode);
      }

    }
  }
  return;
}

void AVLTree::leftLeftShift(Node * &currNode){

  Node * temp = currNode; //save our currentNode

  currNode = currNode->left; //now we change currentNode to what it should be

  temp->left = currNode->right; //take the old node's left pointer and have it point to new currentNode's tree

  currNode->right = temp; //not set the currentNodes right to point to the old node.

  //adjust height since we changed the tree
  changeHeight(temp); //first change the right of currNode to it's new height
  changeHeight(currNode); //now change the new currNode to its subsequent height
  
}

void AVLTree::leftRightShift(Node * &currNode){
  rightRightShift(currNode->left);
  leftLeftShift(currNode);
}

void AVLTree::rightLeftShift(Node * &currNode){
  leftLeftShift(currNode->right);
  rightRightShift(currNode);
}

void AVLTree::rightRightShift(Node * &currNode){//symmetric procedure of leftLeftShift
  Node * temp = currNode;

  currNode = currNode->right;

  temp->right = currNode->left;

  currNode->left = temp;

  changeHeight(temp);
  changeHeight(currNode);
}

