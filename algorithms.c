#ifndef ALGORITHMS_C
#define ALGORITHMS_C

#include "algorithms.h"
#include <stdio.h>
/** @brief Actual implementations of common algorithms. FOR INTERNAL USAGE ONLY
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

#ifdef __cplusplus
extern "C++" {
#endif // __cplusplus

unsigned long get_middle(const unsigned long totalSize)
{
	unsigned long middleN = 0;
	if(totalSize == 1) middleN = 0 ;
	else {
		if(totalSize % 2 == 0) middleN = (unsigned long)(totalSize / 2) ; 
		// if the list size is even, we just get the size / 2, rounded down
		else middleN = (unsigned long)(totalSize / 2) + 1 ;  // if list is odd, we get the size / 2, rounded up (by rounding down to a full int then adding 1 (e.g 3 / 2 == 1.5, 1.5->1->2 (since 2 is inbetween both values, giving us a 1 middle value))
	}
	return middleN ;
}
	
int binary_search_int(const int* list, const unsigned long size, const int target)
{
	if(size == 0) return 0 ;
	const unsigned long middleN = get_middle(size) ;
	const int middleVal = list[middleN] ; // get middle element of list
	printf("Current L: %d\nCurrent R: %d\nCurrent Size: %ld\n", *list, *(list+size-1), size) ;
	if(target == middleVal) return 1 ;
	else if(size != 1) // if there's more elements in the list we can actually look at
	{
		if(target < middleVal) return binary_search_int(list, middleN, target) ;
		else if(target > middleVal) return binary_search_int(list + middleN, size - middleN, target) ;
	}
	return 0 ; // if there aren't more elements we can look at
}
	
int binary_search_unsigned_int(const unsigned int* list, const unsigned long size, const unsigned int target)
{
	if(size == 0) return 0 ;
	const unsigned long middleN = get_middle(size) ;
	const unsigned int middleVal = list[middleN] ; // get middle element of list
	if(target == middleVal) return 1 ;
	else if(size != 1) // if there's more elements in the list we can actually look at
	{
		if(target < middleVal) return binary_search_unsigned_int(list, middleN - 1, target) ;
		else if(target > middleVal) return binary_search_unsigned_int(list + middleN - 1, size - middleN, target) ;
	}
	return 0 ; // if there aren't more elements we can look at
}
	
int binary_search_long(const long* list, const unsigned long size, const long target)
{
	if(size == 0) return 0 ;
	const unsigned long middleN = get_middle(size) ;
	const long middleVal = list[middleN] ; // get middle element of list
	if(target == middleVal) return 1 ;
	else if(size != 1) // if there's more elements in the list we can actually look at
	{
		if(target < middleVal) return binary_search_long(list, middleN, target) ;
		else if(target > middleVal) return binary_search_long(list + middleN - 1, size - middleN, target) ;
	}
	return 0 ; // if there aren't more elements we can look at
}
	
int binary_search_long_long(const long long* list, const unsigned long size, const long long target)
{
	if(size == 0) return 0 ;
	const unsigned long middleN = get_middle(size) ;
	const long long middleVal = list[middleN] ; // get middle element of list
	if(target == middleVal) return 1 ;
	else if(size != 1) // if there's more elements in the list we can actually look at
	{
		if(target < middleVal) return binary_search_long_long(list, middleN, target) ;
		else if(target > middleVal) return binary_search_long_long(list + middleN - 1, size - middleN, target) ;
	}
	return 0 ; // if there aren't more elements we can look at
}
		
int binary_search_unsigned_long(const unsigned long* list, const unsigned long size, const unsigned long target)
{
	if(size == 0) return 0 ;
	const unsigned long middleN = get_middle(size) ;
	const unsigned long middleVal = list[middleN] ; // get middle element of list
	if(target == middleVal) return 1 ;
	else if(size != 1) // if there's more elements in the list we can actually look at
	{
		if(target < middleVal) return binary_search_unsigned_long(list, middleN, target) ;
		else if(target > middleVal) return binary_search_unsigned_long(list + middleN - 1, size - middleN, target) ;
	}
	return 0 ; // if there aren't more elements we can look at
}
		
int binary_search_float(const float* list, const unsigned long size, const float target)
{
	if(size == 0) return 0 ;
	const unsigned long middleN = get_middle(size) ;
	const float middleVal = list[middleN] ; // get middle element of list
	if(target == middleVal) return 1 ;
	else if(size != 1) // if there's more elements in the list we can actually look at
	{
		if(target < middleVal) return binary_search_float(list, middleN, target) ;
		else if(target > middleVal) return binary_search_float(list + middleN - 1, size - middleN, target) ;
	}
	return 0 ; // if there aren't more elements we can look at
}
	
int binary_search_double(const double* list, const unsigned long size, const double target)
{
	if(size == 0) return 0 ;
	const unsigned long middleN = get_middle(size) ;
	const double middleVal = list[middleN] ; // get middle element of list
	if(target == middleVal) return 1 ;
	else if(size != 1) // if there's more elements in the list we can actually look at
	{
		if(target < middleVal) return binary_search_double(list, middleN, target) ;
		else if(target > middleVal) return binary_search_double(list + middleN - 1, size - middleN, target) ;
	}
	return 0 ; // if there aren't more elements we can look at
}

int binary_search_long_double(const long double* list, const unsigned long size, const long double target)
{
	if(size == 0) return 0 ;
	const unsigned long middleN = get_middle(size) ;
	const long double middleVal = list[middleN] ; // get middle element of list
	if(target == middleVal) return 1 ;
	else if(size != 1) // if there's more elements in the list we can actually look at
	{
		if(target < middleVal) return binary_search_long_double(list, middleN, target) ;
		else if(target > middleVal) return binary_search_long_double(list + middleN - 1, size - middleN, target) ;
	}
	return 0 ; // if there aren't more elements we can look at
}
	
int linear_search_int(const int* list, const unsigned long size, const int target)
{
	for(unsigned long i = 0 ; i < size ; ++i) if(list[i] == target) return 1 ;
	return 0 ;
}

int linear_search_unsigned_int(const unsigned int* list, const unsigned long size, const unsigned int target)
{
	for(unsigned long i = 0 ; i < size ; ++i) if(list[i] == target) return 1 ;
	return 0 ;
}

int linear_search_long(const long* list, const unsigned long size, const long target)
{
	for(unsigned long i = 0 ; i < size ; ++i) if(list[i] == target) return 1 ;
	return 0 ;
}
		
int linear_search_long_long(const long long* list, const unsigned long size, const long long target)
{
	for(unsigned long i = 0 ; i < size ; ++i) if(list[i] == target) return 1 ;
	return 0 ;
}		
		
int linear_search_unsigned_long(const unsigned long* list, const unsigned long size, const unsigned long target)
{
	for(unsigned long i = 0 ; i < size ; ++i) if(list[i] == target) return 1 ;
	return 0 ;
}	
	
int linear_search_float(const float* list, const unsigned long size, const float target)
{
	for(unsigned long i = 0 ; i < size ; ++i) if(list[i] == target) return 1 ;
	return 0 ;
}

int linear_search_double(const double* list, const unsigned long size, const double target)
{
	for(unsigned long i = 0 ; i < size ; ++i) if(list[i] == target) return 1 ;
	return 0 ;
}	
	
int linear_search_long_double(const long double* list, const unsigned long size, const long double target)
{
	for(unsigned long i = 0 ; i < size ; ++i) if(list[i] == target) return 1 ;
	return 0 ;
}	

#ifdef __cplusplus 
} // "C++"
#endif // __cplusplus

#endif // ALGORITHMS_C
