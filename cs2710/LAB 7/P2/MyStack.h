#ifndef MY_STACK_H
#define MY_STACK_H

/*  The class stack defines an ADT stack.  */
/* begin {Definition of class stack} */


#define STACK_SIZE 1000
#define EXPR_LENGTH 1000
typedef  int ElemType;

class stack {
  ElemType stackArray[STACK_SIZE];        // A stack of characters
  int tos;              // A pointer to the top of stack.

public :
  ElemType top();               // returns the element on Top of the stack
  void push(ElemType x);      // Pushes an element on to the stack
  ElemType pop();             // Pops an element from the stack
  int empty();            // returns 1 if stack is Empty
  void makeNull();        // creates an Empty stack
 };
/* end{Definition of class stack} */
#endif