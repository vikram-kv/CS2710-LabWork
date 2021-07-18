#ifndef LISTADTPTR_H
#define LISTADTPTR_H

#include <iostream>
#include "ElementType.h"

typedef struct CellType* Position;

typedef struct CellType 
{
    ElementType value;
    Position next;
} CellNode;

class List 
{
    public:
        void insert(ElementType val,  Position p);
        void delItem(Position p);
        void makeNull();
        void printList();
        ElementType retrieveValue(Position p);
        Position end();
        Position first();
        Position next(Position p);
    private:
        Position listHead;
};
List PolynomialSubtract(List, List);
List PolynomialAdd(List, List);
#endif
