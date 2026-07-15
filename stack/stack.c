
#include "stack.h"
#include <stdio.h>

size_t pop(Stack* stack){

    if (is_empty(stack)){
        fprintf(stderr, "Stack Underflow\n");
        return 0;
    }

    // Last element is at -> count
    // Pop last element and set the last element to null
    // Remember to decrease count
    size_t last = stack->items[stack->count - 1];
    stack->count--;
    return last;
}

void append(Stack* stack, size_t element) {

    // Implement reallocation if stack is full
    if ((stack->count) >= stack->capacity){
        if (stack->capacity == 0){
            stack->capacity = STACK_DEFAULT_SIZE;
        }
        else {
            stack->capacity = 2 * stack->capacity;
            // Re allocate with sizeof(*(stack->items))
            // By dereferencing we get the actual size, not the size of the pointer
            // The size of a pointer is 8 bytes
            size_t* new_items = realloc(stack->items, stack->capacity * sizeof(*(stack->items)));
            if (new_items == NULL) {
                fprintf(stderr, "Fatal: Stack overflow (out of memory)\n");
                exit(1);
            }
            stack->items = new_items;
        }
    }
    stack->items[stack->count] = element;
    stack->count++;

}

Stack* create_stack(){

    // How to allocate stack memory?
    Stack *stack = malloc(sizeof(*stack));
    stack->capacity = STACK_DEFAULT_SIZE;
    stack->items = malloc(sizeof(size_t) * stack->capacity);
    stack->count = 0;
    return stack;

}

bool is_empty(Stack *stack) {

    // Stack is empty when it has zero elements
    if (stack->count == 0) {
        return true;
    }
    else {
        return false;
    }
}

void print_stack(Stack* stack) {

    printf("[");
    for(int idx = 0; idx < stack->count; idx++){
        printf(" %zu ", stack->items[idx]);
    }
    printf("]\n");

}

void clear_stack(Stack *stack){
    
    free(stack->items);
    stack->items = NULL;
    stack->capacity = 0;
    stack->count = 0;
}
