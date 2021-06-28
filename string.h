#ifndef STRING_H
#define STRING_H
#pragma once

#include <stdlib.h> // malloc, free
#include <string.h> // memcpy, memset
#include <stddef.h> // NULL keyword

/** @brief String structure & functionality to support resizeable character arrays
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date Jun 2021
**/

#ifdef __cplusplus 
extern "C++" {
#endif // __cplusplus

typedef struct {
	/** string struct, contains properties pertaining to string **/

	char* data ; // stores string data
	
	unsigned long size ; // stores actual items of data

} string ;

/** string_init function, initialises empty string
  * @return initialised string struct **/
string string_init(void) ;

/** string_copy function, copies contents of a given string 
  * @param const pointer to string
  * @return copy of given string **/
string string_copy(const string*) ;

/** string_assign function, sets contents as a given c-string
  * @param pointer to string to assign to
  * @param const char* (c-string) to assign **/
void string_assign(string*, const char*) ;

/** string_append function, adds char to end of a string data and resizes str capacity accordingly
  * @param pointer to string to append data to
  * @param char to add **/
void string_append(string*, char) ;

/** string_fini function, frees data held by provided string
  * @param pointer to string **/
void string_fini(string*) ;

string string_init(void)
{
	string str ;
	str.data = malloc(1) ;
	str.size = 0 ;
	return str ;
}

string string_copy(const string* cpStr)
{
	string str ;
	str.size = cpStr->size ;
	if(str.size > 0) 
	{
		str.data = malloc(str.size+1) ;
		memcpy(str.data, cpStr->data, str.size+1) ;
	}
	else {
		str.data = NULL ;
	}
	return str ;
}

void string_assign(string* str, const char* item)
{
	unsigned long strLength = strlen(item) ; 
	/*  allocate more memory accordingly, copy the data over, add new data, delete old location */
	char* newStrData = malloc(str->size+strLength+1) ;
	memset(newStrData, 0, str->size+strLength+1) ; /* there has to be a better alternative to avoid valgrinds message */
	memcpy(newStrData, str->data, str->size) ;
	free(str->data) ; /* delete the old bit of data */
	str->data = newStrData ; /* assign vector new memory location */
	memcpy(str->data+str->size, item, strLength) ;
	str->size += strLength ;
}

void string_append(string* str, char item)
{
	/*  allocate more memory accordingly, copy the data over, add new data, delete old location */
	char* newStrData = malloc(str->size+1+1) ;
	memset(newStrData, 0, str->size+1+1) ; /* there has to be a better alternative to avoid valgrinds message */
	memcpy(newStrData, str->data, str->size) ;
	free(str->data) ; /* delete the old bit of data */
	str->data = newStrData ; /* assign vector new memory location */
	str->data[str->size] = item ;
	++str->size ;
}

void string_fini(string* str)
{
	free((void*)str->data) ;
	str->data = NULL ;
	str->size = 0 ;
}

#ifdef __cplusplus 
} // "C++"
#endif // __cplusplus

#endif // STRING_H
