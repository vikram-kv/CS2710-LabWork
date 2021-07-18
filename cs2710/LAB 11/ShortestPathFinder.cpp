/************************
* $ID$
* File:  ShortestPathFinder.cpp - Uses Djikstra's algorithm to find the shortest path length(path length = sum of weights of all edges in the path) in an weighted undirected graph between the first vertex and all other vertices.
*
* Purpose: Usage of Djikstra's algorithm to find Shortest path length between a source vertex and all other vertices in a graph. Also implements a Graph ADT using adjacency lists.
*          The vertex with the least SPL is found by maintaining minheap of vertices along with their SPLs. A special MinHeap ADT is used for this purpose.O(n) search is avoided
*          in MinHeap by storing positions of all vertices in the heap.
*
* Author: K V VIKRAM
*
* Created: [2020-10-22 20:42] by vikram
* 
* Last Modified: [2020-10-26 20:53] by vikram 
*
* Input Format:
*      Line 1: Number of vertices(m) in the graph + ' ' + Number of edges(n) in the graph
*      Next E lines: u v w (Indicating edge uv is in graph with weight Cost(u,v) = w)
* Constraints:
*      m,n,u,v,w are all integers satisfying
*           0 < m,n < 1000
*           0 <= u,v < m
*           0 < w < 1000
*      All SPLs lie in the range of int(This is not very strict.If this constraint fails, replace int in typedef int WeightType with long and INT_MAX in #define INFINITY INT_MAX with LONG_MAX)
* Output Format:
*      Contains m lines
*      Line k : Least cost of reaching vertex k-1 from vertex 0
*
* Compilation:  g++ AdjacencyNode.h AdjacencyList.h AdjacencyList.cpp Graph.h Graph.cpp HeapNode.h MinHeap.h MinHeap.cpp ShortestPathFinder.cpp -o solution, ./solution.
*
* Bugs:     No major bugfixes or new releases
*************/
#include <iostream>
#include "Graph.h"
#include "MinHeap.h"
#include <climits>  //For use of INT_MAX 
#define INFINITY INT_MAX
using namespace std;

/*  DjikstraSPA() - Uses Djikstra's shortest path algorithm to find the shortest path between vertex 0 of a graph and all other vertices.
                    sPLArray[i] stores the required shortest path length between vertex i and vertex 0. statusArray is a character array
                    where statusArray[i] = 'K' if the vertex i has been processed fully(its sPL from 0 is known) , = 'H' if vertex i is in heap,
                    = 'U' if vertex i is unknown(A path through known vertices from 0 to i hasnt been found).
    ARGS - A reference to a graph - Graph& G
    RET - A array of sPL between vertex 0 and all vertices through pointer - WeightType* sPLArray             
*/
WeightType* DjikstraSPA(Graph& G)
{
    //Variable Declarations
    int vertexCount=G.returnVertexCount();  //Number of vertices in the graph G
    WeightType* sPLArray;                   //Stores sPL between vertex 0 and all vertices
    char* statusArray;                      //Stores status of all vertices. 'K' if known, 'H' if in heap, 'U' if unknown
    MinHeap myHeap(vertexCount);            //myHeap stores HeapNodes of vertices with their sPLs in a minheap for ease of deletion and insertion.Initialized with a capacity of vertexCount
    HeapNode* deletedHeapNode;              //Stores deleted root node from heap in loop
    NodeType delNode;                       //Stores vertex of deletedHeapNode
    AdjacencyNode* curListPtr;              //Used to traverse current list(adjacency list of delNode) in inner while loop
    NodeType curNode;                       //Stores curNode = value of adjNode @curListPtr
    WeightType delSPL;                      //delSPL stores the final sPL of the delNode. 
    WeightType newPathLength;               //newPathLength stores the calculated path length using previously known vertices and delNode for the path from 0 to curNode.
    //Initialization Segment
    sPLArray = new WeightType[vertexCount];     //sPLArray is allocated space
    statusArray = new char[vertexCount];        //statusArray is allocated space
    for(int i=0;i<vertexCount;i++)              //Loop to initialize sPLArray and statusArray
    {
        sPLArray[i] = INFINITY;                 //No path is known for any vertex from vertex 0
        statusArray[i] = 'U';                   //All vertices are unknown
    }
    myHeap.insert(0,0);                         //vertex 0 is inserted with sPL = 0
    //Loop Segment
    while(!myHeap.isEmpty())                                    //If all vertices connected to vertex 0 have been exhausted so that myHeap is empty
    {
        deletedHeapNode = myHeap.deleteRoot();                  //root of myHeap is deleted
        delNode = deletedHeapNode->vertex;                      //vertex @root of myHeap
        delSPL = deletedHeapNode->sPL;                          //sPL of delNode
        statusArray[delNode] = 'K';                             //sPL of delNode is final and hence, delNode is known
        sPLArray[delNode] = delSPL;                             //sPL of delNode is stored
        curListPtr = (G.returnList(delNode)).returnHead();      //Head of list of adjacent nodes to delNode is obtained
        while(curListPtr!=NULL)                                 //Till all adjacent nodes have been exhausted
        {
            curNode = curListPtr->adjNode;                      //current adjacent node @curListPtr
            newPathLength = delSPL+curListPtr->edgeWeight;      //path length using delNode and edge from delNode to curNode
            if(statusArray[curNode]=='U')                       //if there was no path from 0 to curNode using known vertices till now
            {
                myHeap.insert(curNode,newPathLength);           //curNode is inserted in the heap
                statusArray[curNode]='H';                       //curNode status is updated
            }
            else if(statusArray[curNode]=='H')                  //if curNode is already in heap
            {
                myHeap.decreaseKey(curNode,newPathLength);      //curNode sPL is updated
            }
            curListPtr=curListPtr->next;                        //Loop Update
        }
        delete deletedHeapNode;                                 //Frees heap memory allocated
    }
    delete[] statusArray;                                       //statusArray is deleted
    return sPLArray;                                            //Array of sPLs is returned
}

int main()
{
    //Variable Declarations
    Graph G;                    //Graph for which Djikstra's SPA needs to be used to find sPLs of all vertices from vertex 0
    int vertexCount,edgeCount;  //vertexCount - number of vertices in G. edgeCount - number of edges in G
    NodeType u,v;               //Used for storing edge endpoints input
    WeightType w;               //used for storing edge weight input
    WeightType* sPLArray;       //Stores sPL of all vertices from vertex 0
    //Input Segment
    cin >> vertexCount >> edgeCount;    
    G.createEmptyGraph(vertexCount);    //G is initialized to empty graph with vertexCount vertices
    for(int i=0;i<edgeCount;i++)        //Loop to obtain edges in G
    {
        cin >> u >> v >> w;
        G.addEdge(u,v,w);               //edge uv with weight w is added to G
    }
    sPLArray = DjikstraSPA(G);          //sPLArray is computed
    //Output Segment
    for(int i=0;i<vertexCount;i++)      //sPLArray is printed in req. format
    {
        cout << i << ' ' <<sPLArray[i] << endl;
    }
    delete[] sPLArray;                  //Memory allocated to sPLArray is freed
    return 0;
}