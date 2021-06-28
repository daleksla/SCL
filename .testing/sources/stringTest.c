/* Include the code that we plan to test */
#include "../../string.h"
#include <stdio.h>

#define CHECK_TRUE(bool_val) ({\
	if((bool_val) != 1) return 1 ;\
})

/* string_init_test */
int string_init_test(void)
{
	string str = string_init() ;
	CHECK_TRUE(str.size == 0) ;
	CHECK_TRUE(str.data == NULL) ;
	string_fini(&str) ;
	return 0 ;
}

/* string_append_test */
int string_append_test(void)
{
	string str = string_init() ;
	int i = 1 ; string* pStr = &str ; // for some reason, macro function wanted predefined data
	string_append(pStr, i) ;
	CHECK_TRUE(str.size == 1) ;
	CHECK_TRUE(str.data != NULL) ;
	string_fini(&str) ;
	return 0 ;
}

/* string_fini_test */
int string_fini_test(void)
{
	string str = string_init() ;
	string_fini(&str) ; 
	CHECK_TRUE(str.size == 0) ;
	CHECK_TRUE(str.data == NULL) ;
	int i = 1 ;
	string* pStr = &str ;
	string_append(pStr, i) ; // so container actually stores data
	string_fini(&str) ; 
	CHECK_TRUE(str.size == 0) ;
	CHECK_TRUE(str.data == NULL) ;
	return 0 ;
}

int main(int argc, char** argv)
{
	int curTestResult = 0 ;
	curTestResult = string_init_test() ;
	if(curTestResult == 1)
	{
		printf("%s\n", "One or more of the tests in string_init_test failed!") ;
		return -1 ;
	}
	curTestResult = string_append_test() ;
	if(curTestResult == 1)
	{
		printf("%s\n", "One or more of the tests in string_append_test failed!") ;
		return -1 ;
	}
	curTestResult = string_fini_test() ;
	if(curTestResult == 1)
	{
		printf("%s\n", "One or more of the tests in string_fini_test failed!") ;
		return -1 ;
	}
	return 0 ;
}
