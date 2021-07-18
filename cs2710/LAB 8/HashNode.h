#ifndef HASH_NODE_H
#define HASH_NODE_H
#include <string>
#include "ElementType.h"
/*
Defines a class HashNode which is the type of a single node
in the ADT HashTable
Data Members:
	private - key - Unique key which used to hash the node to an appropriate position in the hashtable
			  value - Data of HashNode
Member Functions:
	Constructors - 1 Default and 1 Parametrised
	Accessors - retrieveKey() and retrieveValue()
*/

/* Begin - Definition of class HashNode */

class HashNode
{
    string key;
    ElementType value;
public:
    HashNode() : key{""}, value{} {} // default value of key and value are "" and ElementType{}
    HashNode(string str,ElementType elem) : key{str}, value{elem} {} // initialises key with str and value with elem
    string retrieveKey(); //returns key
    ElementType retrieveValue();//returns value
};

/* End - Definition of class HashNode */

#endif