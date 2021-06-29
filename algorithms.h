#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#pragma once

/** @brief Implementations of common algorithms, such as sorts, searches, etc.
    @author Salih Mahmoud Sayed Ahmed
    @email ahmed233@uni.coventry.ac.uk
    @date May 2021
**/

#ifdef __cplusplus
extern "C++" {
#endif // __cplusplus

/** This function obtains the 'middle index' value, based on a given size
 * @param const unsigned long (size of list to determine middle of)
 * @return unsigned long ('middle' index) **/
unsigned long get_middle(const unsigned long totalSize) ;

/** This is a linear search algorithm for integer arrays
 * @param const pointer to int array (to be searched)
 * @param unsigned long, correlating to size of array
 * @param const int correlating to target (to be identified in list)
 * @return int representing boolean value (indicates if supplied target was found or not) **/	
int linear_search_int(const int*, const unsigned long, const int) ;

/** This is a linear search algorithm for unsigned int arrays
 * @param const pointer to unsigned int array (to be searched)
 * @param const unsigned long, correlating to size of array
 * @param const unsigned int correlating to target (to be identified in list)
 * @return int representing boolean value (indicates if supplied target was found or not) **/	
int linear_search_unsigned_int(const unsigned int*, const unsigned long, const unsigned int) ;

/** This is a linear search algorithm for long arrays
 * @param const pointer to long array (to be searched)
 * @param unsigned long, correlating to size of array
 * @param const long correlating to target (to be identified in list)
 * @return int representing boolean (indicates if supplied target was found or not) **/	
int linear_search_long(const long*, const unsigned long, const long) ;
	
/** This is a linear search algorithm for long long arrays
 * @param const pointer to long long array (to be searched)
 * @param unsigned long, correlating to size of array
 * @param const long long correlating to target (to be identified in list)
 * @return int representing boolean (indicates if supplied target was found or not) **/	
int linear_search_long_long(const long long*, const unsigned long, const long long) ;
	
/** This is a linear search algorithm for unsigned long arrays
 * @param const pointer to unsigned long array (to be searched)
 * @param unsigned long, correlating to size of array
 * @param const unsigned long correlating to target (to be identified in list)
 * @return int representing boolean (indicates if supplied target was found or not) **/	
int linear_search_unsigned_long(const unsigned long*, const unsigned long, const unsigned long) ;
	
/** This is a linear search algorithm for float arrays
 * @param const pointer to float array (to be searched)
 * @param const unsigned long, correlating to size of array
 * @param const float correlating to target (to be identified in list)
 * @return int representing boolean (indicates if supplied target was found or not) **/	
int linear_search_float(const float*, const unsigned long, const float) ;

/** This is a linear search algorithm for double arrays
 * @param const pointer to double array (to be searched)
 * @param const unsigned long, correlating to size of array
 * @param const double correlating to target (to be identified in list)
 * @return int representing boolean (indicates if supplied target was found or not) **/	
int linear_search_double(const double*, const unsigned long, const double) ;

/** This is a linear search algorithm for long double arrays
 * @param const pointer to long double array (to be searched)
 * @param const unsigned long, correlating to size of array
 * @param const long double correlating to target (to be identified in list)
 * @return int representing boolean (indicates if supplied target was found or not) **/	
int linear_search_long_double(const long double*, const unsigned long, const long double) ;

/** This is a binary search algorithm for integer arrays, which splits a list into sub-segments to look upon and repeats until the element is found
 * @param const pointer to int array (to be searched)
 * @param unsigned long, correlating to size of array
 * @param const int correlating to target (to be identified in list)
 * @return int representing boolean (indicates if supplied target was found or not) **/	
int binary_search_int(const int*, const unsigned long, const int) ;

/** This is a binary search algorithm for unsigned int arrays, which splits a list into sub-segments to look upon and repeats until the element is found
 * @param const pointer to unsigned int array (to be searched)
 * @param const unsigned long, correlating to size of array
 * @param const unsigned int correlating to target (to be identified in list)
 * @return int representing boolean (indicates if supplied target was found or not) **/	
int binary_search_unsigned_int(const unsigned int*, const unsigned long, const unsigned int) ;

/** This is a binary search algorithm for long arrays, which splits a list into sub-segments to look upon and repeats until the element is found
 * @param const pointer to long array (to be searched)
 * @param unsigned long, correlating to size of array
 * @param const long correlating to target (to be identified in list)
 * @return int representing boolean (indicates if supplied target was found or not) **/	
int binary_search_long(const long*, const unsigned long, const long) ;
	
/** This is a binary search algorithm for long long arrays, which splits a list into sub-segments to look upon and repeats until the element is found
 * @param const pointer to long long array (to be searched)
 * @param unsigned long, correlating to size of array
 * @param const long long correlating to target (to be identified in list)
 * @return int representing boolean (indicates if supplied target was found or not) **/	
int binary_search_long_long(const long long*, const unsigned long, const long long) ;
	
/** This is a binary search algorithm for unsigned long arrays, which splits a list into sub-segments to look upon and repeats until the element is found
 * @param const pointer to unsigned long array (to be searched)
 * @param unsigned long, correlating to size of array
 * @param const unsigned long correlating to target (to be identified in list)
 * @return int representing boolean (indicates if supplied target was found or not) **/	
int binary_search_unsigned_long(const unsigned long*, const unsigned long, const unsigned long) ;
	
/** This is a binary search algorithm for float arrays, which splits a list into sub-segments to look upon and repeats until the element is found
 * @param const pointer to float array (to be searched)
 * @param const unsigned long, correlating to size of array
 * @param const float correlating to target (to be identified in list)
 * @return int representing boolean (indicates if supplied target was found or not) **/	
int binary_search_float(const float*, const unsigned long, const float) ;

/** This is a binary search algorithm for double arrays, which splits a list into sub-segments to look upon and repeats until the element is found
 * @param const pointer to double array (to be searched)
 * @param const unsigned long, correlating to size of array
 * @param const double correlating to target (to be identified in list)
 * @return int representing boolean (indicates if supplied target was found or not) **/	
int binary_search_double(const double*, const unsigned long, const double) ;

/** This is a binary search algorithm for long double arrays, which splits a list into sub-segments to look upon and repeats until the element is found
 * @param const pointer to long double array (to be searched)
 * @param const unsigned long, correlating to size of array
 * @param const long double correlating to target (to be identified in list)
 * @return int representing boolean  (indicates if supplied target was found or not) **/	
int binary_search_long_double(const long double*, const unsigned long, const long double) ;

#ifdef __cplusplus 
} // "C++"
#endif // __cplusplus

#endif // ALGORITHMS_H
