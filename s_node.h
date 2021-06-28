#ifndef S_NODE_H
#define S_NODE_H
#pragma once

#include <stddef.h>

/** @brief Singly linked node structure & functionality. FOR INTERNAL USAGE ONLY
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date Jun 2021
**/

#ifdef __cplusplus 
extern "C++" {
#endif // __cplusplus

typedef struct s_node {
	/** d_node struct, contains properties pertaining to singly linked node **/
	void* data ; // stores node data
	
	struct s_node* next ; // stores link to next node in linked list

} s_node ;

/** s_node_init function, initialises empty singly linked node
  * @return initialised singly linked node struct **/
s_node s_node_init(void) ;

s_node s_node_init(void)
{
	s_node node ;
	node.data = NULL ;
	node.next = NULL ;
	return node ;
}

#ifdef __cplusplus 
} // "C++"
#endif // __cplusplus

#endif // S_NODE_H
