
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



void addElement(LinkedList_t* list, char data) {
    LinkedListElement_t *newElement = malloc (sizeof (LinkedListElement_t));
    newElement->data = data;
    newElement->next = NULL;
    
    if (list->head == NULL) {
        list->head = list->tail = newElement;
    }
    else {
        newElement->next = list->head;
        list->head = newElement;
    }
}

#endif