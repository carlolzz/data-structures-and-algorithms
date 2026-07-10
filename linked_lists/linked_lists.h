#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H

#include <stdio.h>
#include <stddef.h> 

// 1. Properly named struct for self-referencing
typedef struct ListNode {
    size_t data;
    struct ListNode* next;
} ListNode;

// 2. Consistent use of 'ListNode' or 'struct ListNode'
void print_list(ListNode* head);
void free_list(ListNode* head);
ListNode* create_node(size_t data);
ListNode* create_list_from(size_t* values, size_t arr_len);
ListNode* add_to_list_at_beg(ListNode* head, size_t newData);
ListNode* add_to_list_at_end(ListNode* head, size_t newData);
ListNode* reverse_linked_list(ListNode* head);

#endif