#include "php_sample.h"

/*
  1. define the namespace for your extension
 */
#define SAMPLE_NS "sample"

/*
  2. implement a php function
 */
PHP_FUNCTION(sample_hello_world)
{
  php_printf("Hello World!\n");
}

/*
  3. define a list for your extension functions
*/
const zend_function_entry php_sample_functions[] = {
  /*
    4. register the function in the namespace
   */
  ZEND_NS_NAMED_FE(SAMPLE_NS, helloWorld, ZEND_FN(sample_hello_world), NULL)
  PHP_FE_END
};

zend_module_entry sample_module_entry = {
  STANDARD_MODULE_HEADER,
  PHP_SAMPLE_EXTNAME,
  /*
   5. add the functions to the module entry
   */
  php_sample_functions, /* Functions */
  NULL, /* MINIT */
  NULL, /* MSHUTDOWN */
  NULL, /* RINIT */
  NULL, /* RSHUTDOWN */
  NULL, /* MINFO */
  PHP_SAMPLE_EXTVER,
  STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_SAMPLE
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(sample)
#endif
