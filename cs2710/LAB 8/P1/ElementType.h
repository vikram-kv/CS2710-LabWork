#ifndef ELEMENT_TYPE_H
#define ELEMENT_TYPE_H

#include <iostream>
using namespace std;

/* 
Defines a class ElementType
Private Data members - nVwl: Number of vowels , nCnsnt - Number of consonants
Constructors - Default constructor , Parametrised constructor
Public members - retrieveVwlCount - returns nVwl , retrieveCnstCount - returns nCnsnt
                 and printElement - prints the object contents
*/

/* Begin - Definition of class ElementType */

class ElementType
{
    int nVwl;
    int nCnsnt;
public:
    ElementType();
    ElementType(int,int);
    int retrieveVwlCount();
    int retrieveCnstCount();
    void printElement();
};

/* End - Definition of class ElementType */

#endif