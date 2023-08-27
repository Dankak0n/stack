#include <stdio.h>
#include "stack.h"

int main() {
	stack *s = new_stack();
	push(s, 0);
	push(s, 0);
	push(s, 0);
	clear(s);
	push(s, 2);
	push(s, 4);
	push(s, 1);
	pop(s);
	printf("%d\n%d", top(s), (int)size(s));
	destroy(s);
}
