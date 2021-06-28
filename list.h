#ifndef LIST_H
#define LIST_H
#pragma once

#include "d_node.h" // typedef'd struct d_node
#include <stdlib.h> // malloc, free
#include <string.h> // memcpy, memset

/** @brief Doubly linked list structure & functionality
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date Jun 2021
**/

#ifdef __cplusplus 
extern "C++" {
#endif // __cplusplus

typedef struct {
	/** list struct, contains properties pertaining to doubly linked list **/
	unsigned long size ; // amounts of items of data
	
	unsigned long bytes ; // amount of bytes allocated (needed for memory management of generic type)
	
	struct d_node* head ; // stores link to next node in linked list
	
	struct d_node* tail ; // stores link to previous node in linked list

} list ;

/** list_init function, initialises empty doubly linked list
  * @return initialised doubly linked list struct **/
list list_init(void) ;

/** list_copy function, copies contents of a given list 
  * @param const pointer to list
  * @return copy of given list **/
list list_copy(const list*) ;

/** list_append function, adds item of data to end of a linked list by adding additional node
  * @param pointer to list to append data to
  * @param l-value (ie pre-initialised) item of data to add **/
#define list_append(qwerty_x_list_l_abcd, qwerty_x_data_l_abcd) ({\
	/* initialise node & set its data */\
	d_node* pNode = (d_node*)malloc(sizeof(d_node)) ;\
	*pNode = d_node_init() ;\
	pNode->data = (void*)&qwerty_x_data_l_abcd ;\
	/* check where it belongs */\
	if(qwerty_x_list_l_abcd->size == 0)\
	{\
		qwerty_x_list_l_abcd->head = pNode ;\
		qwerty_x_list_l_abcd->tail = pNode ;\
	}\
	else {\
		qwerty_x_list_l_abcd->tail->next = pNode ;\
		qwerty_x_list_l_abcd->tail = pNode ;\
	}\
	++qwerty_x_list_l_abcd->size ;\
	qwerty_x_list_l_abcd->bytes += sizeof(d_node) ;\
})

/** list_fini function, frees data held by provided list
  * @param pointer to list **/
void list_fini(list*) ;

list list_init(void)
{
	list myList ;
	myList.bytes = 0 ;
	myList.size = 0 ;
	myList.head = NULL ;
	myList.tail = NULL ;
	return myList ;
}

list list_copy(const list* i_list)
{
	list myList = list_init() ;
	if(i_list->size == 0) return myList ;
	struct d_node* otherNode = i_list->head ;
	list* pList = &myList ;
	for(unsigned int i = 0 ; i < i_list->size ; ++i)
	{
		list_append(pList, otherNode->data) ;
		otherNode = otherNode->next ;
	}
	return myList ;
}

void list_fini(list* i_list)
{
	if(i_list->head != NULL)
	{
		struct d_node* cur = i_list->head ;
		struct d_node* next = NULL ;
		while(cur != NULL)
		{
			next = cur->next ;
			free(cur) ;
			cur = next ;
		}
		i_list->bytes = 0 ;
		i_list->size = 0 ;
		i_list->head = NULL ;
		i_list->tail = NULL ;
	}
}

#ifdef __cplusplus 
} // "C++"
#endif // __cplusplus

#endif // LIST_H
