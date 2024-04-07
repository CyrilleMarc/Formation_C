#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <common/common.h>

int main()
{
	return 0;
}

//****************** CHAPTER 1 - ARRAY TO SORT**************************************

/*
void init_array_to_malloc_random_i(int** array_to_sort, int array_element_count, int maxValue);
void array_to_sort_i(int* array_to_sort, int array_element_count);
int check_array_is_sorted(int* array_to_sort, int array_element_count);

int main(int argc, char* argv[])
{
	logger_set_current_level(LOG_INFO);
	logger_log(LOG_DEBUG, __FUNCSIG__, argv[0]);

	int maxValue = 256;
	int* array_to_sort = NULL;
	int array_element_count = 128;

	printf("**************TABLEAU NON TRIE***************\n");
	printf("\n");

	init_array_to_malloc_random_i(&array_to_sort, array_element_count, maxValue );
		for (int i = 0; i < array_element_count; ++i) {
		printf("%d ", array_to_sort[i]);
	}
		printf("\n");
		printf("**************TABLEAU TRIE***************\n");
		printf("\n");

		array_to_sort_i(array_to_sort, array_element_count);
		for (int i = 0; i < array_element_count; ++i) {
			printf("%d ", array_to_sort[i]);
		}
		printf("\n");
		printf("*************VERIFICATION TABLEAU TRIE****************\n");
		printf("\n");

		if (0 != check_array_is_sorted(array_to_sort, array_element_count)) {
			logger_log(LOG_INFO, __FUNCSIG__, "Array is successfully sorted");
			return 0;
		}
		else
		{
			logger_log(LOG_ERROR, __FUNCSIG__, "Array is not sorted");
			return 1;
		}

		free(array_to_sort);

	return 0;
}

void init_array_to_malloc_random_i(int **array_to_malloc, int array_element_count, int maxValue) {
	*array_to_malloc = (int*)malloc(array_element_count * sizeof(int));
	if (NULL == *array_to_malloc) {
		logger_log(LOG_DEBUG, __FUNCSIG__, "Allocation memory failed");
		return;
	}
	srand(time(NULL));
	int i = 0;
	for(i =0; i < array_element_count; ++i){
		(*array_to_malloc)[i] = rand() % maxValue;
	}

}

void array_to_sort_i(int *array_to_sort, int array_element_count) {
	int temp = 0;
	int i = 0;
	int j = 0;

	for (i = 0; i < array_element_count; ++i) {
		for (j = 0; j < array_element_count - 1; ++j) {
			if (array_to_sort[j] > array_to_sort[j + 1]) {
				temp = array_to_sort[j];
				array_to_sort[j] = array_to_sort[j + 1];
				array_to_sort[j + 1] = temp;
			}
		}
	}
}

int check_array_is_sorted(int* array_to_sort, int array_element_count) {
	int i = 0;
	for (i = 0; i < array_element_count - 1; ++i) {
		if (array_to_sort[i] > array_to_sort[i + 1]);
		return 0;
	}
}*/



//****************************CHAPTER 2 - SINGLE LIST *********************************************

