#include "MinHeap.h"

/* Begin {Implementation of MinHeap} */
/*  MinHeap(int) - Assigns space for a heap and vertexIndexArray of size size.
    ARGS - int size
*/
MinHeap::MinHeap(int size)
{
    last=0;                                 //heap uses indices starting at 1 for ease of computing parent of any node.
    heapSize = size;                        //heapSize is size
    heap = new HeapNode*[heapSize];         //Space for heapSize number of ptrs
    vertexIndexArray = new int[heapSize];   //Space for vertexIndexArray
    for(int i=0;i<heapSize;i++)             //Initialization of ptrs in heap[]
    {
        heap[i] = nullptr;
    }
}

/*  isEmpty() - Returns true if heap is unoccupied.
    ARGS - nothing
    RET - bool
*/
bool MinHeap::isEmpty()
{
    return (last==0)?true:false;//Heap is unoccupied if last is 0
}

/*  swap() - Exchanges the values at heap[i] and heap[j]. Updates the positions of vertices heap[i]->vertex and heap[j]->vertex.
    ARGS - int i,int j
    RET - nothing(void)
*/
void MinHeap::swap(int i,int j)
{
    vertexIndexArray[heap[i]->vertex]=j;    //heap[i]->vertex is now @j in heap
    vertexIndexArray[heap[j]->vertex]=i;    //heap[j]->vertex is now @i in heap
    //Stmts to exchange values of heap[i] and heap[j]
    HeapNode* temp = heap[i];   
    heap[i] = heap[j];
    heap[j] = temp;
}

/*  insert() - Inserts a vertex v with current sPL w into heap with upward percolation till minheap property is satisfied by heap.
    ARGS - NodeType v, WeightType w
    RET - void
*/
void MinHeap::insert(NodeType v,WeightType w)
{
    heap[++last] = new HeapNode{v,w};   //New HeapNode with vertex=v and sPL=w is put at last position of heap
    vertexIndexArray[v] = last;         //Updates position of v in heap to last
    int curPos = last;                  //Loop Variable for following ancestry path of the last node.
    while(curPos>1)
    {
        if(heap[curPos/2]->sPL > w)     //if parent at curPos/2 violates minheap property, do swap(curPos,curPos/2)
            swap(curPos/2,curPos);
        else                            //if parent of curPos satisfies minheap property, insertion is complete
            break;
        curPos/=2;                      //Loop Update
    }
}

/*  decreaseKey() - Decreases sPL of vertex v in heap to newSPL if newSPL < current sPL of v
    ARGS - NodeType v, WeightType newSPL
    RET - nothing(void)
*/
void MinHeap::decreaseKey(NodeType v, WeightType newSPL)
{
    int curPos = vertexIndexArray[v];   //Locating vertex v in heap
    if(newSPL < heap[curPos]->sPL)      //Check if newSPL < current sPL
        heap[curPos]->sPL = newSPL;
    else
        return ;
    while(curPos>1)                     //Loop for percolating upward. Same as the loop segment in insert()
    {
        if(heap[curPos/2]->sPL > newSPL)
            swap(curPos/2,curPos);
        else
            break;
        curPos/=2;
    }
}

/*  deleteRoot() - Deletes the root of heap and reheapifies the heap after placing the last node at the front
    ARGS - nothing
    RET - Pointer to the deleted root
*/
HeapNode* MinHeap::deleteRoot()
{
    HeapNode* rootNode = heap[1];       //ptr to deleted root
    last--;                             //last decrement
    if(last!=0)                         //if new heap is not empty
    {
        int curPos = 1;                             //Loop Variable for downward percolation
        int leftChildPos,smallChildPos;             //Positions of left child of heap[curPos] and smallest(the one with lower sPL) child of heap[curPos]
        heap[1] = heap[last+1];                     //Last node of heap is placed at the front
        vertexIndexArray[heap[1]->vertex] = 1;      //Update of position of last node's vertex
        while(1)                                    //Loop for downward percolation
        {
            leftChildPos = 2*curPos;
            if(leftChildPos<last)                               //if there is a right child for heap[curPos]
            {
                smallChildPos = (heap[leftChildPos]->sPL<heap[leftChildPos+1]->sPL)?leftChildPos:(leftChildPos+1);  //sets smallChildPos to index of the child with smaller sPL
            }
            else if(leftChildPos==last)                         //if there is left child only
            {
                smallChildPos = leftChildPos;
            }
            else                                                //Here,the old last node is at its final position
                break;
            if(heap[smallChildPos]->sPL<heap[curPos]->sPL)      //If heap[curPos] violates minheap property
            {
                swap(smallChildPos,curPos);                     //swaps nodes @ smallChildPos and curPos
                curPos = smallChildPos;                         //Loop Update
            }
            else
                break;
        }
    }
    return rootNode;                                            //Ptr to deleted root is returned.
}
/* End {Implementation of MinHeap} */