#pragma once

typedef struct {
	int *data;
	int size;
	int top;
} Stack;


void stack_init(Stack* stack, int maxSize);
void push_element_in_stack(Stack* stack, int value);
int pop_element_from_stack(Stack* stack, int *value);