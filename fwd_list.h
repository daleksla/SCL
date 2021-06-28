#ifndef FWD_LIST_H
#define FWD_LIST_H
#pragma once

#include "d_node.h" // typedef'd struct d_node
#include <stdlib.h> // malloc, free
#include <string.h> // memcpy, memset

/** @brief Singly linked list structure & functionality
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date Jun 2021
**/

#ifdef __cplusplus 
extern "C++" {
#endif // __cplusplus

typedef struct {
	/** fwd_list struct, contains properties pertaining to singly linked list **/
	unsigned long size ; // amounts of items of data
	
	struct s_node* head ; // stores link to first node in linked list
	
	struct s_node* tail ; // stores link to end node in linked list

} fwd_list ;

/** fwd_list_init function, initialises empty singly linked list
  * @return initialised singly linked list struct **/
fwd_list fwd_list_init(void) ;

/** fwd_list_copy function, copies contents of a given list 
  * @param const pointer to list
  * @return copy of given list **/
fwd_list fwd_list_copy(const list*) ;

/** fwd_list_append function, adds item of data to end of a linked list by adding additional node
  * @param pointer to fwd_list to append data to
  * @param l-value (ie pre-initialised) item of data to add **/
#define fwd_list_append(qwerty_x_fwd_list_l_abcd, qwerty_x_data_l_abcd) ({\
	/* initialise node & set its data */\
	d_node* pNode = (d_node*)malloc(sizeof(d_node)) ;\
	*pNode = d_node_init() ;\
	pNode->data = (void*)&qwerty_x_data_l_abcd ;\
	/* check where it belongs */\
	if(qwerty_x_fwd_list_l_abcd->size == 0)\
	{\
		qwerty_x_fwd_list_l_abcd->head = pNode ;\
		qwerty_x_fwd_list_l_abcd->tail = pNode ;\
	}\
	else {\
		qwerty_x_fwd_list_l_abcd->tail->next = pNode ;\
		qwerty_x_fwd_list_l_abcd->tail = pNode ;\
	}\
	++qwerty_x_fwd_list_l_abcd->size ;\
})

/** fwd_list_fini function, frees data held by provided fwd_list
  * @param pointer to fwd_list **/
void fwd_list_fini(fwd_list*) ;

fwd_list fwd_list_init(void)
{
	fwd_list myList ;
	myList.size = 0 ;
	myList.head = NULL ;
	myList.tail = NULL ;
	return myList ;
}

fwd_list fwd_list_copy(const fwd_list* i_list)
{
	fwd_list myList = list_init() ;
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

void fwd_list_fini(fwd_list* i_list)
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
		i_list->size = 0 ;
		i_list->head = NULL ;
		i_list->tail = NULL ;
	}
}

#ifdef __cplusplus 
} // "C++"
#endif // __cplusplus

#endif // FWD_LIST_H
