/************************
* $ID$
* File:   UnionIntersection.cpp - Perform Set Operations of union and intersection using List ADT's
*         array based implementation from listADTArr.h
*
* Purpose: To compute the union and intersection of two sets of integers, sort them
*          and print them. Uses List ADT for storing and processing sets.
*          
* Author: K V VIKRAM
*
* Created: [2020-09-16 15:18] by vikram
*
* Last Modified: [2020-09-17 11:18] by vikram 
*
* Input Format:
*     Line 1: Number of elements in set A and set B
*     Line 2: Elements of set A with repetitions(if any)
*     Line 3: Elements of set B with repetitions(if any)
* Constraints:
*     0<Integers inputted <= 10^6
*     Number of unique elements in either set <= 50000(As there is an off chance
*     that A U B has 10^5 elements in this case)
* Output Format:
*     Line 1: Elements of A U B without repetition and in sorted order.
*     Line 2: Elements of A AND B without repetition and in sorted order.
*
* Compilation:  Compile and run with g++ FindUnionAndIntersection.cpp listADTArr.cpp listADTArr.h -o soln, ./soln
*
* Bugs:     No major bugfixes or new releases
*************/

#include "listADTArr.h"
#include <iostream>
using namespace std;

/* Function that finds the union of two sets represented by lists A and B
   Returns the list which represents A U B.
   Arguments: List A,B
   Returns: C = A U B
*/
List Union(List A, List B) {
  List C;//C will store A U B
  C.makeNull();
  Position ptrA,ptrB;//ptrA,ptrB are pointers for A and B respectively.
  Position endA,endB;//endA,endB store the end locations of A and B respectively.
  int flag;//flag is used for avoiding duplication
  int curValue;//used in nested loop for limiting calls of retrieve().
  endA=A.end();
  endB=B.end();
  ptrA=A.first();
  while(ptrA!=endA)//Loop to copy whole of A to C
  {
    C.insert(A.retrieve(ptrA),C.end());
    ptrA=A.next(ptrA);
  }
  ptrB=B.first();
  while(ptrB!=endB)//Loop to copy elements of B/A to C
  {
    flag=0;//0 at end of inner loop indicates curValue is not in A
    ptrA=A.first();
    curValue=B.retrieve(ptrB);
    while(ptrA!=endA)//Loop for traversing A 
    {
      if(A.retrieve(ptrA)==curValue)//if curValue is in A
      {
        flag=1;//curValue is not to be inserted again in C
        break;
      }
      ptrA=A.next(ptrA);//Loop Update
    }
    if(flag==0)
      C.insert(curValue,C.end());//curValue is inserted as it is not in A
    ptrB=B.next(ptrB);//Loop Update
  }
  return C;//A U B is returned
}

/* Function that finds the intersection of two sets represented by lists A and B
   Returns the list which represents A intersection B.
   Arguments: Lists A , B
   Returns: C= A and B 
*/
List Intersection(List A, List B) {
  
  List C;//C will store A and B
  C.makeNull();
  Position ptrA,ptrB;//ptrA,ptrB are pointers for A and B respectively.
  Position endA,endB;//endA,endB store the end locations of A and B respectively.
  endA=A.end();
  endB=B.end();
  ptrA=A.first();
  int flag;//flag is used for checking common-ness
  int curValue;//used in nested loop for limiting calls of retrieve().
  while(ptrA!=endA)//Loop to traverse list A
  {
    ptrB=B.first();
    curValue=A.retrieve(ptrA);
    flag=0;//0 at end of inner loop indicates curValue is not common to A and B
    while(ptrB!=endB)//Loop to traverse list B
    {
      if(B.retrieve(ptrB)==curValue)//if curValue is in B
      {
        flag=1;//indicates curValue is to be inserted in C
        break;
      }
      ptrB=B.next(ptrB);//Loop Update
    }
    if(flag==1)
    {
      C.insert(curValue,C.end());//curValue is inserted in C
    }
    ptrA=A.next(ptrA);//Loop Update
  }
  return C;//returns A and B
}

/* Function to get size number of elements of type elementType from stdin
  and store them in an array and return a pointer to it.
*/
elementType* GetElements(int size)
{
  elementType* arr = new elementType[size];
  for(int i=0;i<size;i++)
    cin >>arr[i];
  return arr;
}

/* Function to create a list from an elementType array of size size.
   As the list represents a set, duplication is avoided
   Arguments: A - ptr to the list, arr - elementType array,
              size - size of arr
    Returns: nothing
*/
void CreateList(List *A,elementType* arr,int size)
{
  A->makeNull();//List at A is initialized
  int flag;//checks for duplication
  Position ptr,endA;//ptr is a loop ptr for A and endA is the end position of A
  for(int i=0;i<size;i++)//traverses arr
  {
    ptr=A->first();
    endA=A->end();
    flag=0;//0 at end of inner loop indicates arr[i] should be inserted
    while(ptr!=endA)
    {
      if(A->retrieve(ptr)==arr[i])//if arr[i] is already in *A
      {
        flag=1;
        break;
      }
      ptr=A->next(ptr);//Loop Update
    }
    if(flag==0)
    {
      A->insert(arr[i],endA);//arr[i] is inserted at *A's end
    }
  }
  return ;
}

int main() {
  
  List A, B, C;//A and B store input sets and C stores output list
  elementType *array1, *array2;//array1 and array2 are temp arrays for storing user input
  int M, N;//M, N - size of array1 and array2 respectively
  cin >> M >> N;
  //array1 and array2 are obtained from user
  array1=GetElements(M);
  array2=GetElements(N);
  //Lists A and B are created from array1 and array2 respectively
  CreateList(&A,array1,M);
  CreateList(&B,array2,N);
  //array1 and array2 are freed
  delete[] array1;
  delete[] array2;
  //stmts to find and print A U B
  C=(List)Union(A,B);
  C.quickSortList(1,C.end()-1);
  C.printList();
  //stmts to find and print A and B
  C=(List)Intersection(A,B);
  C.quickSortList(1,C.end()-1);
  C.printList();
  return 0;
}