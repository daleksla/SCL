/* Include the code that we plan to test */
#include "../../vector.h"
#include <stdio.h>

#define CHECK_TRUE(bool_val) ({\
	if((bool_val) != 1) return 1 ;\
})

/* vector_init_test */
int vector_init_test(void)
{
	vector vec = vector_init() ;
	CHECK_TRUE(vec.size == 0) ;
	CHECK_TRUE(vec.bytes == 0) ;
	CHECK_TRUE(vec.data == NULL) ;
	vector_fini(&vec) ;
	return 0 ;
}

/* vector_append_test */
int vector_append_test(void)
{
	vector vec = vector_init() ;
	int i = 1 ; vector* pVec = &vec ; // for some reason, macro function wanted predefined data
	vector_append(pVec, i) ;
	CHECK_TRUE(vec.size == 1) ;
	CHECK_TRUE(vec.bytes == sizeof(i)) ;
	CHECK_TRUE(vec.data != NULL) ;
	vector_fini(&vec) ;
	return 0 ;
}

/* vector_fini_test */
int vector_fini_test(void)
{
	vector vec = vector_init() ;
	vector_fini(&vec) ; 
	CHECK_TRUE(vec.size == 0) ;
	CHECK_TRUE(vec.bytes == 0) ;
	CHECK_TRUE(vec.data == NULL) ;
	int i = 1 ;
	vector* pVec = &vec ;
	vector_append(pVec, i) ; // so container actually stores data
	vector_fini(&vec) ; 
	CHECK_TRUE(vec.size == 0) ;
	CHECK_TRUE(vec.bytes == 0) ;
	CHECK_TRUE(vec.data == NULL) ;
	return 0 ;
}

int main(int argc, char** argv)
{
	int curTestResult = 0 ;
	curTestResult = vector_init_test() ;
	if(curTestResult == 1)
	{
		printf("%s\n", "One or more of the tests in vector_init_test failed!") ;
		return -1 ;
	}
	curTestResult = vector_append_test() ;
	if(curTestResult == 1)
	{
		printf("%s\n", "One or more of the tests in vector_append_test failed!") ;
		return -1 ;
	}
	curTestResult = vector_fini_test() ;
	if(curTestResult == 1)
	{
		printf("%s\n", "One or more of the tests in vector_fini_test failed!") ;
		return -1 ;
	}
	return 0 ;
}
