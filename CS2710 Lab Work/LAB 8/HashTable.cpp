#include "HashTable.h"

/* Begin - Implementation of class HashTable */

/*
	Technique for searching:
		Let searchKey be the key we want to search for in hashTable. Let hashVal = hash(searchKey).
		This code replaces a deleted HashNode with a dummy with illegal values key="D" and value=ElementType(0,-1).
		Since the collision resolution strategy is linear probing, any new node will be assigned to the first free(NULL or DUMMY NODE)
		location at or beyond hashVal with circling back if we go beyond last index. So, when a search is performed,
		We only look from hashVal to the index of the first NULL node for the searchKey. We note that hashTable[i] is NULL iff it 
		did not point to any node after the last resize() or makeHashTable() operation.We note that search does not terminate at a DUMMY NODE,
		as it is possible that DUMMY Node was occupied when searchKey was inserted so that that location was skipped over.
*/

/*
	hash(string,int) - hashes the key based on tabSize and returns hash value.
	Hash Function - hash value = sum(char ch:key) mod tabSize
	ARG - key(String) , tabSize(int)
	RETURNS - hash value (Position)
*/
Position HashTable::hash(string key,int tabSize)
{
    int sum = 0;
    for(char ch : key)
    {
        sum += (int)ch - 96;
    }
    return (sum%tabSize);
}

/*
	hash(string) - Overloaded Function. Uses hash(string,int) with key = key and tabSize = this->capacity
	ARG - key(string)
	RETURNS - hash value(Position)
*/
Position HashTable::hash(string key)
{
    return hash(key,capacity);
}

/*
	makeHashTable - Initialises hashTable with capacity = initialSize (default - 2)
					All locations in hashTable are initialized to NULL
					size = 0 (no hash nodes)
	ARG - initialSize(int)
	RETURNS - nothing(void)
*/
void HashTable::makeHashTable(int initialSize)
{
    hashTable = new HashNode*[initialSize];
    for(int i=0;i<initialSize;i++)
    {
        hashTable[i] = NULL;
    }
    size = 0;
    capacity = initialSize;
}

/*
	hashTableResize - Resizes a HashTable by creating an array HashNode Pointers of size newSize. Existing hash nodes are rehashed
					  in the new array and assigned to their new pointer. Deleted Node (key ="D" (illegal))
					  are not rehashed. After rehashing, hashTable is assigned its new value and capacity is
					  updated to newSize
	ARG - newSize(int)
	RETURNS - nothing(void)
*/
void HashTable::hashTableResize(int newSize)
{
    HashNode** newTable;//pointer to array of HashNode pointers
    HashNode* curNode;//loop pointer
    Position hashVal,pos;//store hash value and current position in loop respectively
    //Allocation and initialization of elements of newTable
    newTable = new HashNode*[newSize];
    for(int i=0;i<newSize;i++)
        newTable[i] = NULL;
    //Loop for traversing old hash table and performs move operations if a valid hash node is
    //found
    for(int i=0;i<capacity;i++)
    {
        curNode = hashTable[i];
        if(curNode!=NULL && curNode->retrieveKey()!=DELETED)//if the current node has valid data now(Deleted Nodes are not valid)
        {
            hashVal = hash(curNode->retrieveKey(),newSize);
            pos = hashVal;
            while(newTable[pos]!=NULL)//Loop to find correct position for *curNode 
            {
                pos++;
                if(pos>=newSize)//circles back if end is reached
                {
                    pos=0;
                }
            }
            newTable[pos] = curNode;//*curNode is placed in its position
        }
        else
        {
            delete curNode;//if curNode is not pointing a valid node(NULL or DELETED)
        }
    }
    delete[] hashTable;//old hashTable is deleted
    hashTable = newTable;//new hashTable is assigned to hashTable
    capacity = newSize;//capacity is updated
}

