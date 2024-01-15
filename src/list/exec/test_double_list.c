#include <stdlib.h>

#include <common/common.h>
#include <list/double_list.h>



int main(int argc, char* argv[])
{
  logger_set_current_level(LOG_DEBUG);
  logger_log(LOG_DEBUG, __FUNCSIG__, argv[0]);

  Liste *new_list = double_list_init();
  for(int i = 0; i < 20; ++i){
	  double_list_insert_element(new_list, i);
  }
	  double_list_display(new_list);
	  /*
	  Element* current = new_list->first;
	  while (NULL != current) {
		  printf("%d->", current->number);
		  current = current->next;
	  }*/
	  double_list_delete_first(new_list);
	  printf("\n");
	  double_list_display(new_list);
	  printf("\n");
	  double_list_delete_by_number(new_list, 4);
	  printf("\n");
	  double_list_display(new_list);
	  printf("\n");
	  double_list_delete_all(new_list);
	  printf("\n");
	  double_list_display(new_list);
	 
	  

	  return 0;
  
}