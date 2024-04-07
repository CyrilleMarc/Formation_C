#include <stdio.h>
#include <stdlib.h>

#include <common/common.h>
#include <stack/stack.h>

int main(int argc, char* argv[])
{
	logger_set_current_level(LOG_DEBUG);
	logger_log(LOG_DEBUG, __FUNCSIG__, argv[0]);

		Stack stack;
		int value = 0;
		stack_init(&stack,10);

		push_element_in_stack(&stack, 1);
		push_element_in_stack(&stack, 3);
		push_element_in_stack(&stack, 5);
		push_element_in_stack(&stack, 7);

		
		pop_element_from_stack(&stack, &value);
		printf("la valeur retournée est : %d", value);
		printf("\n");
		pop_element_from_stack(&stack, &value);
		printf("la valeur retournée est : %d", value);
}
