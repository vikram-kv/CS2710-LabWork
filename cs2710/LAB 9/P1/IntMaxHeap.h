#ifndef INT_MAX_HEAP
#define INT_MAX_HEAP
#include <iostream>
using namespace std;

/*  The class Heap defines an ADT Heap. */
/* begin{Definition of class Heap} */
#define HEAP_SIZE 1001
typedef int ElementType;
typedef int Position;
class Heap {
  ElementType priority[HEAP_SIZE];        // A Heap of integers
  Position last;
public:
  void insertHeap(ElementType x);       // Inserts an element on to the Heap
  ElementType deleteRoot();             // DeleteRoot of the Heap
  int empty();                   // returns 1 if Heap is empty
  void createHeap();             // creates an empty Heap
  void printHeap();               // Prints the heap
 };
/* end{Definition of class Heap} */

#endif