#ifndef LIST_ADT_ARR_H
#define LIST_ADT_ARR_H

typedef int elementType;//Alias for int used as an element type
typedef int Position;//Alias for int used for indexing

/*
  Defines ADT List.
  Data members: Pointer to the first node of an array of type elementType - *list
                Position of the last node - lastNode
  Operations: All the common list operations along with
              Swap the elements at two positions
              Sort the list by Quick Sort technique
*/
/* begin {Definition of class List} */
class List {
public:
  void insert(elementType x, Position p);
  void delItem(Position p);
  void makeNull();
  void printList();
  Position end();
  Position first();
  Position next(Position p);
  elementType retrieve(Position p);
  void swap(Position i,Position j);
  void quickSortList(Position,Position);
private:
  Position partition(Position,Position);
  Position lastNode;
  elementType*  list;
};
/* end{Definition of class List} */
#endif
