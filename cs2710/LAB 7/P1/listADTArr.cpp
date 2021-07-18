#include <iostream>
#include "listADTArr.h"
using namespace std;

/* begin{Implementation of the class List} */

//Creates an array of elementType of size 10000 and
//assigns it to member *list
void List::makeNull() {
  list = new elementType[100000]; 
  lastNode = 0;
}

//Inserts an element x at index p in the array list
//Returns null and updates lastNode after insertion
void List::insert(elementType x, Position p) {
  int i;
  for (i = lastNode+1; i > p; i--)
    list[i] = list[i-1];
  list[p] = x;
  lastNode++;
}

//Prints the entire list in a single line separated by space
//Prints '$' if list is empty
void List::printList() {
  Position p;
  p = 1;
  while (p <= lastNode) {
    cout << list[p] << " ";
    p++;
  }
  if(lastNode==0)
    cout << '$';
  cout << endl;
 }

 //Gives the first unoccupied position in the array list
Position List::end() {
  Position p;
  p = lastNode + 1;
  return(p);
}

//Deletes the element at position p of the list
void List::delItem(Position p) {
  int i;
  for (i = p; i < lastNode; i++)
    list[i] = list[i+1];
  lastNode = lastNode - 1;
}

//Gives the index of the first position in list
//Since 0 is reserved for the sentinel element, this is 1
Position List::first() {
  return(1);
}

//Gives the position next to p in the array list
Position List::next(Position p) {
  return (p+1);
}
//Returns the element at position p of the array list
elementType List::retrieve (Position p) {
  return (list[p]);
}

//Function that swaps the elements at indices i and j of the
//array list
void List::swap(Position i, Position j)
{
  elementType temp;
  temp=list[i];
  list[i]=list[j];
  list[j]=temp;
}

/*Private member function(to be used only by quickSortList())
  that partitions the list portion between bIndex and eIndex
  into two parts by using the lomuto partition scheme.
  Algorithm:
    Fix the last element as the pivot element.
    Make a pass through the array and when a element <= pivot at j
    is found, exchange it with the element at i in the left segment of
    the array.
    Finally, exchange the pivot with the element at i+1
  Upon Completion, list[bIndex..i] <= pivot , list[i+1..eIndex]>pivot
  and pivot is in its final position
  Returns the final position of the pivot.
*/
Position List::partition(Position bIndex,Position eIndex)
{
  int pivot=list[eIndex];//pivot element
  Position i,j;//i is the free position for swap, j is ptr for traversal
  i=bIndex-1;
  j=bIndex;
  while(j<eIndex)//till j is the index of the pivot element
  {
    if(list[j]<=pivot){//if element at j is not greater than pivot
      i++;
      swap(i,j);//stmt to exchange the elements at i and j
    }
    j++;//loop update
  }
  swap(eIndex,i+1);//places the pivot in its final position
  return (i+1);//returns pivot index
}

/* Recursive Function that uses the quicksort algorithm to sort the array list
   in the segment[bIndex..eIndex]. Can be used recursively to sort the whole 
   list.
*/
void List::quickSortList(Position bIndex,Position eIndex)
{
    if(bIndex<eIndex)
    {
      Position pivotLoc=partition(bIndex,eIndex);//Partitions the array portion [bIndex..eIndex]
      quickSortList(bIndex,pivotLoc-1);//Sorts the elements with value <= list[pivotLoc]
      quickSortList(pivotLoc+1,eIndex);//Sorts the elements with value > list[pivotLoc]
    }
}

/* end {Implementation of List} */

