
#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdlib.h>

#define STACK_DEFAULT_SIZE 256

// Implemented as a dynamic array
typedef struct Stack {
    size_t count;
    size_t capacity;
    size_t* items;
} Stack;

// push: adds a new element to the stack
// pop: removes and returns the top element of the stack, requires memmove?
// isEmpty: checks if the size is empty

Stack* create_stack(void);
size_t pop(Stack* stack);
bool is_empty(Stack* stack);
void clear_stack(Stack* stack);
void print_stack(Stack* stack);
void append(Stack* stack, size_t element);

#endif
