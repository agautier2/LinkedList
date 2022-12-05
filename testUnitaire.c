#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdlib.h>
#include "linkedList.h"

void test_new_element(){
    
    linked_list* HEAD = new_element(11);
    CU_ASSERT( HEAD->data == 11);
    CU_ASSERT( HEAD->next == NULL);
    CU_ASSERT( HEAD->prev == NULL);
    free_liste(HEAD);
}

void test_linked_list_push(){
    
    linked_list* HEAD = new_element(11);
    linked_list* elem0 = new_element(12);
    linked_list_push(HEAD,elem0);
    linked_list* elem1 = new_element(13);
    linked_list_push(HEAD,elem1);
    linked_list* pt = HEAD;

    

    CU_ASSERT( pt->data == 11);
    CU_ASSERT( pt->next == elem0);
    pt = pt->next;
    CU_ASSERT( pt->data == 12);
    CU_ASSERT( pt->next == elem1);
    pt = pt->next;
    CU_ASSERT( pt->data == 13);
    CU_ASSERT( pt->next == NULL);
    free_liste(HEAD);
}


void test_linked_list_pop(){
    

    linked_list* HEAD = new_element(11);
    linked_list* elem0 = new_element(12);
    linked_list* pt = HEAD;
    linked_list_push(HEAD,elem0);
    linked_list_pop(elem0);
    CU_ASSERT( pt->data == 11);
    CU_ASSERT( pt->next == NULL);
    linked_list_pop(HEAD);
    CU_ASSERT( pt->prev == NULL);
    CU_ASSERT( pt->next == NULL);
    free_liste(HEAD);

    
}

void test_linked_list_length(){

    linked_list* HEAD = new_element(11);
    CU_ASSERT( linked_list_length(HEAD) == 1);
    linked_list* elem0 = new_element(12);
    linked_list_push(HEAD,elem0);
    CU_ASSERT( linked_list_length(HEAD) == 2);
    linked_list* elem1 = new_element(13);
    linked_list_push(HEAD,elem1);
    CU_ASSERT( linked_list_length(HEAD) == 3);
    free_liste(HEAD);

}


void test_add_element_at_index(){

    linked_list* HEAD = new_element(11);
    linked_list* elem0 = new_element(12);
    linked_list_push(HEAD,elem0);
    linked_list* elem1 = new_element(14);
    add_element_at_index(HEAD,elem1,1);
    CU_ASSERT( linked_list_length(HEAD) == 3);
    linked_list* pt = HEAD;
    pt = pt->next;
    CU_ASSERT(pt->data == 14);
    CU_ASSERT(pt->next == elem0);
    free_liste(HEAD);
}



int init_suite(void){
    return 0;
}

int clean_suite(void){
    return 0;
}

int main(){
    CU_pSuite pSuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    pSuite = CU_add_suite("Suite_1", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (
        NULL == CU_add_test(pSuite, "test_test_new_element()", test_new_element)||
        NULL == CU_add_test(pSuite, "test_linked_list_push()", test_linked_list_push)||
        NULL == CU_add_test(pSuite, "test_linked_list_pop()", test_linked_list_pop) ||
        NULL == CU_add_test(pSuite, "test_linked_list_length()", test_linked_list_length) ||
        NULL == CU_add_test(pSuite, "test_test_add_element_at_index()", test_add_element_at_index)
    )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
    
}
