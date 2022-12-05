#ifndef LINKEDLIST
#define LINKEDLIST

typedef struct linked_list{
int data;
struct linked_list* next;
struct linked_list* prev;
} linked_list;

void linked_list_push(linked_list* root_list, linked_list* element);
void linked_list_pop(linked_list* root_list);
void add_element_at_index(linked_list* root_list, linked_list* element, int index);
int linked_list_length(linked_list* root_list);
void free_liste(linked_list* root_list);
linked_list* new_element(int data);

#endif
