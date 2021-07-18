#include "AdjacencyList.h"

/* Begin {Implementation of AdjacencyList} */
/*  addNode - adds a AdjacencyNode with adjNode = u and edgeWeight = w to the list at the head.
    ARGS - NodeType u, WeightType w
    RET - nothing(void)
    USE - indicates the vertex of the list(say v) is adjacent to u and C(u,v) = w
*/
void AdjacencyList::addNode(NodeType u,WeightType w)
{
    AdjacencyNode* temp = new AdjacencyNode;
    temp->adjNode = u;
    temp->edgeWeight = w;
    temp->next = head;
    head = temp;
}

/*  returnHead() - returns a pointer to the first node in the list
    ARGS - nothing
    RET - AdjacencyNode*
    USE - For external access to the list for traversal
*/
AdjacencyNode* AdjacencyList::returnHead()
{
    return head;
}
/* End {Implementation of AdjacencyList} */