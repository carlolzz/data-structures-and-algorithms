#ifndef QUEUE_H
#define QUEUE_H
#define DEFAULT_QUEUE_CAPACITY 100

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct DeQueue {
    size_t count;
    size_t capacity;
    size_t* items;
} DeQueue;

// enqueue: adds a new element to the end of the queue
// deque: removes and returns the top element of the queue
// peek: returns the top element on the queue
// isEmpty: checks if the size is empty

void enqueue(DeQueue* q, size_t element);
// requires memmove
size_t dequeue(DeQueue* q);
size_t peek(DeQueue* q);
bool is_empty(DeQueue* q);
DeQueue* create_queue();
void print_queue(DeQueue* q);

#endif