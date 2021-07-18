#include "ListADTArr.h"
using namespace std;

int main() {
     
  	List A, B, C, D;
    int lSize1,lSize2;//sizes of list A and B respectively
    int count;//loop variable
    PolyNode newNode;
    //A and B are initialized
    A.makeNull();
    B.makeNull();
    cin >> lSize1 >> lSize2;
    count=0;
    while(count<lSize1)//Loop to read List A
    {
        cin >> newNode.coefficient >> newNode.degree;
        A.insert(newNode,A.end());
        count++;
    }
    count=0;
    while(count<lSize2)//Loop to read List B
    {
        cin >> newNode.coefficient >> newNode.degree;
        B.insert(newNode,B.end());
        count++;
    }
  	C = (List) PolynomialAdd (A, B);
    C.printList();
  	D = (List) PolynomialSubtract (A, B);
    D.printList();
    return 0;
}