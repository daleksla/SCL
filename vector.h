#ifndef VECTOR_H
#define VECTOR_H
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
	/** vector struct, contains properties pertaining to vector **/

	void* data ; // stores vector data
	
	unsigned long bytes ; // stores bytes allocated
	
	unsigned long size ; // stores actual items of data

} vector ;

/** vector_init function, initialises empty vector
  * @return initialised vector struct **/
vector vector_init() ;

/** vector_copy function, copies contents of a given vector. 
  * @param const pointer to vector
  * @return copy of given vector **/
vector vector_copy(const vector*) ;

/** vector_fini function, frees data held by provided vector
  * @param pointer to vector **/
void vector_fini(vector*) ;

vector vector_init()
{
	vector vec ;
	vec.data = NULL ;
	vec.bytes = 0 ;
	vec.size = 0 ;
	return vec ;
}

vector vector_copy(const vector* cpVec)
{
	vector vec ;
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

/** vector_append function, adds item of data to end of a vector data and resizes accordingly
  * @param pointer to vector to append data to
  * @param l-value (ie pre-initialised) item of data to add **/
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

void vector_fini(vector* vec)
{
	if(vec->data != NULL) 
	{
		free(vec->data) ;
		vec->data = NULL ;
		vec->size = 0 ;
		vec->bytes = 0 ;
	}
}

#ifdef __cplusplus 
} // "C++"
#endif // __cplusplus

#endif // C_VECTOR_H
