#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

#include <iostream>
#include "AdjacencyNode.h"
using namespace std;

/*  AdjacencyList - A special list ADT which is used to store the adjacency list of a vertex in linked list representation.
    Data Members - head (A pointer to the first AdjacencyNode in the list)
    Mutator function - addNode(NodeType,WeightType) - adds a new node to the list
    Accessor function - returnHead() - returns a pointer to the first node in the list 
    Constructor - AdjacencyList() - creates empty list
    Destructor - ~AdjacencyList() - deletes the entire list
*/
/* Begin {Definition of AdjacencyList} */
class AdjacencyList
{
    AdjacencyNode* head;        //ptr to first node in the list
public:
    AdjacencyList()             //creates empty list
    {
        head = nullptr;
    }
    void addNode(NodeType,WeightType);
    AdjacencyNode* returnHead();
    ~AdjacencyList()            //Iteratively empties the list
    {
        AdjacencyNode* temp;
        while(head!=nullptr)
        {
            temp=head;
            head=head->next;
            delete temp;
        }
    }
};
/* End {Definition of AdjacencyList} */

#endif