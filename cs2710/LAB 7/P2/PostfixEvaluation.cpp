/************************
* $ID$
* File:  PostfixEvaluation.cpp - Evaluate Postfix expressions on integers by using
*        ADT stack defined in MyStack.h
*
* Purpose: Evaluate and print the result of a postfix expression on positive integers with 
*          operations +,-,*,/.
*          
* Author: K V VIKRAM
*
* Created: [2020-09-16 16:02] by vikram
*
* Last Modified: [2020-09-17 12:31] by vikram 
*
* Input Format:
*      Line 1: Number(N) of elements in the postfix expression(both operands and operators)
*      Line 2: Postfix expression with elements separated by space
* Constraints:
*      1 <= N <= 1000
*      0 < operand <=10^5
* Output Format:
*      Line 1: Input Postfix expression with elements separated by space
*      Line 2: The Result is :(result of evaluation)
*
* Compilation:  Compile and run with g++ PostfixEvaluation.cpp MyStack.cpp MyStack.h -o soln, ./soln
*
* Bugs:     No major bugfixes or new releases
*************/
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "MyStack.h"
using namespace std;

/* Function to perform Postfix Expression Evaluation using stack ADT
   Arguments - an array of strings which have operators or operands in postfix 
               form - char** postFixExpr, exprLength - number of elements in expression
   Returns - the result of evaluation of postFixExpr
*/
int EvaluatePostFix(char **postFixExpr, int exprLength) {
   int result;// result of expression evaluation
   int value;//used for storing integer value read from a string
   stack opndStack;// a stack of operands for evaluation
   int opnd1,opnd2;// opnd1 and opnd2 store operands popped from opndStack.
   int opnResult;// opnResult stores result of operation on opnd1 and opnd2
   int index=0;//loop variable
   opndStack.makeNull();// opndStack is initialized
   while(index<exprLength)//Loop for expr evaluation
   {
    if(postFixExpr[index][0]>='0'&&postFixExpr[index][0]<='9')//if postFixExpr[index] is an operand
    {
      sscanf(postFixExpr[index],"%d",&value);//value stores the operand
      opndStack.push(value);//value is pushed into the opndstack
    }
    else
    {//if postFixExpr[index] is an operator
      //opnd1 and opnd2 are popped from opndStack
      opnd1=opndStack.pop();
      opnd2=opndStack.pop();
      switch(postFixExpr[index][0])//opnResult stores the result of opnd2 'postFixExpr[index][0]' opnd1
      {
        case '+':
          opnResult=opnd2+opnd1;
          break;
        case '-':
          opnResult=opnd2-opnd1;
          break;
        case '*':
          opnResult=opnd2*opnd1;
          break;
        case '/':
          opnResult=opnd2/opnd1;
          break;
        default://invalid case
          exit(-1);
          break;    
      }
      opndStack.push(opnResult);//opnResult is pushed into the opndStack
    }
    index++;//loop update
   }
   result=opndStack.pop();//The only remaining element in opndStack is the result
   return result;//result is returned
}


int main() {
  char **postFixExpr;//points to an array of strings which store operands and operators
  int  n;//no of elements in input
  int  i;//loop variable
  cin >> n;//n is obtained
  postFixExpr=new char*[n];// n pointers of type char* are created to hold n strings
  i=0;
  while(i<n)
  {
    postFixExpr[i]=new char[8];//max length of element is 7 corr. to 100000\0. 1 extra char for safety
    cin >> postFixExpr[i];//element i is obtained
    i++;  
  }
  i=0;
  while(i<n)//Loop to print the postfix expression inputted
  {
      cout << postFixExpr[i] << ' ';
      i++;
  }
  int value = (int) EvaluatePostFix(postFixExpr, n);//value = result of expression evaluation
  cout << "\nThe Result is :" << value << endl;//The result is printed
  i=0;
  while(i<n)//Loop to free the space used for storing strings
  {
    delete[] postFixExpr[i];
    i++;  
  }
  delete[] postFixExpr;//frees the array of n char* pointers
  return 0;
}