/* Include the code that we plan to test */
#include "../../list.h"
#include <stdio.h>

#define CHECK_TRUE(bool_val) ({\
	if((bool_val) != 1) return 1 ;\
})

/* list_init_test */
int list_init_test(void)
{
	list l = list_init() ;
	CHECK_TRUE(l.size == 0) ;
	CHECK_TRUE(l.head == NULL) ;
	CHECK_TRUE(l.tail == NULL) ;
	list_fini(&l) ;
	return 0 ;
}

/* list_append_test */
int list_append_test(void)
{
	list l = list_init() ;
	int i = 1 ; list* pL = &l ; // for some reason, macro function wanted predefined data
	list_append(pL, i) ;
	CHECK_TRUE(l.size == 1) ;
	CHECK_TRUE(l.head != NULL) ;
	CHECK_TRUE(l.tail != NULL) ;
	CHECK_TRUE(l.head == l.tail) ;
	list_append(pL, i) ;
	CHECK_TRUE(l.head != l.tail) ;
	list_fini(&l) ;
	return 0 ;
}

/* list_fini_test */
int list_fini_test(void)
{
	list l = list_init() ;
	list_fini(&l) ; 
	CHECK_TRUE(l.size == 0) ;
	CHECK_TRUE(l.head == NULL) ;
	CHECK_TRUE(l.tail == NULL) ;
	int i = 1 ;
	list* pL = &l ;
	list_append(pL, i) ; // so container actually stores data
	list_fini(&l) ; 
	CHECK_TRUE(l.size == 0) ;
	CHECK_TRUE(l.head == NULL) ;
	CHECK_TRUE(l.tail == NULL) ;
	return 0 ;
}

int main(int argc, char** argv)
{
	int curTestResult = 0 ;
	curTestResult = list_init_test() ;
	if(curTestResult == 1)
	{
		printf("%s\n", "One or more of the tests in list_init_test failed!") ;
		return -1 ;
	}
	curTestResult = list_append_test() ;
	if(curTestResult == 1)
	{
		printf("%s\n", "One or more of the tests in list_append_test failed!") ;
		return -1 ;
	}
	curTestResult = list_fini_test() ;
	if(curTestResult == 1)
	{
		printf("%s\n", "One or more of the tests in list_fini_test failed!") ;
		return -1 ;
	}
	return 0 ;
}
