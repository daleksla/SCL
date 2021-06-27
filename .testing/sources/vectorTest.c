/* Include the code that we plan to test */
#include "../../c_vector.h"
#include <stdio.h>

#define CHECK_TRUE(bool_val) ({\
	if((bool_val) != 1) return 1 ;\
})

/* c_vector_init_test */
int c_vector_init_test(void)
{
	c_vector vec = c_vector_init() ;
	CHECK_TRUE(vec.size == 0) ;
	CHECK_TRUE(vec.bytes == 0) ;
	CHECK_TRUE(vec.data == NULL) ;
	c_vector_fini(&vec) ;
	return 0 ;
}

/* c_vector_append_test */
int c_vector_append_test(void)
{
	c_vector vec = c_vector_init() ;
	int i = 1 ; c_vector* pVec = &vec ; // for some reason, macro function wanted predefined data
	c_vector_append(pVec, i) ;
	CHECK_TRUE(vec.size == 1) ;
	CHECK_TRUE(vec.bytes == sizeof(i)) ;
	CHECK_TRUE(vec.data != NULL) ;
	c_vector_fini(&vec) ;
	return 0 ;
}

/* c_vector_fini_test */
int c_vector_fini_test(void)
{
	c_vector vec = c_vector_init() ;
	c_vector_fini(&vec) ; 
	CHECK_TRUE(vec.size == 0) ;
	CHECK_TRUE(vec.bytes == 0) ;
	CHECK_TRUE(vec.data == NULL) ;
	int i = 1 ;
	c_vector* pVec = &vec ;
	c_vector_append(pVec, i) ; // so container actually stores data
	c_vector_fini(&vec) ; 
	CHECK_TRUE(vec.size == 0) ;
	CHECK_TRUE(vec.bytes == 0) ;
	CHECK_TRUE(vec.data == NULL) ;
	return 0 ;
}

int main(int argc, char** argv)
{
	int curTestResult = 0 ;
	curTestResult = c_vector_init_test() ;
	if(curTestResult == 1)
	{
		printf("%s\n", "One or more of the tests in c_vector_init_test failed!") ;
		return -1 ;
	}
	curTestResult = c_vector_append_test() ;
	if(curTestResult == 1)
	{
		printf("%s\n", "One or more of the tests in c_vector_append_test failed!") ;
		return -1 ;
	}
	curTestResult = c_vector_fini_test() ;
	if(curTestResult == 1)
	{
		printf("%s\n", "One or more of the tests in c_vector_fini_test failed!") ;
		return -1 ;
	}
	return 0 ;
}
