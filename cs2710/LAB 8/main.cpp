/************************
* $ID$
* File:   HashTableWithStringKey.cpp - Create a dynamically size-adjusting hash table with keys of string type and data as number of 
*                                      vowels/consonants and perform operations of insert,search and delete.
*
* Purpose: To create a and perform operations on dynamically growing/shrinking hashTable with string keys.
*
* Hssh Function - hash(key) = sum(position of letters of key in alphabet)%tableCapacity.
*         
* Author: K V VIKRAM
*
* Created: [2020-09-24 21:17] by vikram
*
* Last Modified: [2020-09-24 21:17] by vikram 
*
* Input Format:
*       Line 1 - Number of operations
*       Subsequent Lines - OpCode(int) + ' ' + key(string of lowercase letters(if OpCode!=4)
*       Here, OpCode is in [1..4] and 1 - Insert key, 2 - Find key,3 - Delete Node with key
*       and 4 - Print current size and capacity of hashTable
* Constraints:
*       All keys must be of lowercase only.
*       Valid Input Format must be follwed.
* Output Format:
*       For each line of input from line 2,
*       if opCode is 2, number of vowels and consonants at node with key is printed in a newline.
*       if opCode is 4, size and capacity of hashtable is printed.
*
* Compilation:  Compile and run with g++ HashTableWithStringKey.cpp -o soln, ./soln
*
* Bugs:     No major bugfixes or new releases
*************/

#include "HashTable.h"
ElementType assignValue();
void HashTableOperations(HashTable&,int);

/* Begin - main() */
int main()
{
    int noCmds;//number of commands from the user
    HashTable table;//instance of type HashTable
    table.makeHashTable();//initialization of table
    cin >> noCmds;
    HashTableOperations(table,noCmds);//HashTableOperations is called by reference to table and with noCmds
    table.deleteTable();
    return 0;
}
/* End - main() */

/*
    assignValue() - determines the number of consonants and vowels (both in lower case)
                    in the string key using the type for this purpose, ElementType.
    ARG - key(string)
    RETURNS - ElementType
*/
ElementType assignValue(string key)
{
    int vwlCount = 0,cnsntCount = 0;//vwlCount - no of vowels, cncsntCount - number of consonants
    for(char ch : key)//Loop over all characters in key
    {
        switch(ch)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vwlCount++;//ch is vwl
                break;
            default:
                cnsntCount++;//ch is cnsnt as key contains only lowercase vowels and consonants
                break;
        }
    }
    return ElementType{vwlCount,cnsntCount};
}

/*
    hashTableOperations - Perform noCmds number of operations on the hashTable aliased by table.
                          Operations with commandCode :
                          1) Insert key
                          2) Find key
                          3) Delete key
                          4) Print size and capacity
    ARG - table(HashTable&) , noCmds(int)
    RETURNS - nothing(void)
*/
void HashTableOperations(HashTable& table,int noCmds)
{
    int commandCode;//stores commandCode (valid - 1 to 4)
    string key;//stores the key in command (if any)
    ElementType nodeValue;//used for displaying return value in case of command 2 : Find Key
    for(int i=1;i<=noCmds;i++)
    {
        cin >> commandCode;
        switch(commandCode)
        {
            case 1:
                cin >> key;//key is read
                table.hashTableInsert(key,assignValue(key));//key with its value is inserted
                break;
            case 2:
                cin >> key;//key is read
                nodeValue=table.hashTableFind(key);//key(if present)'s value is returned
                if((nodeValue.retrieveCnstCount()+nodeValue.retrieveVwlCount())>0)//if legal value is in nodeValue
                    nodeValue.printElement();
                else
                    cout << "Not Found" << endl;
                break;
            case 3:
                cin >> key;//key is read
                table.hashTableDelete(key);//key (if present) is deleted
                break;
            case 4:
                table.printSizeAndCapacity();//size and capacity is printed
                break;
            default:
                break;
        }
    }
}