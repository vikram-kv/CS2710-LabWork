#include "MyStack.h"

/* begin{Implementation of the class stack} */

ElemType stack::top() {

  if (tos < STACK_SIZE)
    return (stackArray[tos]);
  else
    return(0);
  }

int stack::empty() {

  if (tos >= STACK_SIZE)
   return 1;
  else
   return 0;
}

void stack::push(ElemType x) {

  tos--;
  stackArray[tos] = x;
}

ElemType stack::pop() {

  ElemType tmp;

  if (tos >= STACK_SIZE) 
    return (-1); 
  else {
    tmp = stackArray[tos];
    tos++;
    return (tmp);
  }
}

void stack::makeNull() {

  tos = STACK_SIZE;

}
/* end {Implementation of stack} */