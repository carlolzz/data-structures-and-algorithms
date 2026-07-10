
#include "queue.h"

DeQueue* create_queue(){

    DeQueue* q = malloc(sizeof(*q));
    q->capacity = 0;
    q->items = malloc(sizeof(size_t) * q->capacity);
    q->count = 0;
    return q;

}

void enqueue(DeQueue* q, size_t element){

    if((q->count) >= q->capacity) {
        if(q->capacity == 0) {
            q->capacity = DEFAULT_QUEUE_CAPACITY;
        }
        else {
            // Reallocate memory, double capacity
            q->capacity = 2 * q->capacity;
            size_t* new_items = realloc(q->items, q->capacity * sizeof(*(q->items)));
            if (new_items == NULL) {
                fprintf(stderr, "Fatal: Memory overflow\n");
                exit(EXIT_FAILURE);
            }
            q->items = new_items;
        }
        
    }
    q->items[q->count] = element;
    q->count++;

}

size_t dequeue(DeQueue* q){

    if(q->count == 0) {
        fprintf(stderr, "Error, cannot dequeue from an empty queue");
        return 0;
    }

    // Get the first element
    size_t top = q->items[0];

    if(q->count > 1) {
        // Shift elements to the left
        memmove(&q->items[0], q->items[1], (sizeof(size_t) * (q)->count - 1));
    }
    
    q->count--;

    return top;

}

size_t peek(DeQueue* q){

    if(q->count == 0) {
        fprintf(stderr, "Error, cannot peek from an empty queue\n");
        return 0;
    }

    size_t top = q->items[0];
    return top;
}

void print_queue(DeQueue* q) {

    printf("[");
    for(int idx = 0; idx < q->count; idx++){
        printf(" %zu ", q->items[idx]);
    }
    printf("]\n");

}


bool is_empty(DeQueue* q){
    if (q->count == 0) return true;
    else return false;
}
