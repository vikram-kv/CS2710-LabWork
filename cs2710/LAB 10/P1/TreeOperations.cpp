/************************
* $ID$
* File:  TreeOperations.cpp - Uses an ADT Tree implemented by leftMostChild-rightSibling Representation which allows the operations of traversal(POST ORDER), create empty tree, insert new nodes , print the height and count the number of leaves.
*
* Purpose: Usage of Special Type of Tree ADT where all nodes have unique values, larger nodes than a given node are inserted in the rightSibling branch and smaller nodes than a given node are inserted in the leftMostChild Branch. 
* 
* Author: K V VIKRAM
*
* Created: [2020-10-18 20:03] by vikram
*  
* Last Modified: [2020-10-18 20:03] by vikram 
*
* Input Format:
*      Line 1: Number(N) of nodes in the tree(not including the root node)
*      LIne 2: Value at each node represented by space
* Constraints:
*      1 <= N <= 10000
*      Root Node has value 0
*      1 =< Value at non-root nodes <= 10^5
*      All nodes have unique values
* Output Format:
*      Line 1: Height of the tree is: (Height of tree)
*      LIne 2: Number of Leaves: (Number of Leaves in tree)
*
* Compilation:  Compile and run with g++ TreeNode.h Tree.h Tree.cpp TreeOperations.cpp -o solution, ./solution
*
* Bugs:     No major bugfixes or new releases
*************/
#include "Tree.h"

/*-------------------------------------------------------------------------
 *  main -- Main program
 *    Args: 
 *    Returns:  int
 *    Throws: 
 *    See:  
 *    Bugs: 
 -------------------------------------------------------------------------*/
int main() {
  Tree T1;
  int i, n;
  int *array;
  cin >> n;
  array = new int [n];
  for (i = 0; i < n; i++)
    cin >> array[i];
  T1.makeTree(array, n);
  cout << "Height of the tree is: " << T1.height(T1.getRoot())<< endl;
  cout << "Number of Leaves: "<< T1.numLeaves(T1.getRoot()) << endl;
  return 0;
}