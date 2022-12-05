#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main(){

linked_list* HEAD = new_element(11);
linked_list* elem0 = new_element(12);
linked_list_push(HEAD,elem0);
linked_list* elem1 = new_element(11);
add_element_at_index(HEAD,elem1,1);
return 0;

}
