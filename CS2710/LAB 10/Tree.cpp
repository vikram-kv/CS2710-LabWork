#include "Tree.h"

/* Begin{Implementation of class Heap} */

/*-------------------------------------------------------------------------
 *  createNode -- creates a new node @root with value = E and leftmost child @leftMostChild and rightSibling @rightSibling
 *    Args: int, Tree, Tree
 *    Returns:  Nothing
 *    Throws: 
 *    See:  
 *    Bugs: 
 -------------------------------------------------------------------------*/
void Tree::createNode(int E, Tree leftMostChild, Tree rightSibling) {
   root = new TreeNode;
   root->leftMostChild = leftMostChild.getRoot();
   root->rightSibling = rightSibling.getRoot();
   root->element = E;
}

/*-------------------------------------------------------------------------
 *  getRoot -- Returns the root of a given node
 *    Args: Nothing
 *    Returns:  treeptr
 *    Throws: 
 *    See:  
 *    Bugs: 
 -------------------------------------------------------------------------*/
treeptr Tree::getRoot()
{
  return(root);
}

/*-------------------------------------------------------------------------
 *  max -- max of two integer variables
 *    Args: int, int 
 *    Returns:  returns the maximum of two numbers
 *    Throws: 
 *    See:  
 *    Bugs: 
 -------------------------------------------------------------------------*/
int Tree::max(int x, int y) {
  if (x > y) 
    return(x);
  else
    return(y);
}

/*-------------------------------------------------------------------------
 *  makeTreeHelper -- a private function
 *    Args: treeptr, int
 *    Returns: tree
 *    Throws: 
 *    See:  
 *    Bugs: 
 -------------------------------------------------------------------------*/
treeptr Tree::makeTreeHelper(treeptr ptr,int i) {
  if (ptr == NULL) {
    ptr = new TreeNode;
    ptr->element = i;
    ptr->leftMostChild = NULL;
    ptr->rightSibling = NULL;
  }
   else if (i < ptr->element) 
     ptr->leftMostChild = (treeptr) makeTreeHelper(ptr->leftMostChild,i);
   else if (i > ptr->element)
     ptr->rightSibling = (treeptr) makeTreeHelper(ptr->rightSibling,i);
 return(ptr);
}

/*-------------------------------------------------------------------------
 *  printTreeHelper -- a private function recursively prints elements in the tree
 *    Args: treeptr, int
 *    Returns: tree
 *    Throws: 
 *    See:  
 *    Bugs: 
 -------------------------------------------------------------------------*/
void Tree::printTreeHelper(treeptr ptr,int val) {
  if (ptr != NULL) {
    printTreeHelper(ptr->leftMostChild,0);
    cout << " " << ptr->element << " value " << val << endl ;
    printTreeHelper(ptr->rightSibling,1);
  }
}

/*-------------------------------------------------------------------------
 *  printTree -- public interface function to printTree
 *    Args: Nothing
 *    Returns:  Nothing
 *    Throws: 
 *    See:  
 *    Bugs: 
 -------------------------------------------------------------------------*/
void Tree::printTree() {
  if (root != NULL)
    printTreeHelper(root,0);
  else
    cout << "root is NULL\n";
}

/*-------------------------------------------------------------------------
 *  makeTree -- create a tree with leftMostChild, rightSibling
 *    Args: int*, int
 *    Returns:  makes the tree
 *    Throws: 
 *    See:  
 *    Bugs: 
 -------------------------------------------------------------------------*/
void Tree::makeTree(int *array, int n) {
  int i = 0;
  root = new TreeNode;
  root->leftMostChild = NULL;
  root->rightSibling = NULL;
  root->element = 0;
 
  while (i < n) {
      root->leftMostChild = (treeptr) makeTreeHelper(root->leftMostChild,array[i]);
      i++;
   }
}

/*-------------------------------------------------------------------------
 *  height -- returns the height of a tree
 *    Args: treeptr
 *    Returns:  int
 *    Throws: 
 *    See:  
 *    Bugs: 
 -------------------------------------------------------------------------*/
int Tree::height(treeptr ptr) {
    if(ptr->leftMostChild==NULL)//if the node @ptr corresponds to a leaf
      return 0;
    else { //Here, @ptr has atleast one child
        treeptr childCounter = ptr->leftMostChild;//childCounter - loop variable for children of node @ptr
        int maxChildHeight = 0;//maxChildHeight - maximum height among subtrees with roots as children of node @ptr
        //Loop to iterate through @ptr's children
        while(childCounter!=NULL) {
            maxChildHeight = max(maxChildHeight,height(childCounter));//max height check and update
            childCounter=childCounter->rightSibling;//loop update
        }
    return (1+maxChildHeight);//height is increased by 1 to account for root node @ptr
    }
}

/*-------------------------------------------------------------------------
 *  numLeaves -- returns the number of leaves in the tree
 *    Args: treeptr
 *    Returns:  int
 *    Throws: 
 *    See:  
 *    Bugs: 
 -------------------------------------------------------------------------*/
int Tree::numLeaves(treeptr ptr) {
    if(ptr->leftMostChild==NULL)//if the node @ptr corresponds to a leaf
        return 1;
    else { //Here, @ptr has atleast one child
        int noOfLeaves = 0;//number of leaves in tree with root @ptr
        treeptr childCounter = ptr->leftMostChild;//loop variable for children of @ptr
        //Loop to iterate through @ptr's children
        while(childCounter!=NULL) {
            noOfLeaves += numLeaves(childCounter);//number of leaves increment
            childCounter=childCounter->rightSibling;//loop update
        }
        return (noOfLeaves);//no of leaves is returned
    }
}
/* End{Implementation of class Heap} */
