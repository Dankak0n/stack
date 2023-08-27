#include <stdlib.h>

typedef struct _node_t {
	int data;
	struct _node_t *prev;
}* _node_ptr;

typedef struct _stack_t {
	struct _node_t *_last;
	size_t _size;
}* _stack_ptr;

_stack_ptr new_stack(void) {
	_stack_ptr new_stack = (_stack_ptr)malloc(sizeof(struct _stack_t));
	new_stack->_last = NULL;
	new_stack->_size = 0;
	return new_stack;
}

int top(const _stack_ptr cur_stack) {
	return cur_stack->_last->data;
}

size_t size(const _stack_ptr cur_stack) {
	return cur_stack->_size;
}

int empty(const _stack_ptr cur_stack) {
	return cur_stack->_size == 0;
}

void push(const _stack_ptr cur_stack, int value) {
	cur_stack->_size++;
	_node_ptr new_node = (_node_ptr)malloc(sizeof(struct _node_t));
	new_node->data = value;
	new_node->prev = cur_stack->_last;
	cur_stack->_last = new_node;
}

void pop(const _stack_ptr cur_stack) {
	cur_stack->_size--;
	_node_ptr tmp = cur_stack->_last;
	cur_stack->_last = cur_stack->_last->prev;
	free(tmp);
}

void destroy(const _stack_ptr cur_stack) {
	while (!empty(cur_stack)) {
		pop(cur_stack);
	}
}

int clear(const _stack_ptr cur_stack) {
	if (empty(cur_stack)) {
		return 0;
	} else {
		destroy(cur_stack);
		return 1;
	}
}
