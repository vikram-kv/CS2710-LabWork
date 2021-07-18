#ifndef ADJACENCY_NODE_H
#define ADJACENCY_NODE_H

typedef int NodeType;   //NodeType - Vertex of graph(A non-negative integer)
typedef int WeightType; //WeightType - Weight of an edge of or path in graph(A non-negative integer)

/*  AdjacencyNode - A node in adjacency list of graph vertices
    Members - adjNode (The adjacent vertex), edgeWeight (The weight of the edge joining adjNode with the list's vertex)
              next (Pointer to next adjacency Node in adjacency list)
*/
struct AdjacencyNode
{
    NodeType adjNode;
    WeightType edgeWeight;
    AdjacencyNode* next;
};

#endif