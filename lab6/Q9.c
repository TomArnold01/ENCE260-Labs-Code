LinkedListElement_t* findElement(LinkedList_t* list, char data) {
    LinkedListElement_t *current = list->head;
    while (current) {
        if (current->data == data) return current;
        current = current->next;
    }
    return NULL;
}

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