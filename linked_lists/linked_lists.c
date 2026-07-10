
#include <stdlib.h>
#include "linked_lists.h"

void print_list(ListNode* node) {       
    while (node != NULL) {
        printf("[%zu]->", node->data);
        node = node->next;
    }   
    printf("NULL\n\n");
    return;
}

void free_list(ListNode* head) {
    while(head) {
        // Save the current list element as temp
        ListNode* tmp = head;
        head = head->next;
        free(tmp);
    }
}

ListNode* create_node(size_t data) {

    // malloc(sizeof(*newNode)) (Dereferencing the variable)
    // -- or malloc(sizeof(ListNode))    

    ListNode* newNode = malloc(sizeof(*newNode));
    if (!newNode) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    // Initialize the fields so the node is "ready to use"
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

ListNode* create_list_from(size_t* values, size_t arr_len) {

    if (values == NULL || arr_len == 0) {
        fprintf(stderr, "Error, cannot create a linked list from an array of empty values.\n");
        return NULL;
    }

    struct ListNode* head = createNode(values[0]);  
    struct ListNode* current = head;

    for(size_t idx = 1; idx < arr_len; idx++) {
        current->next = createNode(values[idx]);
        current = current->next;
    }

    return head;

}

// Add an element to the beginning of a linked list.
ListNode* add_to_list_at_beg(ListNode* head, size_t newData){

    ListNode* newNode = createNode(newData);
    newNode->next = head;
    return newNode;

}

// Add an element to the end of the list; for this we have to traverse it.
ListNode* add_to_list_at_end(ListNode* head, size_t newData) {

    ListNode* newNode = createNode(newData);

    if (head == NULL) {
        return newNode;
    }

    struct ListNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;

}

ListNode* reverse_linked_list(ListNode* head){

    ListNode* prev = NULL;
    
    while (head != NULL) {
        ListNode* nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }

    return prev;

}
