#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct linkedlistelement_s {
    char data;
    struct linkedlistelement_s* next;
};
typedef struct linkedlistelement_s LinkedListElement_t;

typedef struct {
    LinkedListElement_t* head;
    LinkedListElement_t* tail;
} LinkedList_t;

void addElement(LinkedList_t* list, char data);
LinkedListElement_t* findElement(LinkedList_t* list, char data);
void deleteElement(LinkedList_t* list, LinkedListElement_t* element);

void addElement(LinkedList_t* list, char data) 
{
    LinkedListElement_t *newElement = malloc (sizeof (LinkedListElement_t));
    newElement->data = data;
    newElement->next = NULL;
    
    if (list->head == NULL) {
        list->head = list->tail = newElement;
    } else {
      
        list->tail->next = newElement;
        list->tail = newElement;
    }
}


LinkedListElement_t* findElement(LinkedList_t* list, char data) 
{
    LinkedListElement_t *current = list->head;
    while (current) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void deleteElement(LinkedList_t* list, LinkedListElement_t* element)
{
    if (list == NULL || list->head == NULL || element == NULL) {
    return;
  }
    if (list->head->data == element->data) {
    list->head = list->head->next;
    } else {
        LinkedListElement_t* curr = list->head->next;
        LinkedListElement_t* prev = list->head;
        while (curr != NULL && curr->data!=element->data) {
            prev = curr;
            element = element->next;
         }
        if (curr != NULL && curr->data == element->data) {
            prev->next = curr->next;
        }
    }    

}

int main(void) {
    
    
LinkedList_t alist = {.head = NULL, .tail = NULL};
LinkedListElement_t* element;
addElement(&alist, 'a');
addElement(&alist, 'b');
addElement(&alist, 'c');
element = findElement(&alist, 'b');
deleteElement(&alist, element);
for (LinkedListElement_t* elem=alist.head; elem != NULL; elem = elem->next) {
    printf("%c", elem->data);
}
//Clean up
while (alist.head != NULL) {
    deleteElement(&alist, alist.head);
}

}