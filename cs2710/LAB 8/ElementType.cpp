#include "ElementType.h"

/* Begin - Implementation of class ElementType */

//Default Constructor - Initialises object's private members to 0
ElementType::ElementType()
{
    nVwl = 0;
    nCnsnt =0;
}

//Parametrised Constructor - Initialises object's nVwl with vwl
//and nCnsnt with cnsnt
//Useful for temporary instance creation
ElementType::ElementType(int vwl,int cnsnt)
{
    nVwl = vwl;
    nCnsnt = cnsnt;
}

/*
	retrieveVwlCount() - Returns number of vowels
	ARG - None
	RETURNS - int
*/
int ElementType::retrieveVwlCount()
{
    return nVwl;
}

/*
	retrieveCnstCount() - Returns number of consonants
	ARG - None
	RETURNS - int
*/
int ElementType::retrieveCnstCount()
{
    return nCnsnt;
}

/*
	retrieveCnstCount() - Prints number of vowels and consonants
	ARG - None
	RETURNS - Nothing
*/
void ElementType::printElement()
{
    cout << "Consonants: " << nCnsnt << " Vowels: " << nVwl << endl;
}

/* End - Implementation of class ElementType */