#pragma once
#include <stdlib.h>

typedef struct _stack_t stack;
typedef struct _stack_t* _stack_ptr;
typedef struct _node_t*  _node_ptr;

_stack_ptr new_stack(void);
void destroy(const _stack_ptr cur_stack);
void clear(const _stack_ptr cur_stack);

size_t size(const _stack_ptr cur_stack);
int empty(const _stack_ptr cur_stack);

int top(const _stack_ptr cur_stack);
void push(const _stack_ptr cur_stack, int value);
void pop(const _stack_ptr cur_stack);