/*
	hashTableInsert - Inserts HashNode with key = newKey and value = newVal into the table
					  Insertion is done only after a search is made to find whether key is already
					  present in hashTable.Resizing is done when the size of the updated hashTable strictly
					  exceeds capacity/2.The first segment of the code where a search is performed may be done
					  with hashTableFind() but this unnecessarily leads to extra function calls.
	ARG - newKey(string) , newVal(ElementType)
	RETURNS - nothing (void)
*/
void HashTable::hashTableInsert(string newKey,ElementType newVal)
{
    Position hashVal,pos;//hashVal stores hash value of new Key. pos is loop variable
    string curKey;//stores the key at pos of hashTable in loop
    bool found = false;//found is true if newKey already exists in hashTable
    hashVal = hash(newKey);
    pos = hashVal;
    while(hashTable[pos]!=NULL)//Loop till the first NULL location is found
    {
        curKey = hashTable[pos]->retrieveKey();
        if(curKey == newKey)// if current key is newKey, node already exists
        {
            found = true;
            break;
        }
        pos++;
        if(pos>=capacity)//Circles back when end is reached
        {
            pos = 0;
        }
    }
    if(found == false)//if newKey is not present in hashTable
    {
        pos = hashVal;
        while(hashTable[pos]!=NULL&&hashTable[pos]->retrieveKey()!=DELETED)//loop till a free(NULL or loc with dummy node) is found
        {
            pos++;
            if(pos>=capacity)//Circles back when end is reached
                pos=0;
        }
        if(hashTable[pos] == NULL)//if first free loc at or beyond hashVal is unused(NULL)
            hashTable[pos] = new HashNode(newKey,newVal);
        else //if first free loc at or beyond hashVal points to dummy node
            *hashTable[pos] = HashNode(newKey,newVal);
        size++;//size update
        if(2*size>capacity)//Resizes when size strictly exceeds capacity/2
            hashTableResize(capacity*2);
    }
}

/*
	hashTableFind - Searches for and returns the value at node whose key is searchKey.
					If node with searchKey is not found, dummy value = ElementType{0,0}
					is returned.
	ARG - searchKey
	RETURNS - value at node whose key is searchKey or dummy value (ElementType)
*/
ElementType HashTable::hashTableFind(string searchKey)
{
    Position hashVal,pos;//hashVal stores hash value of new Key. pos is loop variable
    ElementType returnVal;//stores return value of the function,initialized with default constructor
    hashVal=hash(searchKey);// hash value of searchKey is found
    pos = hashVal;
    while(hashTable[pos] != NULL)//loop till the first unused(NULL) position in hashTable[] is found
    {
        if(hashTable[pos]->retrieveKey() == searchKey)//if searchKey is at hashTable[pos]
            break;
        pos++;
        if(pos>=capacity)//circle back after end is reached
            pos=0;
    }
    if(hashTable[pos]!=NULL)//if the loop terminated because searchKey was found
        returnVal = hashTable[pos]->retrieveValue();
    return returnVal;
}
/*
	hashTableDelete - Searches for and if found, deletes the node with key = delKey.
					  Here, deletion is same as getting replaced with a dummy. If a deletion is 
					  done, value at the deleted node is returned.Else, ElementType{0,0} is returned.
	ARG - delKey(string)
	Returns - value at node with delKey or dummy value (ElementType)
*/
ElementType HashTable::hashTableDelete(string delKey)
{
    Position hashVal,pos;//hashVal stores hash value of new Key. pos is loop variable
    ElementType returnVal;//stores return value of the function,initialized with default constructor
    hashVal=hash(delKey);// hash value of delKey is found
    pos=hashVal;
    while(hashTable[pos]!=NULL)//loop till the first unused(NULL) position in hashTable[] is found
    {
        if(hashTable[pos]->retrieveKey() == delKey)//if delKey is at hashTable[pos]
        {
            returnVal = hashTable[pos]->retrieveValue();
            *hashTable[pos] = HashNode(DELETED,ElementType(0,-1));//Illegal key = "D" and value =ElementType{0,-1} is placed at hashTable[pos]
            size--;//size update
        }
        pos++;
        if(pos>=capacity)//circle back after end is reached
            pos=0;
    }
    if(4*size < capacity)//resize to capacity/2 if size goes strictly less than capacity/4
        hashTableResize(capacity/2);
    return returnVal;
}

//Prints the size and capacity of the HashTable
void HashTable::printSizeAndCapacity()
{
    cout << "size =" << size << " capacity =" << capacity << endl;
}

//Free all dynamic memory allocated
void HashTable::deleteTable()
{
	for(int i=0;i<capacity;i++)
		delete hashTable[i];
	delete[] hashTable;
}
/* End - Implementation of HashTable */