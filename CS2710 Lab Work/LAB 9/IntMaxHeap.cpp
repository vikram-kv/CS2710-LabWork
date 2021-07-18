#include "IntMaxHeap.h"
/* Begin{Implementation of class Heap} */

/* insertHeap() - Inserts a new element x into the heap
   ARG - Element to be inserted x of type ElementType
   RETURNS - Nothing 
   IMPLEMENTATION - New Element is inserted to maintain completeness of the heap at the last+1 position.
                    The element then percolates up by comparison with its ancestors till a position 
                    where maxheap property is satisfied. A dummy node is at index 0 for ensuring fewer 
                    arithmetic operations are done while computing indices of child nodes and parent node.
                    So, in this implementation, if a node's position is i, its children are at 2i and 2i+1 whereas
                    it's parent(for i!=1) is at floor(i/2) = i/2 in int arithmetic.The root is at index 1.
    */
void Heap::insertHeap(ElementType x)
{
    Position curPos;//Used as a loop variable.Stores the position under consideration presently
    ++last;//update 
    curPos = last;//curPos is now the location of x. curPos takes the indices on ancestry path of x only in the loop.
    while(curPos>1)//if curPos is not the root
    {
        if(priority[curPos/2]<x)//if x is larger than its parent 
        {
            priority[curPos] = priority[curPos/2];//parent is moved to its child's location on ancestry path of x
        }
        else//Here,curPos is x's final position(if x is put at curPos,x's parent will satisfy maxheap property)
        {
            priority[curPos] = x;
            break;
        }
        curPos=curPos/2;//loop update. updated curPos is location of parent of old curPos.
    }
    if(curPos==1)//if the loop has run till the root or has not run at all, then x is to be placed at root of the heap
        priority[curPos]=x;
}

/* deleteRoot() - Deletes the root of the heap and reheapifies the heap after putting the last element at the root.
   ARG - None
   RETURNS - The deleted root element
   IMPLEMENTATION - The root is deleted first. The last element(the right most element in the last level) is placed at
                    at the root and then it percolates down to its right place(when maxheap criteria is satisfied by it)
   */
ElementType Heap::deleteRoot()
{
    if(last==0)//Underflow
        return ElementType(INT_MIN);
    else
    {
        last--;//update
        if(last==0)//if new heap is empty
            return priority[1];
    }
    ElementType delRoot,lastElem;//delRoot stores the deleted root. lastElem stores the last element of the heap
    Position curPos,leftChildPos,largeChildPos;//curPos - current node under consideration for lastElem in loop,leftChildPos - left child of current node,largeChildPos - larger child of current node
    lastElem = priority[last+1];//the last element is obtained
    delRoot = priority[1];//deleted root is found
    curPos = 1;//testing for lastElem's final position starts at root
    while(1)
    {
        leftChildPos=2*curPos;
        if(leftChildPos+1<=last)//there is a right child as well
        {
            largeChildPos = (priority[leftChildPos+1]>priority[leftChildPos])?(leftChildPos+1):leftChildPos;
        }
        else if(leftChildPos==last)//there is only left child
        {
            largeChildPos = leftChildPos;
        }
        else//curPos is in the last level, we are done
        {
            priority[curPos]=lastElem;
            break;
        }
        if(priority[largeChildPos]>lastElem)//larger child of curPos is larger than lastElem
            priority[curPos] = priority[largeChildPos];//larger child is assigned to curPos position
        else//lastElem placed at curPos will satisfy maxheap property
        {
            priority[curPos] = lastElem;
            break;
        }
        curPos = largeChildPos;//loop update
    }
    return delRoot;
}

/* empty() - Returns 1 if the heap is empty
   ARG - None
   RETURNS - 1 if heap is empty, else 0
   */
int Heap::empty()
{
    return (last==0);
}

/* printHeap() - Prints the heap by performing Level Order Traversal of nodes
   ARG - None
   RETURNS - Nothing
   IMPLEMENTATION - Level Order traversal of heap in array based implementation is the same as traversal of the array from left to right.
   */
void Heap::printHeap()
{
    if(last==0)//Heap is empty
    {
        cout << "EMPTY HEAP" << endl;
    }
    else
    {
        for(int i=1;i<=last;i++)
        {
            cout << priority[i] << ' ';
        }
        cout << endl;
    }
}

/* createHeap() - Initializes/Resets the data of a heap to that of an empty one.
   ARG - None
   Returns - None
   */
void Heap::createHeap()
{
    last=0;
}

/* End{Implementation of class Heap} */