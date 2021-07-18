#ifndef GRAPH_H
#define GRAPH_H

#include "AdjacencyList.h"
/*  Graph - An ADT Graph implemented by adjacencylists. Vertices are of NodeType and adjacency lists are of type AdjacencyList.
    Data Members - v (Number of vertices in the graph), adjLists (Array of adjacency lists).Here, the understanding is the vertices
                   are named as(by having NodeType as) 0,1...,v-1 and adjLists[i] is the adjacency list of vertex i.
    Mutators -  createEmptyGraph(int) - creates an edgeless graph
                addEdge(NodeType,NodeType,WeightType) - adds an edge to the graph
    Accessors - returnList&(NodeType) - returns a reference to AdjacencyList of chosen vertex
                returnVertexCount() - returns the no of vertices in the graph
    Constructor - Graph() - creates an empty graph G=(V,E) with |V|=|E|=0
*/
/* Begin {Definition of Graph} */
class Graph
{
    int v;                      //Number of Vertices
    AdjacencyList* adjLists;    //Array of AdjacencyList
public:
    Graph()                     //Initialises to NULL graph (0 vertices)
    {
        v = 0;
        adjLists = nullptr;
    }
    void createEmptyGraph(int);
    void addEdge(NodeType,NodeType,WeightType);
    AdjacencyList& returnList(NodeType);
    int returnVertexCount();
    ~Graph()
    {
        delete[] adjLists;
    }
};
/* End {Definition of Graph} */

#endif