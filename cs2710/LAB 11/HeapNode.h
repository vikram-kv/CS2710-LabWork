#ifndef HEAP_NODE_H
#define HEAP_NODE_H

#include "AdjacencyNode.h"	//For the type definitions of NodeType and WeightType

/*  HeapNode - Node for the class MinHeap
    Members - NodeType vertex(a graph vertex), WeightType sPL(ShortestPathLength using known vertices)
*/
struct HeapNode
{
    NodeType vertex;
    WeightType sPL;
};

#endif
