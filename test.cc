#include "avl.h"
#include "bst.h"
#include <time.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int myrandom(int i){return std::rand()%i;}

float getAverage(vector<float> v){
  float sum = 0;
  for(int i = 0; i < v.size(); i++){
    sum += v.at(i);
  }
  return (sum/v.size());
}

void AVLTreeTest1(int n){
  vector<float> v;

  for(int i=0; i<5; ++i){

    AVLTree* tree = new AVLTree();
    clock_t t1, t2;
    t1 = clock();
    for(int i = 0; i < n; i++){
      tree->Insert(i);
    }

    for(int i = 0; i < n; i++){
      tree->Access(i);
    }

    for(int i = 0; i < n; i++){
      tree->Delete(i);
    }

    t2 = clock();

    float diff = ((float)t2-(float)t1);
    diff = (diff/CLOCKS_PER_SEC)*1000;

    cout << "The AVL Tree ran through the inserts, access's and deletes for N = " << n << ", Test " << i
	 << " "  << diff <<" rate" << endl;

    v.push_back(diff);
    
  }
  cout << "The avg of the AVL Tree for test 1 with N = " << n << " is " << getAverage(v) << "." << endl;
}

void BSTTreeTest1(int n){
  vector<float> v;

  for(int i=0; i<5; ++i){

    BinarySearchTree* tree = new BinarySearchTree();
    clock_t t1, t2;
    t1 = clock();
    for(int i = 0; i < n; i++){
      tree->Insert(i);
    }

    for(int i = 0; i < n; i++){
      tree->Access(i);
    }

    for(int i = 0; i < n; i++){
      tree->Delete(i);
    }

    t2 = clock();

    float diff = ((float)t2-(float)t1);
    diff = (diff/CLOCKS_PER_SEC)*1000;
    
    cout << "The BST Tree ran through the inserts, access's and deletes for N = " << n << ", Test " << i
	 << " "  << diff <<" rate" << endl;

    v.push_back(diff);
  }


  cout << "The avg of the BST Tree for test 1 with n = " << n << " is " << getAverage(v) << "." << endl;

}

void AVLTreeTest2(int n){
  vector<float> v;

  for(int i=0; i<5; ++i){

    AVLTree* tree = new AVLTree();
    clock_t t1, t2;
    t1 = clock();
    for(int i = 0; i < n; i++){
      tree->Insert(i);
    }

    for(int i = n-1; i >= 0; i--){
      tree->Access(i);
    }

    for(int i = n-1; i >= 0; i--){
      tree->Delete(i);
    }

    t2 = clock();

    float diff = ((float)t2-(float)t1);
    diff = (diff/CLOCKS_PER_SEC)*1000;
    
    cout << "The AVL Tree ran through the inserts, access's and deletes done in reverse for N = " << n << ", Test " << i
	 << " "  << diff <<" rate" << endl;

    v.push_back(diff);
  }


  cout << "The avg of the AVL Tree for test 2 with n = " << n << " is " << getAverage(v) << "." << endl;
}

void BSTTreeTest2(int n){
  vector<float> v;

  for(int i=0; i<5; ++i){

    BinarySearchTree* tree = new BinarySearchTree();
    clock_t t1, t2;
    t1 = clock();
    for(int i = 0; i < n; i++){
      tree->Insert(i);
    }

    for(int i = n-1; i >= 0; i--){
      tree->Access(i);
    }

    for(int i = n-1; i >= 0; i--){
      tree->Delete(i);
    }

    t2 = clock();

    float diff = ((float)t2-(float)t1);
    diff = (diff/CLOCKS_PER_SEC)*1000;
    
    cout << "The BST Tree ran through the inserts, access's and deletes done in reverse for N = " << n << ", Test " << i
	 << " "  << diff <<" rate" << endl;

    v.push_back(diff);
  }


  cout << "The avg of the BST Tree for Test 2 with n = " << n << " is " << getAverage(v) << "." << endl;

}

