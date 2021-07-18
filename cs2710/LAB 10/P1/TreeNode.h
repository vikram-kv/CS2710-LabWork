#ifndef TREE_NODE_H
#define TREE_NODE_H

/* Defines a structure tnode - Node of a int tree */
typedef struct tnode* treeptr;
typedef struct tnode {
    int element;
    treeptr leftMostChild;
    treeptr rightSibling;
} TreeNode; 

#endif
