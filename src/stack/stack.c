#include <stdio.h>
#include <stdlib.h>


#include <common/common.h>
#include <stack/stack.h>

void stack_init(Stack *stack, int maxSize){

	stack->data = malloc(maxSize * sizeof(int));
	stack->size = maxSize;
	stack->top = -1;
	logger_log(LOG_INFO, __FUNCSIG__, "Stack init successfully");

}

void push_element_in_stack(Stack* stack, int value) {
	if (stack->top < stack->size - 1) {
		stack->top++;
		stack->data[stack->top] = value;

		logger_log(LOG_INFO, __FUNCSIG__, "value successfully in");
		
	}
	else {
		logger_log(LOG_DEBUG, __FUNCSIG__, "Failure, stack is full");
	}
}

int pop_element_from_stack(Stack *stack, int *value) {
	if (stack->top >= 0) {
		*value = stack->data[stack->top];
		stack->top--;
		logger_log(LOG_INFO, __FUNCSIG__, "value successfully out");
		return *value;
	}
	else {
		logger_log(LOG_INFO, __FUNCSIG__, "Failure, stack is already empty");
		return 0;
	}
}