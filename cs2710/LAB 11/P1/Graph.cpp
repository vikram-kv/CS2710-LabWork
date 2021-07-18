#include "Graph.h"

/* Begin {Implementation of Graph} */
/*  createEmptyGraph() - Creates a graph with vertexCount vertices and no edges.
    ARGS - int vertexCount
    RET - nothing(void)
*/
void Graph::createEmptyGraph(int vertexCount)
{
    v = vertexCount;    
    adjLists = new AdjacencyList[vertexCount];  //calls default constructor of class AdjacencyList
}

/*  addEdge() - Adds an edge between vertices u and v of weight w
    ARGS - NodeTyep u,NodeType v,WeightType w
    RET - nothing(void)
*/
void Graph::addEdge(NodeType u, NodeType v, WeightType w)
{
    adjLists[u].addNode(v,w);   //adds v to adjList of u with C(u,v) = w
    adjLists[v].addNode(u,w);   //adds u to adjList of v with C(v,u) = w
}

/*  returnList() - Returns a reference to adjacency List of vertex u
    ARGS - NodeType u
    RET - AdjacencyList adjLists[u]
*/
AdjacencyList& Graph::returnList(NodeType u)
{
    return adjLists[u];
}

/*  returnVertexCount() - Returns the number of vertices in the graph
    ARGS - nothing
    RET - int v
*/
int Graph::returnVertexCount()
{
    return v;
}
/* End {Implementation of Graph} */