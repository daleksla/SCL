/* Include the code that we plan to test */
#include "../../fwd_list.h"
#include <stdio.h>

#define CHECK_TRUE(bool_val) ({\
	if((bool_val) != 1) return 1 ;\
})

/* fwd_list_init_test */
int fwd_list_init_test(void)
{
	fwd_list l = fwd_list_init() ;
	CHECK_TRUE(l.size == 0) ;
	CHECK_TRUE(l.head == NULL) ;
	CHECK_TRUE(l.tail == NULL) ;
	fwd_list_fini(&l) ;
	return 0 ;
}

/* fwd_list_append_test */
int fwd_list_append_test(void)
{
	fwd_list l = fwd_list_init() ;
	int i = 1 ; fwd_list* pL = &l ; // for some reason, macro function wanted predefined data
	fwd_list_append(pL, i) ;
	CHECK_TRUE(l.size == 1) ;
	CHECK_TRUE(l.head != NULL) ;
	CHECK_TRUE(l.tail != NULL) ;
	CHECK_TRUE(l.head == l.tail) ;
	fwd_list_append(pL, i) ;
	CHECK_TRUE(l.head != l.tail) ;
	fwd_list_fini(&l) ;
	return 0 ;
}

/* fwd_list_fini_test */
int fwd_list_fini_test(void)
{
	fwd_list l = fwd_list_init() ;
	fwd_list_fini(&l) ; 
	CHECK_TRUE(l.size == 0) ;
	CHECK_TRUE(l.head == NULL) ;
	CHECK_TRUE(l.tail == NULL) ;
	int i = 1 ;
	fwd_list* pL = &l ;
	fwd_list_append(pL, i) ; // so container actually stores data
	fwd_list_fini(&l) ; 
	CHECK_TRUE(l.size == 0) ;
	CHECK_TRUE(l.head == NULL) ;
	CHECK_TRUE(l.tail == NULL) ;
	return 0 ;
}

int main(int argc, char** argv)
{
	int curTestResult = 0 ;
	curTestResult = fwd_list_init_test() ;
	if(curTestResult == 1)
	{
		printf("%s\n", "One or more of the tests in fwd_list_init_test failed!") ;
		return -1 ;
	}
	curTestResult = fwd_list_append_test() ;
	if(curTestResult == 1)
	{
		printf("%s\n", "One or more of the tests in fwd_list_append_test failed!") ;
		return -1 ;
	}
	curTestResult = fwd_list_fini_test() ;
	if(curTestResult == 1)
	{
		printf("%s\n", "One or more of the tests in fwd_list_fini_test failed!") ;
		return -1 ;
	}
	return 0 ;
}
