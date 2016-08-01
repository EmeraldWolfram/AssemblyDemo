#ifndef LinkedList_H
#define LinkedList_H

#include "TCB.h"
/**
 * LinkedList
 *	
 *	Object of LinkedList's type contain:
 *		1. head
 *		2. tail
 *	where the head always point to the first node of the linked list and
 *	the tail always point to the last node of the linked list
 *
 *	Both head and tail are ListElement object that point to another ListElement
 *	object but head and tail does not store value.
 *
 *	If the linked list is empty, both head and tail point to NULL
 *
 * 
 * ListElement
 *
 *	ListElement type object contain:
 *		1. an integer
 *		2. a pointer pointing to the next ListElement object
 *	
 *	ListElement type object is basically a node that can extend to
 *	to store more value when needed.
 *
 *	It extend by pointing to another ListElement object.
 *	If no more node behind, the pointer point to NULL
 *
 */
typedef struct ListElement_t ListElement;
struct ListElement_t{
	void* value;
	ListElement* next;
};

typedef struct{
	Tcb* head;
	Tcb* tail;
  int length;
}LinkedList;

extern LinkedList	stackList;

void initLinkedList();

ListElement* createListElement(void* value);
LinkedList* createLinkedList();

void addListLast(LinkedList* currentList, Tcb* currentNode);
void addListFirst(LinkedList* stack, Tcb *elem);

Tcb* listRemoveFirst(LinkedList* link);
Tcb* listRemoveLast(LinkedList* link);

Tcb* listFind(LinkedList* list, void* value, int(*compare)(void*,void*));
int intCompare(void *first, void *second);
int stringCompare(void *first, void *second);

#endif // LinkedList_H
