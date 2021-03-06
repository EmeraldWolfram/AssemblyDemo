#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/**
 * createLinkedList
 *	Calling the function will generate an empty Linked List and return it	
 *
 *	As the linked list created was empty, both head and tail point to NULL
 *
 * Words:
 *	1. newList		a new linked list object that is empty
 *
 *
 * createListElement
 *
 *	Calling the function will generate a ListElement's object and return it.
 *	ListElement type object contain:
 *		1. an integer
 *		2. a pointer to the next ListElement object
 *
 *	ListElement type object is basically a node that can extend to store more value
 *
 * Words:
 *	1. inValue		integer argument brought in to store in the listElement object
 *	2. newNode		new created node that store the "inValue"
 */

LinkedList stackList;

void initLinkedList(){
	stackList.head	= NULL;
	stackList.tail	= NULL;
	stackList.length= 0;
}



LinkedList* createLinkedList(){
	LinkedList* newList = malloc(sizeof(LinkedList));
	assert(newList != NULL);
  
	newList-> head	= NULL;
	newList-> tail	= NULL;
  newList->length = 0;
	
	return newList;
}

ListElement* createListElement(void* inValue){
	ListElement* newNode = malloc(sizeof(ListElement));
	assert(newNode != NULL);
  
	newNode->value = inValue;
	newNode->next = NULL;
  
	return newNode;
}

void addListLast(LinkedList* currentList, Tcb* currentNode){

  if(currentNode == NULL){
    currentList = currentList;
  }
  else{
    Tcb* tempNode = currentList->head;
		//check if the linked list empty. If empty, create a Node that the head point to
		if(currentList->head == NULL){
			currentList->head = currentNode;
		}
		//if the list is not empty, find the last node and add a node as new last node
		else{
			while(tempNode->next != NULL){
				tempNode = tempNode->next;
			}
			tempNode->next = currentNode;
		}
		//No matter what, the tail always point to last node
		currentList->tail = currentNode;
    currentList->length ++;
  }
}

void addListFirst(LinkedList* list, Tcb *elem){ 

  if(elem == NULL){
    elem = elem;
  }
  else{
    Tcb* prevHead = list->head;
    list->head = elem; //No matter what, the head always point to the new added Element
    
    if(list->length == 0){
      list->head->next = NULL;
      list->tail = elem;
    }
    else
      list->head->next = prevHead;
    
    (list->length)++;
  }
}

Tcb* listRemoveFirst(LinkedList* link){
  Tcb* removedElement;

  if(link->head == NULL){
    removedElement = NULL;
  }
  else{
    removedElement = link->head;
    if(link->head->next != NULL)
      link->head = link->head->next;
    else{
      link->head = NULL;
      link->tail = NULL;
    } 
    removedElement->next = NULL;
    link->length --;
  }
  return removedElement;
}

Tcb* listRemoveLast(LinkedList* link){
  Tcb* removedElement;
  Tcb* tempNode;
 
  if(link->head == NULL){
    removedElement = NULL;
  }
  else{
    tempNode  = link->head;
    removedElement = link->tail;
    if(tempNode->next != NULL){
      while(tempNode->next != link->tail){
        tempNode = tempNode->next;
      }
      link->tail = tempNode;
      tempNode->next = NULL;
    }
    else{
      link->head = NULL;
      link->tail = NULL;
    }
    removedElement->next = NULL;
    link->length --;
  }
  return removedElement;
}

Tcb* listFind(LinkedList* list, void* value, int(*compare)(void*,void*)){
  Tcb* tempElement;

  if(list == NULL){
    return NULL;
  }
  else if(list->head == NULL){
    return NULL;
  }
  else{
    tempElement = list->head;
    while(compare(&(tempElement->sp),value) != 0 && tempElement->next != NULL){
      tempElement = tempElement->next;
    }
    if(tempElement->next == NULL){
      return NULL;
    }
  }
  return tempElement;
}

int intCompare(void *first, void *second){
  if(*((int*)first) == *((int*)second)){
    return 0;
  }
  return 1;
}

int stringCompare(void *first, void *second){
  if(strcmp((char*)first,(char*)second) == 0){
    return 0;
  }
  return 1;
}