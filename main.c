#include <stdlib.h>
#include <stdio.h>

typedef struct __stack_t {
    int *elements, is_empty, back;
    size_t size, capacity;
} stack;

struct __stack_t* new_stack() {
    struct __stack_t *x = (struct __stack_t *)malloc(sizeof(struct __stack_t));
    x->elements = NULL;
    x->size = 0;
    x->capacity = 0;
    x->is_empty = 1;
    return x;
}

void clear(struct __stack_t *cur_stack) {
    cur_stack->elements = realloc(cur_stack->elements, 0);
    cur_stack->size = 0;
    cur_stack->capacity = 0;
    cur_stack->is_empty = 1;
}

void destroy_stack(struct __stack_t ** cur_stack) {
    free((*cur_stack)->elements);
    free(*cur_stack);
}

void push(struct __stack_t *cur_stack, size_t value) {
    if (cur_stack->capacity == cur_stack->size) {
        if (cur_stack->capacity) {
            cur_stack->capacity *= 2;
        } else {
            cur_stack->capacity++;
        }
        cur_stack->elements = realloc(cur_stack->elements, cur_stack->capacity * sizeof(int));
    }
    cur_stack->elements[cur_stack->size] = value;
    cur_stack->size++;
    cur_stack->is_empty = 0;
    cur_stack->back = value;
}

void pop(struct __stack_t *cur_stack) {
    if (cur_stack->size == 0) {
        return;
    }
    cur_stack->size--;
    if ((cur_stack->size << 2) <= cur_stack->capacity) {
        cur_stack->capacity = cur_stack->size;
        cur_stack->elements = realloc(cur_stack->elements, cur_stack->capacity * sizeof(int));
    }
    if (!cur_stack->size) {
        cur_stack->is_empty = 1;
    } else {
        cur_stack->back = cur_stack->elements[cur_stack->size - 1];
    }
}

int main() {
    stack *s = new_stack();
    push(s, 10);
    clear(s);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    pop(s);
    printf("%d %d\n", s->back, s->is_empty);
    pop(s);
    printf("%d %d\n", s->back, s->is_empty);
    pop(s);
    printf("%d\n", s->is_empty);
    destroy_stack(&s);
}
