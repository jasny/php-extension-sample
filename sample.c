#include "php_sample.h"

#define SAMPLE_NS "sample"

PHP_FUNCTION(sample_getGreetings)
{
    HashTable *names;
    zval *name;

    ZEND_PARSE_PARAMETERS_START(1, 1)
    	Z_PARAM_ARRAY_HT(names)
    ZEND_PARSE_PARAMETERS_END();

    /*
      1. initialize the return value as an array
    */
    array_init(return_value);

    ZEND_HASH_FOREACH_VAL(names, name) {
        zend_string *greeting = strpprintf(0, "Hello %s!", ZSTR_VAL(zval_get_string(name)));

        /*
          2. add greeting to list
        */
        add_next_index_str(return_value, greeting);
    } ZEND_HASH_FOREACH_END();
}

const zend_function_entry php_sample_functions[] = {
  ZEND_NS_NAMED_FE(SAMPLE_NS, getGreetings, ZEND_FN(sample_getGreetings), NULL)
  PHP_FE_END
};

zend_module_entry sample_module_entry = {
  STANDARD_MODULE_HEADER,
  PHP_SAMPLE_EXTNAME,
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
