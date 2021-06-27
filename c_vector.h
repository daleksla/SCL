#ifndef C_VECTOR_H
#define C_VECTOR_H
#pragma once

#include <stdlib.h> // malloc, free
#include <string.h> // memcpy, memset

/** @brief Vector structure & functionality to support dynamically allocated arrays
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date Jun 2021
**/

#ifdef __cplusplus 
extern "C++" {
#endif // __cplusplus

typedef struct {
	/** c_vector struct, contains properties pertaining to vector **/

	void* data ; // stores vector data
	unsigned long bytes ; // stores bytes allocated
	unsigned long size ; // stores actual items of data

} c_vector ;

/** c_vector_init function, initialises empty vector
  * @return initialised c_vector struct **/
c_vector c_vector_init() ;

/** c_vector_copy function, copies contents of a given c_vector. 
  * @param const pointer to c_vector
  * @return copy of given c_vector **/
c_vector c_vector_copy(const c_vector* cpVec)

/** c_vector_fini function, frees data held by provided c_vector
  * @param pointer to c_vector **/
void c_vector_fini(c_vector* vec)

c_vector c_vector_init() ;
{
	c_vector vec ;
	vec.data = NULL ;
	vec.bytes = 0 ;
	vec.size = 0 ;
	return vec ;
}

c_vector c_vector_copy(const c_vector* cpVec)
{
	c_vector vec ;
	vec.bytes = cpVec->bytes ;
	vec.size = cpVec->size ;
	if(vec.bytes) 
	{
		vec.data = malloc(vec.bytes) ;
		memcpy(vec.data, cpVec->data, vec.bytes) ;
	}
	else {
		vec.data = NULL ;
	}
	return vec ;
}

#define c_vector_append(vec, item) ({\
	unsigned long bytes = sizeof(item) ;\
	/* then, allocate more memory accordingly, copy the data over, add new data, delete old location */\
	void* newVecData = malloc(vec->bytes+bytes) ;\
	memset(newVecData, 0, vec->bytes+bytes) ; /* there has to be a better alternative to avoid valgrinds message */\
	memcpy(newVecData, vec->data, vec->bytes) ;\
	free(vec->data) ; /* delete the old bit of data */\
	vec->data = newVecData ; /* assign vector new memory location */\
	((char*)vec->data)[vec->bytes] = item ;\
	vec->bytes += bytes ;\
	++vec->size ;\
})

void c_vector_fini(c_vector* vec)
{
	if(vec->data) 
	{
		free(vec->data) ;
		vec->data = NULL ;
	}
}

#ifdef __cplusplus 
} // "C++"
#endif // __cplusplus

#endif // C_VECTOR_H
