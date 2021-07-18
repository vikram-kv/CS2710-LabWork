#ifndef TREE_H
#define TREE_H
#include "TreeNode.h"
#include <iostream>
using namespace std;

/*  The class Heap defines an ADT Tree. */
/* begin{Definition of class Tree} */
class Tree {
  private:
    treeptr root;
    void printTreeHelper(treeptr ptr,int val);
    treeptr makeTreeHelper(treeptr ptr,int val);
    int max(int x, int y); 
  public:
     void createNode (int E, Tree L, Tree R);
     void makeTree(int *array, int n);
     treeptr getRoot();
     void printTree();    
     int height(treeptr ptr);
     int numLeaves(treeptr ptr);
     Tree(){root = NULL;}
     ~Tree () { delete root;}
};
/* end{Definition of class Tree} */

#endif
