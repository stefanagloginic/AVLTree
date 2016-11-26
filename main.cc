#include <iostream>

#include "gtest/gtest.h"

#include "avl.h"

using namespace std;

TEST (AVLTree, Test1) {
  AVLTree avltree;
  avltree.Insert(20);
  avltree.Insert(10);
  avltree.Insert(2);
  avltree.Access(2);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "10 2 20");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "2 10 20");

  avltree.Insert(15);
  avltree.Insert(18);
  avltree.Insert(12);
  avltree.Access(15);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "15 10 2 12 18 20");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "2 10 12 15 18 20");

  avltree.Delete(10);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "15 12 2 18 20");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "2 12 15 18 20");
  
  avltree.Delete(18);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "15 12 2 20");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "2 12 15 20");

  avltree.Delete(20);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "12 2 15");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "2 12 15");

  avltree.Insert(7);
  EXPECT_STREQ (avltree.PrintPreOrder().c_str(), "12 2 7 15");
  EXPECT_STREQ (avltree.PrintInOrder().c_str(), "2 7 12 15");
}

TEST (AVLTree, LeftLeftRotation){
  AVLTree avl;
  avl.Insert(11);
  avl.Insert(6);
  avl.Insert(3);

  EXPECT_STREQ (avl.PrintPreOrder().c_str(), "6 3 11");
  EXPECT_STREQ (avl.PrintInOrder().c_str(), "3 6 11");
}


TEST (AVLTree, RightRightRotation){
  AVLTree avl;
  avl.Insert(3);
  avl.Insert(6);
  avl.Insert(11);

  EXPECT_STREQ (avl.PrintPreOrder().c_str(), "6 3 11");
  EXPECT_STREQ (avl.PrintInOrder().c_str(), "3 6 11");

}

TEST (AVLTree, LeftRightRotation){
  AVLTree avl;
  avl.Insert(11);
  avl.Insert(6);
  avl.Insert(9);

  EXPECT_STREQ (avl.PrintPreOrder().c_str(), "9 6 11");
  EXPECT_STREQ (avl.PrintInOrder().c_str(), "6 9 11");

}

TEST (AVLTree, RightLeftRotation){
  AVLTree avl;
  avl.Insert(6);
  avl.Insert(11);
  avl.Insert(9);
  EXPECT_STREQ (avl.PrintPreOrder().c_str(), "9 6 11");
  EXPECT_STREQ (avl.PrintInOrder().c_str(), "6 9 11");
}

TEST (AVLTree, DeleteLeftLeftRotation){
  AVLTree avl;
  avl.Insert(10);
  avl.Insert(15);
  avl.Insert(9);
  avl.Insert(6);
  avl.Delete(15);

  EXPECT_STREQ (avl.PrintPreOrder().c_str(), "9 6 10");
  EXPECT_STREQ (avl.PrintInOrder().c_str(), "6 9 10");
}

TEST (AVLTree, DeleteRightRightRotation){
  AVLTree avl;
  avl.Insert(10);
  avl.Insert(6);
  avl.Insert(12);
  avl.Insert(15);
  avl.Delete(6);

  EXPECT_STREQ (avl.PrintPreOrder().c_str(), "12 10 15");
  EXPECT_STREQ (avl.PrintInOrder().c_str(), "10 12 15");

}

TEST (AVLTree, DeleteLeftRightRotation){
  AVLTree avl;
  avl.Insert(10);
  avl.Insert(15);
  avl.Insert(5);
  avl.Insert(9);
  avl.Delete(15);

  EXPECT_STREQ (avl.PrintPreOrder().c_str(), "9 5 10");
  EXPECT_STREQ (avl.PrintInOrder().c_str(), "5 9 10");

}

TEST (AVLTree, DeleteRightLeftRotation){
  AVLTree avl;
  avl.Insert(12);
  avl.Insert(3);
  avl.Insert(14);
  avl.Insert(13);
  avl.Delete(3);

  EXPECT_STREQ (avl.PrintPreOrder().c_str(), "13 12 14");
  EXPECT_STREQ (avl.PrintInOrder().c_str(), "12 13 14");

}

TEST (AVLTree, Test2){
  AVLTree avl;
  EXPECT_STREQ (avl.PrintPreOrder().c_str(), "");
  EXPECT_STREQ (avl.PrintInOrder().c_str(), "");

  avl.Insert(11);
  EXPECT_STREQ (avl.PrintPreOrder().c_str(), "11");
  EXPECT_STREQ (avl.PrintInOrder().c_str(), "11");

  avl.Insert(5);
  EXPECT_STREQ (avl.PrintPreOrder().c_str(), "11 5");
  EXPECT_STREQ (avl.PrintInOrder().c_str(), "5 11");

  EXPECT_EQ (avl.Access(5), true);
  EXPECT_EQ (avl.Access(11), true);
  EXPECT_EQ (avl.Access(22), false);

  avl.Delete(11);
  EXPECT_STREQ (avl.PrintPreOrder().c_str(), "5");
  EXPECT_STREQ (avl.PrintInOrder().c_str(), "5");

  avl.Delete(5);
  EXPECT_STREQ (avl.PrintPreOrder().c_str(), "");
  EXPECT_STREQ (avl.PrintInOrder().c_str(), "");

  avl.Insert(11);
  avl.Insert(5);
  avl.Insert(3);
  avl.Delete(5);
  avl.Insert(21);
  avl.Insert(29);
  avl.Insert(32);
  avl.Insert(7);
  avl.Insert(5);
  avl.Insert(6);
  avl.Insert(9);
  avl.Insert(8);
  avl.Delete(7);
  avl.Delete(9);

  EXPECT_EQ (avl.Access(21), true);
  EXPECT_EQ (avl.Access(11), true);
  EXPECT_EQ (avl.Access(9), false);
  EXPECT_EQ (avl.Access(7), false);

  EXPECT_STREQ (avl.PrintPreOrder().c_str(), "11 5 3 8 6 29 21 32");
  EXPECT_STREQ (avl.PrintInOrder().c_str(), "3 5 6 8 11 21 29 32");
}

int main(int argc, char *argv[])
{
  ::testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS ();
}
