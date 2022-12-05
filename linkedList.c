#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void linked_list_push(linked_list* root_list, linked_list* element){

    linked_list* current = root_list;
    while(current->next != NULL){ 
        current = current->next;  
    }
    current->next = element;
    element->prev = current;
}

void linked_list_pop(linked_list* root_list){

    linked_list* current = root_list;
    if(current->prev == NULL){
        free(current);
        return;
    } 
    
    while(current->next != NULL){
        current = current->next;
    }
    current = current->prev;
    free(current->next);
    current->next = NULL;         
}

void add_element_at_index(linked_list* root_list, linked_list* element, int index){
    linked_list* current = root_list;
    int i = 0;

    if(index==0){
        printf("impossible de modifier le head");
    }
    else if(index==linked_list_length(root_list)){
        linked_list_push(root_list,element);
    }
    else if(index<=linked_list_length(root_list)){
        while(i != index-1){
            current = current->next;
            i++;
        }
        linked_list* tmp = current->next;
        current->next = element; 
        element->prev = current;
        element->next= tmp;
    }
}   


int linked_list_length(linked_list* root_list){
    linked_list* current = root_list;
    int taille=0;
    while(current->next != NULL){
        current = current->next;
        taille++;
    }
    return taille+1;
}


void free_liste(linked_list* root_list){
    linked_list* current = root_list;
    linked_list* prev;

    while (current != NULL)
    {
        prev = current;
        current = current->prev;
        free(prev);
    }
    
   
}
        

linked_list* new_element(int data){

     linked_list *new =(linked_list*) malloc(sizeof(linked_list));

    if (new == NULL)
    {
        printf("Échec de l'allocation\n");
        return NULL;
    }
    new->data=data;
    new->prev = NULL;
    new->next = NULL;

    return new;

}