/*
typedef struct Element {
	int number;
	struct Element *next;
	struct Element *back;
} Element;

typedef struct List {
	Element* first;
} List;

List* init_single_list();
void single_list_insert_element(List* list, int newNumber);
void delete_element_first_from_single_list(List* list);


int main()
{
	logger_set_current_level(LOG_INFO);
	logger_log(LOG_DEBUG, __FUNCSIG__, "");


	List* newList = init_single_list();

	for (int i = 0; i <= 20; ++i)
	{
		single_list_insert_element(newList, i);
	}
		Element* current = newList->first;
		while (NULL != current)
		{
			printf("->%d", current->number);
			current = current->next;
		}
		printf("\n");

		delete_element_first_from_single_list(newList);
		Element* newCurrent = newList->first;
		while (NULL != newCurrent)
		{
			printf("->%d", newCurrent->number);
			newCurrent = newCurrent->next;
		}

		void stack_element_in_stack(Stack stack, int newNumber);

	return 0;

}

List* init_single_list()
{
	List* list = malloc(sizeof(List));

	if (NULL == list)
	{
		logger_log(LOG_DEBUG, __FUNCSIG__, "Memory allocation failure");
		return;
	}
	list->first = NULL;
	return list;

}


void single_list_insert_element(List* list, int newNumber)
{
	Element* newElement = malloc(sizeof(Element));
	if (NULL == newElement)
	{
		logger_log(LOG_DEBUG, __FUNCSIG__, "Memory allocation failure");
		return;
	}else
	{
		newElement->number = newNumber;
		newElement->next = list->first;
		newElement->back = NULL;
		list->first = newElement;
	}
}

void delete_element_first_from_single_list(List* list)
{
	if(NULL == list)
	{
		logger_log(LOG_DEBUG, __FUNCSIG__, "List not found");
		return;
	}
	if (NULL == list->first)
	{
		logger_log(LOG_INFO, __FUNCSIG__, "List is empty\n");
		return;
	}

	Element* temp = list->first;
	list->first = list->first->next;
	free(temp);
}

//****************************CHAPTER 3 - DOUBLE_LIST**********************************************


typedef struct Element
{
	int number;
	struct Element* next;
	struct Element* back;
} Element;

typedef struct List
{
	Element* first;
} List;

List* init_double_list();
void insert_element_in_list(List* list, int newNumber);
void delete_element_from_double_list(List* list);

int main(int argc, char* argv[])
{
	logger_set_current_level(LOG_INFO);
	logger_log(LOG_DEBUG, __FUNCSIG__, argv[0]);

	List* newList = init_double_list();
	for (int i = 0; i <= 20; ++i) {
		insert_element_in_list(newList, i);
	}
	Element* current = newList->first;
	while (NULL != current) {
		printf("->%d", current->number);
		current = current->next;
	}
	printf("\n");

	delete_element_from_double_list(newList);
	Element* newCurrent = newList->first;
	while (NULL != newCurrent) {
		printf("->%d", newCurrent->number);
		newCurrent = newCurrent->next;
	}
}
List* init_double_list() {
	List* list = malloc(sizeof(list));
	if (NULL == list) {
		logger_log(LOG_DEBUG, __FUNCSIG__, "Memory allocation failure");
	}
	else {
		list->first = NULL;
	}
	return;
}

void insert_element_in_list(List* list, int newNumber) {
	Element* newElement = malloc(sizeof(Element));
	if (NULL == newElement) {
		logger_log(LOG_DEBUG, __FUNCSIG__, "Memory allocation failure");
	}
	else {
		newElement->number = newNumber;
		newElement->next = NULL;
		newElement->back = NULL;
	}
	if (NULL == list->first) {
		list->first = newElement;
	}
	else {
		Element *current = list->first;
		while (NULL != current->next) {
			current = current->next;
		}
		current->next = newElement;
		newElement->back = current;
	}
}

void delete_element_from_double_list(List *list) {
	Element* temp = list->first;
	Element* current = list->first->next;
	list->first = current;
	current->back = NULL;
	free(temp);

}

//****************************CHAPTER 4 - STACK*****************************

typedef struct Element {
	int number;
	struct Element* next;
	struct Element* back;
} Element;

typedef struct Stack {
	Element* first;
} Stack;

void stack_element_in_stack(Stack *stack, int newNumber) {

	Element *newElement = malloc(sizeof(Element));
	if (NULL == stack) {
		logger_log(LOG_DEBUG, __FUNCSIG__, "Memory allocation failure");
		return -1;
	}

	newElement->number = newNumber;
	newElement->next = stack->first;
	stack->first = newElement;
}

int unstack_element_in_stack(Stack *stack) {
	if (NULL == stack) {
		logger_log(LOG_DEBUG, __FUNCSIG__, "Stack not found");
		return -1;
	}
	int unstackNumber = 0;
	if(NULL != stack->first){
		Element* unstack = stack->first;

		unstackNumber = unstack->number;
		stack->first = unstack->next;
		free(unstack);
	}
	return unstackNumber;
}

void display_element_in_stack(Stack* stack, int number_of_element){
	if (NULL == stack) {
		logger_log(LOG_DEBUG, __FUNCSIG__, "Stack not found");
		return -1;
	}

	Element* current = stack->first;
	while(NULL != current){
		number_of_element = current;
		current = current->next;
	}
}*/