/* cairo extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_cairo.h"
#include "cairo_arginfo.h"
#include "php_cairo/rectangle.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

/* {{{ void test1() */
PHP_FUNCTION(test1)
{
	ZEND_PARSE_PARAMETERS_NONE();

	php_printf("The extension %s is loaded and working!\r\n", "cairo");
}
/* }}} */

/* {{{ string test2( [ string $var ] ) */
PHP_FUNCTION(test2)
{
	char *var = "World";
	size_t var_len = sizeof("World") - 1;
	zend_string *retval;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(var, var_len)
	ZEND_PARSE_PARAMETERS_END();

	retval = strpprintf(0, "Hello %s", var);

	RETURN_STR(retval);
}
/* }}}*/

/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(cairo)
{
#if defined(ZTS) && defined(COMPILE_DL_CAIRO)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(cairo)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "cairo support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(cairo)
{
    zend_class_entry ce;

    //zend_hash_init(&classes, 0, NULL, NULL, 1);
    PHP_CAIRO_RECTANGLE_T_MINIT_FUNCTION(&ce, NULL);


    return SUCCESS;
}
/* }}} */

/* {{{ cairo_module_entry */
zend_module_entry cairo_module_entry = {
	STANDARD_MODULE_HEADER,
	"cairo",			/* Extension name */
	ext_functions,			/* zend_function_entry */
	PHP_MINIT(cairo),		/* PHP_MINIT - Module initialization */
	NULL,				/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(cairo),		/* PHP_RINIT - Request initialization */
	NULL,				/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(cairo),		/* PHP_MINFO - Module info */
	PHP_CAIRO_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_CAIRO
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(cairo)
#endif
