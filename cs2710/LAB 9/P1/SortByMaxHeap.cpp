/************************
* $ID$
* File:  SortByMaxHeap.cpp - Build a max heap from a list of integers,sort the list in non-increasing order by successive removal of root followed by reheapification.
*
* Purpose: Definition of Heap ADT (based on maxheap) with operations of insertion of a new element, deletion of root, 
*          check if empty, creation of new heap(initialization) and print heap by Level Order Traversal.
*          Use the maxheap to sort the elements in non-increasing order by popping the root till heap becomes empty.
*          
* Author: K V VIKRAM
*
* Created: [2020-10-08 12:08] by vikram
* 
* Last Modified: [2020-10-08 12:08] by vikram 
*
* Input Format:
*      Line 1: Number(N) of integers to be inserted in heap and sorted.
*      Line 2: The list of integers separated by space.
* Constraints:
*      1 <= N <= 1000
*      abs(integer entry) < 10000
* Output Format:
*      N Lines : Heap printed by LOT after every insertion
*      2*N Lines : Line I - Deleted Root element
*                  Line II - Heap after deletion
*      Last Line : The input integers sorted in non-increasing order.
*
* Compilation:  Compile and run with g++ IntMaxHeap.h IntMaxHeap.cpp SortByMaxHeap.cpp -o soln, ./soln
*
* Bugs:     No major bugfixes or new releases
*************/

#include "IntMaxHeap.h"
#include <climits> // for INT_MIN underflow indication

int main(){
    int numElem;//number of elements
    Heap myHeap;//myHeap - stores input elements in a maxheap
    ElementType readElem;//stores read input
    ElementType* sortedList;//ptr for sorted array of elements
    myHeap.createHeap();
    cin >> numElem;//numElem is scanned
    for(int i=0;i<numElem;i++)//Loop for scanning and inserting elements in myHeap.Prints the heap by LOT after every insertion
    {
        cin >> readElem;
        myHeap.insertHeap(readElem);
        myHeap.printHeap();
    }
    sortedList = new ElementType[numElem];//space for sorted array is allocated
    for(int i=0;i<numElem;i++)//Popping roots iteratively till heap becomes empty
    {
        sortedList[i] = myHeap.deleteRoot();//largest element(root) of heap is popped and put in sortedHeap
        cout << sortedList[i] << endl;//popped root is displayed
        myHeap.printHeap();//myHeap is printed
    }
    for(int i=0;i<numElem;i++)//Loop for printing sorted array of elements
    {
        cout << sortedList[i] << ' ';
    }
    cout << endl;
    delete[] sortedList;//space for sorted array is de-allocated
    return 0;
}