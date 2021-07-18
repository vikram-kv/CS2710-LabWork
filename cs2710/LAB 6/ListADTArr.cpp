#include "ListADTArr.h"
using namespace std;


void List::makeNull() {
  list = new CellNode[10000]; 
  lastNode = 0;
}
void List::insert(ElementType val, Position p) {
  int i;
  for (i = lastNode+1; i > p; i--)
    list[i] = list[i-1];
  list[p].value = val;
  lastNode++;
}
void List::printList() {
  Position p;
  p = 1;
  if(lastNode == 0){
    cout<<"EMPTY LIST\n";
    return ;
  }
  while (p <= lastNode) {
    Print (list[p].value);
    p++;
  }
  cout << "\n";
}

Position List::end() {
  Position p;
  p = lastNode + 1;
  return(p);
}

Position List::first() {
  return(1);
}
Position List::next(Position p) {
  return (p+1);
}
ElementType List::retrieveValue(Position p) {
  return (list[p].value);
}

/*
    Function to Add two polynomials given by lists A , B and to return the resulting polynomial
    Arguments - Lists A and B
    Returns - List C
*/
List PolynomialAdd(List A, List B)
{
    List C;
    Position pos1,pos2;//pos1 and pos2 store current positions in A and B
    PolyNode pNode,pNode1,pNode2;//Three nodes of ElementType for storing the values in list A,
    // list B and list C respectively
    C.makeNull();//C is initialized
    //pos1 and pos2 are initialized
    pos1=A.first();
    pos2=B.first();
    while(pos1<A.end()&&pos2<B.end())//while both A and B are not fully scanned
    {
        pNode1=A.retrieveValue(pos1);//pNode1 is top node of A
        pNode2=B.retrieveValue(pos2);//pNode2 is top node of B
        if(pNode1.degree==pNode2.degree)//if the top nodes of A and B are addable
        {
            pNode.degree=pNode1.degree;
            pNode.coefficient=pNode1.coefficient+pNode2.coefficient;
            pos1=A.next(pos1);
            pos2=B.next(pos2);
        }
        else if(pNode1.degree>pNode2.degree)//in this case,pNode1 is inserted into C
        {
            pNode=pNode1;
            pos1=A.next(pos1);
        }
        else
        {   //in this case,pNode2 is inserted into C
            pNode=pNode2;
            pos2=B.next(pos2);
        }
        if(pNode.coefficient!=0)
            C.insert(pNode,C.end());
    }
    while(pos1<A.end())//If list A is not fully traversed
    {
        //Stmts to copy all nodes of A and insert them in C
        pNode1=A.retrieveValue(pos1);
        C.insert(pNode1,C.end());
        pos1=A.next(pos1);
    }
    while(pos2<B.end())//If list B is not fully traversed
    {
        //Stmts to copy all nodes of B and insert them in C.
        pNode2=B.retrieveValue(pos2);
        C.insert(pNode2,C.end());
        pos2=B.next(pos2);
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
    D.makeNull();
    Position pos1,pos2;//pos1 and pos2 store current positions in A and B
    PolyNode pNode,pNode1,pNode2;//Three nodes of ElementType for storing the values in list A,
    // list B and list D respectively
    D.makeNull();
    //D is initialized
    //pos1 and pos2 are initialized
    pos1=A.first();
    pos2=B.first();
    while(pos1<A.end()&&pos2<B.end())//while both A and B are not fully scanned
    {
        pNode1=A.retrieveValue(pos1);//pNode1 is top node of A
        pNode2=B.retrieveValue(pos2);//pNode2 is top node of B
        if(pNode1.degree==pNode2.degree)//if the top nodes of A and B are subtractable
        {
            pNode.degree=pNode1.degree;
            pNode.coefficient=pNode1.coefficient-pNode2.coefficient;
            pos1=A.next(pos1);
            pos2=B.next(pos2);
        }
        else if(pNode1.degree>pNode2.degree)//in this case,pNode1 is inserted into D
        {
            pNode=pNode1;
            pos1=A.next(pos1);
        }
        else
        {
            //in this case,pNode2 is inserted into D after switching sign
            pNode.degree=pNode2.degree;
            pNode.coefficient=-pNode2.coefficient;
            pos2=B.next(pos2);
        }
        if(pNode.coefficient!=0)//If pNode's coeffiecient is 0, then it is not inserted
            D.insert(pNode,D.end());
    }
    while(pos1<A.end())//If list A is not fully traversed
    {
        //stmts to copy all nodes of A, and insert them in D.
        pNode1=A.retrieveValue(pos1);
        D.insert(pNode1,D.end());
        pos1=A.next(pos1);
    }
    while(pos2<B.end())//If list B is not fully traversed
    {
        //stmts to copy all nodes from B, switch their signs and insert them in D.
        pNode2=B.retrieveValue(pos2);
        pNode.coefficient=-pNode2.coefficient;
        pNode.degree=pNode2.degree;
        D.insert(pNode,D.end());
        pos2=B.next(pos2);
    }
  	return D;
}