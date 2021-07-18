#include "ListADTPtr.h"
using namespace std;
void List::makeNull() 
{
    listHead = new CellNode;
    listHead->next = NULL;
}

void List::insert(ElementType val,  Position p) {
  Position temp;
  temp = p->next;
  p->next = new CellType;
  p->next->next  = temp;
  p->next->value = val;
  
}

ElementType List::retrieveValue(Position p) {
  return(p->next->value);  
}

void List::printList() 
{
    Position p;
    p = listHead->next;
    
    if(p == NULL)
        cout<<"EMPTY LIST\n";
    else
    {
        while (p != NULL)
        {
            Print(p->value);
            p = p->next;
        }
        cout << endl;
    }
    
 }

Position List::end() 
{
    Position p;
    p = listHead;
    while (p->next != NULL)
        p = p->next;
    return(p);
}

Position List::first() 
{
    return(listHead);
}

Position List::next(Position p) 
{
    return (p->next);
}

/*
    Function to Add two polynomials given by lists A , B and to return the resulting polynomial
    Arguments - Lists A and B
    Returns - List C
*/
List PolynomialAdd(List A, List B)
{
    List C;
    Position ptr1,ptr2,ptr;//ptr1 is ptr to list A, ptr2 is ptr to list B and ptr is ptr to list C
    Position lptr1,lptr2;//lptr1 is ptr to last node of list A and lptr2 is pointer to last node of list B
    PolyNode pNode1,pNode2,pNode;//Three nodes of ElementType for storing the values in list A,
    // list B and list C respectively
    C.makeNull();//C is initialized
    //prt , ptr1 ,ptr2, lptr1 and lptr2  are initialized
    ptr1=A.first();
    ptr2=B.first();
    ptr=C.first();
    lptr1=A.end();
    lptr2=B.end();
    while(ptr1!=lptr1&&ptr2!=lptr2)//while both A and B are not fully scanned
    {
      pNode1=(ElementType) A.retrieveValue(ptr1);//pNode1 is top node of A
      pNode2=(ElementType) B.retrieveValue(ptr2);//pNode2 is top node of B
      if(pNode1.degree==pNode2.degree)//if the top nodes of A and B are addable
      {
        pNode.coefficient=(pNode1.coefficient+pNode2.coefficient);
        pNode.degree=pNode1.degree;
        ptr1=A.next(ptr1);
        ptr2=B.next(ptr2);
      }
      else if(pNode1.degree>pNode2.degree)//in this case,pNode1 is inserted into C
      {
        pNode=pNode1;
        ptr1=A.next(ptr1);
      }
      else//in this case,pNode2 is inserted into C
      {
        pNode=pNode2;
        ptr2=B.next(ptr2); 
      }
      if(pNode.coefficient!=0)//If pNode's coeffiecient is 0, then it is not inserted
      {
        C.insert(pNode,ptr);
        ptr=C.next(ptr);
      }
    }
    while(ptr1!=lptr1)//If list A is not fully traversed
    {
      //Stmts to copy all nodes of A and insert them in C
      pNode1=(ElementType) A.retrieveValue(ptr1);
      pNode=pNode1;
      ptr1=A.next(ptr1);
      C.insert(pNode,ptr);
      ptr=C.next(ptr);
    }
    while(ptr2!=lptr2)//If list B is not fully traversed
    {
      //Stmts to copy all nodes of B and insert them in C.
      pNode2=(ElementType) B.retrieveValue(ptr2);
      pNode=pNode2;
      ptr2=B.next(ptr2);
      C.insert(pNode,ptr);
      ptr=C.next(ptr); 
    }
      return C;
}
/*
    Function to subtract two polynomials given by lists A , B and to return the resulting polynomial
    Arguments - Lists A and B
    Returns - List D
*/
List PolynomialSubtract(List A, List B)
{
    List D;
    Position ptr1,ptr2,ptr;//ptr1 is ptr to list A, ptr2 is ptr to list B and ptr is ptr to list D
    Position lptr1,lptr2;//lptr1 is ptr to last node of list A and lptr2 is pointer to last node of list B
    PolyNode pNode1,pNode2,pNode;//Three nodes of ElementType for storing the values in list A,
    // list B and list D respectively
    D.makeNull();//D is initialized
    //prt , ptr1 ,ptr2, lptr1 and lptr2  are initialized
    ptr1=A.first();
    ptr2=B.first();
    ptr=D.first();
    lptr1=A.end();
    lptr2=B.end();
    while(ptr1!=lptr1&&ptr2!=lptr2)//while both A and B are not fully scanned
    {
      pNode1=(ElementType) A.retrieveValue(ptr1);//pNode1 is top node of A
      pNode2=(ElementType) B.retrieveValue(ptr2);//pNode2 is top node of B
      if(pNode1.degree==pNode2.degree)//if the top nodes of A and B are subtractable
      {
        pNode.coefficient=(pNode1.coefficient-pNode2.coefficient);
        pNode.degree=pNode1.degree;
        ptr1=A.next(ptr1);
        ptr2=B.next(ptr2);
      }
      else if(pNode1.degree>pNode2.degree)//in this case,pNode1 is inserted into D
      {
        pNode=pNode1;
        ptr1=A.next(ptr1);
      }
      else
      { //in this case,pNode2 is inserted into D after switching sign
        pNode.degree=pNode2.degree;
        pNode.coefficient=-pNode2.coefficient;
        ptr2=B.next(ptr2); 
      }
      if(pNode.coefficient!=0)//If pNode's coeffiecient is 0, then it is not inserted
      { 
        D.insert(pNode,ptr);
        ptr=D.next(ptr);
      }
    }
    while(ptr1!=lptr1)//If list A is not fully traversed
    {
      //stmts to copy all nodes of A, and insert them in D.
      pNode1=(ElementType) A.retrieveValue(ptr1);
      pNode=pNode1;
      ptr1=A.next(ptr1);
      D.insert(pNode,ptr);
      ptr=D.next(ptr);
    }
    while(ptr2!=lptr2)//If list B is not fully traversed
    {
      //stmts to copy all nodes from B, switch their signs and insert them in D.
      pNode2=(ElementType) B.retrieveValue(ptr2);
      pNode.degree=pNode2.degree;
      pNode.coefficient=-pNode2.coefficient;
      ptr2=B.next(ptr2);
      D.insert(pNode,ptr);
      ptr=D.next(ptr); 
    }
      return D;
}