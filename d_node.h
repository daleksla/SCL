#ifndef D_NODE_H
#define D_NODE_H
#pragma once

#include <stddef.h>

/** @brief Doubly linked node structure & functionality. FOR INTERNAL USAGE ONLY
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date Jun 2021
**/

#ifdef __cplusplus 
extern "C++" {
#endif // __cplusplus

typedef struct d_node {
	/** d_node struct, contains properties pertaining to doubly linked node **/
	void* data ; // stores node data
	
	struct d_node* next ; // stores link to next node in linked list
	
	struct d_node* prev ; // stores link to previous node in linked list

} d_node ;

/** d_node_init function, initialises empty doubly linked node
  * @return initialised doubly linked node struct **/
d_node d_node_init(void) ;

d_node d_node_init(void)
{
	d_node node ;
	node.data = NULL ;
	node.next = NULL ;
	node.prev = NULL ;
	return node ;
}

#ifdef __cplusplus 
} // "C++"
#endif // __cplusplus

#endif // D_NODE_H