void AVLTreeTest3(int n){
  vector<float> v;
  vector<int> randOg; //need 3 vectors so they can be shuffled differently and not within the clock.

  for(int i = 0; i < n; i++){
    randOg.push_back(i);
  }
  
  vector<int> rand1(randOg);
  vector<int> rand2(randOg); //making copies here of vector's values.
  
  for(int i=0; i<5; ++i){
    AVLTree* tree = new AVLTree();
    random_shuffle(randOg.begin(), randOg.end(),myrandom); //shuffling the vectors.
    random_shuffle(rand1.begin(), rand1.end(),myrandom);
    random_shuffle(rand2.begin(), rand2.end(),myrandom);
    
    clock_t t1, t2;
    t1 = clock();
    
    for(int i = 0; i < n; i++){
      tree->Insert(randOg.at(i));
    }

    for(int i = 0; i < n; i++){
      tree->Access(rand1.at(i));
    }

    for(int i = 0; i < n; i++){
      tree->Delete(rand2.at(i));
    }

    t2 = clock();

    float diff = ((float)t2-(float)t1);
    diff = (diff/CLOCKS_PER_SEC)*1000;//will give time in milliseconds.

    cout << "The AVL Tree ran through the randomized inserts, acc\
ess's and deletes for N = " << n << ", Test " << i
	 << " "  << diff <<" rate" << endl;

    v.push_back(diff);
  }
  
  cout << "The avg of the AVL Tree for test 3 with N = " << n << " is " << getAverage(v) << "." << endl;  
}

void BSTTreeTest3(int n){
  vector<float> v;
  vector<int> randOg; //need 3 vectors so they can be shuffled differently and not within the clock.

  for(int i = 0; i < n; i++){
    randOg.push_back(i);
  }

  vector<int> rand1(randOg);
  vector<int> rand2(randOg); //making copies here of vector's values.

  for(int i=0; i<5; ++i){
    BinarySearchTree* tree = new BinarySearchTree();
    random_shuffle(randOg.begin(), randOg.end(),myrandom); //shuffling the vectors.
    random_shuffle(rand1.begin(), rand1.end(),myrandom);
    random_shuffle(rand2.begin(), rand2.end(),myrandom);

    clock_t t1, t2;
    t1 = clock();

    for(int i = 0; i < n; i++){
      tree->Insert(randOg.at(i));
    }

    for(int i = 0; i < n; i++){
      tree->Access(rand1.at(i));
    }

    for(int i = 0; i < n; i++){
      tree->Delete(rand2.at(i));
    }
    t2 = clock();

    float diff = ((float)t2-(float)t1);
    diff = (diff/CLOCKS_PER_SEC)*1000;//will give time in milliseconds.

    cout << "The BST Tree ran through the randomized inserts, acc\
ess's and deletes for N = " << n << ", Test " << i
	 << " "  << diff <<" rate" << endl;

    v.push_back(diff);
  }
  cout << "The avg of the BST Tree for test 3 with N = " << n << " is " << getAverage(v) << "." << endl;
}

int main(){
  srand(time(0));
  
  AVLTreeTest1(1000);
  AVLTreeTest1(10000);
  AVLTreeTest1(50000);

  cout << endl;
  
  BSTTreeTest1(1000);
  BSTTreeTest1(10000);
  BSTTreeTest1(50000);

  cout << endl;
  
  AVLTreeTest2(1000);
  AVLTreeTest2(10000);
  AVLTreeTest2(50000);

  cout << endl;
  
  BSTTreeTest2(1000);
  BSTTreeTest2(10000);
  BSTTreeTest2(50000);

  cout << endl;
  
  AVLTreeTest3(1000);
  AVLTreeTest3(10000);
  AVLTreeTest3(50000);

  cout << endl;
  
  BSTTreeTest3(1000);
  BSTTreeTest3(10000);
  BSTTreeTest3(50000);
  }
