#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#define DELETED "D" // Macro for key for a previously occupied but presently unoccupied hash node. Vital in efficient search
#include "HashNode.h"
typedef int Position;

/*
Implements an ADT HashTable with open addressing for collision resolution
Linear Probing is the collision Resolution strategy
Data Members:
	Private - hashTable is a pointer to pointer to first HashNode
			  capacity is the number of pointers in hashTable array
			  size is the number of used locations in hashTable array
Member Functions:
	Private - hash - The Hash function(Normal form - hash(string,int)) which hashes a string based upon table capacity
					 to a index in table. Overloaded form(hash(string)) is where table capacity is this->capacity.
	Public - makeHashTable - Initialises an object with capacity as 2
			 hashTableResize - Resizes hashTable if size goes above or below a threshold
			 hashTableInsert - Inserts key(string) with value(ElementType) if it is not already present
			 hashTableDelete - Deletes a node with key(string) from hashTable
			 hashTableFind - Finds whether a node with key(string) is present in hashTable or not. Returns its value if found
			 printSizeAndCapacity - Prints the size and capacity of the hashTable
			 deleteTable - Free all dynamic memory allocated
*/

/* Begin - Definition of HashTable */

class HashTable 
{
    public:
        void makeHashTable(int initialSize = 2);
        void hashTableResize(int);
        void hashTableInsert(string, ElementType);
        ElementType hashTableDelete(string);
        ElementType hashTableFind(string);
        void printSizeAndCapacity();
        void deleteTable();  
    private:
        Position hash(string,int);
        Position hash(string);
        HashNode** hashTable; 
        int capacity;
        int size;
};

/* End - Definition of HashTable */

#endif
