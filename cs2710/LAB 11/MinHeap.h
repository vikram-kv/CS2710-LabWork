#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <iostream>
#include "HeapNode.h"
using namespace std;

/*  MinHeap - Defines a special MinHeap(For Use With Graph ADT) to maintain shortest path length using known vertices
    only in a std MinHeap to facilitate finding the vertex with the least sPL.Also, allows storage of positions of all vertices 
    in the heap in an array to avoid a O(n) search while decreaseKey().
    Data Members - heap - Array of HeapNode pointers which allow arraybased implementation of MinHeap
                   last - Last Occupied Location in heap
                   heapSize - size of heap array and vertexIndexArray
                   vertexIndexArray - array of integers where vertexIndexArray[i] stores the position of vertex i in heap. 
    Private Mutator - swap(int i,int j) - Swaps the values of heap[i] and heap[j].Also Updates vertexIndexArray[heap[i]->vertex] to j and vice versa.
    Public:
        Mutator - insert(NodeType,WeightType) - Inserts a HeapNode with a vertex and its current sPL
                  decreaseKey(NodeType,WeightType) - Decreases sPL of a vertex to a new value if new value < old sPL
                  deleteRoot() - Deletes the root node of the heap and returns a pointer to it
        Accessor - isEmpty() - Finds whether heap is empty
        Constructor - MinHeap() - Initializes to a empty heap
                      MinHeap(int) - Initializes by assigning memory for heap and vertexIndexArray.Updates last and heapSize
        Destructor - Deallocates heap memory
*/
/* Begin {Definition of MinHeap} */
class MinHeap
{
    HeapNode** heap;        //Array of HeapNode ptrs
    int last;               //Last Occupied Position
    int heapSize;           //Length of Heap
    int* vertexIndexArray;  //Array of vertex positions. [i] gives position of vertex i in heap
    void swap(int,int);
public:
    MinHeap()               //heap of capacity 0
    {
        heap = nullptr;
        last = 0;           //heap uses indices starting at 1 for ease of computing parent of any node.
        heapSize = 0;
        vertexIndexArray = nullptr;
    }
    MinHeap(int size);
    bool isEmpty();
    void insert(NodeType,WeightType);
    void decreaseKey(NodeType,WeightType);
    HeapNode* deleteRoot();
    ~MinHeap()              //Deallocates heap memory
    {
        delete[] heap;
        delete[] vertexIndexArray;
    }
};
/* End {Definition of MinHeap} */

#endif