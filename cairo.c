/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2018 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif


#include <php.h>
#include <php_ini.h>
#include <zend_interfaces.h>
#include <ext/standard/info.h>

#include <cairo/cairo.h>

#include "php_cairo.h"
#include "php_cairo/cairo.h"
#include "php_cairo/status.h"
#include "php_cairo/antialias.h"
#include "php_cairo/content.h"
#include "php_cairo/device-type.h"
#include "php_cairo/extend.h"
#include "php_cairo/fill-rule.h"
#include "php_cairo/filter.h"
#include "php_cairo/font-slant.h"
#include "php_cairo/font-type.h"
#include "php_cairo/font-weight.h"
#include "php_cairo/hint-metrics.h"
#include "php_cairo/hint-style.h"
#include "php_cairo/line-cap.h"
#include "php_cairo/line-join.h"
#include "php_cairo/operator.h"
#include "php_cairo/pattern-type.h"
#include "php_cairo/region-overlap.h"
#include "php_cairo/subpixel-order.h"
#include "php_cairo/surface-type.h"
#include "php_cairo/text-cluster-flags.h"

#include "php_cairo/rectangle.h"
#include "php_cairo/path-data-type.h"
#include "php_cairo/path-data.h"
#include "php_cairo/path.h"
#include "php_cairo/png.h"
#include "php_cairo/matrix.h"
#include "php_cairo/surface.h"
#if CAIRO_HAS_IMAGE_SURFACE
#include "php_cairo/format.h"
#include "php_cairo/image-surface.h"
#endif
#if CAIRO_VERSION >= 11600
//#include "php_cairo/pdf-metadata.h"
#endif




HashTable classes;

/* If you declare any globals in php_gtk.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(gtk)
*/

/* True global resources - no need for thread safety here */
static int le_gtk;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("gtk.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_gtk_globals, gtk_globals)
    STD_PHP_INI_ENTRY("gtk.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_gtk_globals, gtk_globals)
PHP_INI_END()
*/
/* }}} */


/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/


/* {{{ php_gtk_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_gtk_init_globals(zend_gtk_globals *gtk_globals)
{
	gtk_globals->global_value = 0;
	gtk_globals->global_string = NULL;
}
*/
/* }}} */


/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(cairo)
{
    //int zm_startup_gtk(int type, int module_number)

	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/

	zend_class_entry ce;

	zend_hash_init(&classes, 0, NULL, NULL, 1);

                        PHP_CAIRO_T_MINIT_FUNCTION(&ce, NULL);

                        PHP_CAIRO_ANTIALIAS_T_MINIT_FUNCTION(NULL, NULL);
                        PHP_CAIRO_FILL_RULE_T_MINIT_FUNCTION(NULL, NULL);
                        PHP_CAIRO_LINE_CAP_T_MINIT_FUNCTION(NULL, NULL);
                        PHP_CAIRO_LINE_JOIN_T_MINIT_FUNCTION(NULL, NULL);
                        PHP_CAIRO_OPERATOR_T_MINIT_FUNCTION(NULL, NULL);
                        PHP_CAIRO_PATH_DATA_TYPE_T_MINIT_FUNCTION(NULL, NULL);
                        PHP_CAIRO_EXTEND_T_MINIT_FUNCTION(NULL, NULL);
                        PHP_CAIRO_FILTER_T_MINIT_FUNCTION(NULL, NULL);
                        PHP_CAIRO_PATTERN_TYPE_T_MINIT_FUNCTION(NULL, NULL);
                        PHP_CAIRO_REGION_OVERLAP_T_MINIT_FUNCTION(NULL, NULL);
                        PHP_CAIRO_FONT_SLANT_T_MINIT_FUNCTION(NULL, NULL);
                        PHP_CAIRO_FONT_WEIGHT_T_MINIT_FUNCTION(NULL, NULL);
                        PHP_CAIRO_TEXT_CLUSTER_FLAGS_T_MINIT_FUNCTION(NULL, NULL);
                        PHP_CAIRO_FONT_TYPE_T_MINIT_FUNCTION(NULL, NULL);
                        PHP_CAIRO_SUBPIXEL_ORDER_T_MINIT_FUNCTION(NULL, NULL);
                        PHP_CAIRO_HINT_STYLE_T_MINIT_FUNCTION(NULL, NULL);
                        PHP_CAIRO_HINT_METRICS_T_MINIT_FUNCTION(NULL, NULL);
                        PHP_CAIRO_DEVICE_TYPE_T_MINIT_FUNCTION(NULL, NULL);
                        PHP_CAIRO_CONTENT_T_MINIT_FUNCTION(NULL, NULL);
                        PHP_CAIRO_SURFACE_TYPE_T_MINIT_FUNCTION(NULL, NULL);
                        PHP_CAIRO_FORMAT_T_MINIT_FUNCTION(NULL, NULL);
                        PHP_CAIRO_STATUS_T_MINIT_FUNCTION(NULL, NULL);

                        PHP_CAIRO_RECTANGLE_T_MINIT_FUNCTION(&ce, NULL);
                        PHP_CAIRO_PATH_DATA_T_MINIT_FUNCTION(&ce, NULL);
                        PHP_CAIRO_PATH_T_MINIT_FUNCTION(&ce, NULL);
                        PHP_CAIRO_MATRIX_T_MINIT_FUNCTION(&ce, NULL);
                        PHP_CAIRO_SURFACE_T_MINIT_FUNCTION(&ce, NULL);
#if CAIRO_HAS_IMAGE_SURFACE
    //                    PHP_CAIRO_FORMAT_T_MINIT_FUNCTION(NULL, NULL);
    //                    PHP_CAIRO_IMAGE_SURFACE_MINIT_FUNCTION(NULL, NULL);
#endif
                        PHP_CAIRO_PNG_T_MINIT_FUNCTION(NULL, NULL);
#if CAIRO_VERSION >= 11600
    //                    PHP_CAIRO_PDF_METADATA_T_MINIT_FUNCTION(NULL, NULL);
#endif

	return SUCCESS;
}
/* }}} */




/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(cairo)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/

    PHP_CAIRO_T_MSHUTDOWN_FUNCTION();

    PHP_CAIRO_ANTIALIAS_T_MSHUTDOWN_FUNCTION();
    PHP_CAIRO_FILL_RULE_T_MSHUTDOWN_FUNCTION();
    PHP_CAIRO_LINE_CAP_T_MSHUTDOWN_FUNCTION();
    PHP_CAIRO_LINE_JOIN_T_MSHUTDOWN_FUNCTION();
    PHP_CAIRO_OPERATOR_T_MSHUTDOWN_FUNCTION();
    PHP_CAIRO_PATH_DATA_TYPE_T_MSHUTDOWN_FUNCTION();
    PHP_CAIRO_EXTEND_T_MSHUTDOWN_FUNCTION();
    PHP_CAIRO_FILTER_T_MSHUTDOWN_FUNCTION();
    PHP_CAIRO_PATTERN_TYPE_T_MSHUTDOWN_FUNCTION();
    PHP_CAIRO_REGION_OVERLAP_T_MSHUTDOWN_FUNCTION();
    PHP_CAIRO_FONT_SLANT_T_MSHUTDOWN_FUNCTION();
    PHP_CAIRO_FONT_WEIGHT_T_MSHUTDOWN_FUNCTION();
    PHP_CAIRO_TEXT_CLUSTER_FLAGS_T_MSHUTDOWN_FUNCTION();
    PHP_CAIRO_FONT_TYPE_T_MSHUTDOWN_FUNCTION();
    PHP_CAIRO_SUBPIXEL_ORDER_T_MSHUTDOWN_FUNCTION();
    PHP_CAIRO_HINT_STYLE_T_MSHUTDOWN_FUNCTION();
    PHP_CAIRO_HINT_METRICS_T_MSHUTDOWN_FUNCTION();
    PHP_CAIRO_DEVICE_TYPE_T_MSHUTDOWN_FUNCTION();
    PHP_CAIRO_CONTENT_T_MSHUTDOWN_FUNCTION();
    PHP_CAIRO_SURFACE_TYPE_T_MSHUTDOWN_FUNCTION();
    PHP_CAIRO_FORMAT_T_MSHUTDOWN_FUNCTION();
    PHP_CAIRO_STATUS_T_MSHUTDOWN_FUNCTION();

    PHP_CAIRO_RECTANGLE_T_MSHUTDOWN_FUNCTION();
    PHP_CAIRO_PATH_DATA_T_MSHUTDOWN_FUNCTION();
    PHP_CAIRO_PATH_T_MSHUTDOWN_FUNCTION();
    PHP_CAIRO_MATRIX_T_MSHUTDOWN_FUNCTION();
    PHP_CAIRO_SURFACE_T_MSHUTDOWN_FUNCTION();
#if CAIRO_HAS_IMAGE_SURFACE
    //PHP_CAIRO_FORMAT_T_MSHUTDOWN_FUNCTION();
    //PHP_CAIRO_IMAGE_SURFACE_MSHUTDOWN_FUNCTION();
#endif
    PHP_CAIRO_PNG_T_MSHUTDOWN_FUNCTION();
#if CAIRO_VERSION >= 11600
    //PHP_CAIRO_PDF_METADATA_T_MSHUTDOWN_FUNCTION(NULL, NULL);
#endif

    //zend_hash_destroy(&php_glib_object_handlers);
    zend_hash_destroy(&classes);

	return SUCCESS;
}
/* }}} */


/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(cairo)
{
#if defined(COMPILE_DL_CAIRO) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(cairo)
{

    PHP_CAIRO_T_RSHUTDOWN_FUNCTION();

    PHP_CAIRO_ANTIALIAS_T_RSHUTDOWN_FUNCTION();
    PHP_CAIRO_FILL_RULE_T_RSHUTDOWN_FUNCTION();
    PHP_CAIRO_LINE_CAP_T_RSHUTDOWN_FUNCTION();
    PHP_CAIRO_LINE_JOIN_T_RSHUTDOWN_FUNCTION();
    PHP_CAIRO_OPERATOR_T_RSHUTDOWN_FUNCTION();
    PHP_CAIRO_PATH_DATA_TYPE_T_RSHUTDOWN_FUNCTION();
    PHP_CAIRO_EXTEND_T_RSHUTDOWN_FUNCTION();
    PHP_CAIRO_FILTER_T_RSHUTDOWN_FUNCTION();
    PHP_CAIRO_PATTERN_TYPE_T_RSHUTDOWN_FUNCTION();
    PHP_CAIRO_REGION_OVERLAP_T_RSHUTDOWN_FUNCTION();
    PHP_CAIRO_FONT_SLANT_T_RSHUTDOWN_FUNCTION();
    PHP_CAIRO_FONT_WEIGHT_T_RSHUTDOWN_FUNCTION();
    PHP_CAIRO_TEXT_CLUSTER_FLAGS_T_RSHUTDOWN_FUNCTION();
    PHP_CAIRO_FONT_TYPE_T_RSHUTDOWN_FUNCTION();
    PHP_CAIRO_SUBPIXEL_ORDER_T_RSHUTDOWN_FUNCTION();
    PHP_CAIRO_HINT_STYLE_T_RSHUTDOWN_FUNCTION();
    PHP_CAIRO_HINT_METRICS_T_RSHUTDOWN_FUNCTION();
    PHP_CAIRO_DEVICE_TYPE_T_RSHUTDOWN_FUNCTION();
    PHP_CAIRO_CONTENT_T_RSHUTDOWN_FUNCTION();
    PHP_CAIRO_SURFACE_TYPE_T_RSHUTDOWN_FUNCTION();
    PHP_CAIRO_FORMAT_T_RSHUTDOWN_FUNCTION();
    PHP_CAIRO_STATUS_T_RSHUTDOWN_FUNCTION();

    PHP_CAIRO_RECTANGLE_T_RSHUTDOWN_FUNCTION();
    //PHP_CAIRO_PATH_DATA_TYPE_T_RSHUTDOWN_FUNCTION();
    PHP_CAIRO_PATH_DATA_T_RSHUTDOWN_FUNCTION();
    PHP_CAIRO_PATH_T_RSHUTDOWN_FUNCTION();
    PHP_CAIRO_MATRIX_T_RSHUTDOWN_FUNCTION();
    PHP_CAIRO_SURFACE_T_RSHUTDOWN_FUNCTION();
#if CAIRO_HAS_IMAGE_SURFACE
    //PHP_CAIRO_FORMAT_T_RSHUTDOWN_FUNCTION();
    //PHP_CAIRO_IMAGE_SURFACE_RSHUTDOWN_FUNCTION();
#endif
    PHP_CAIRO_PNG_T_RSHUTDOWN_FUNCTION();
#if CAIRO_VERSION >= 11600
    //PHP_CAIRO_PDF_METADATA_T_RSHUTDOWN_FUNCTION(NULL, NULL);
#endif

    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(cairo)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "Cairo support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


/* {{{ gtk_functions[]
 *
 * Every user visible function must have an entry in gtk_functions[].
 */
const zend_function_entry cairo_functions[] = {
    PHP_CAIRO_T_FE()
    PHP_CAIRO_ANTIALIAS_T_FE()
    PHP_CAIRO_FILL_RULE_T_FE()
    PHP_CAIRO_LINE_CAP_T_FE()
    PHP_CAIRO_LINE_JOIN_T_FE()
    PHP_CAIRO_OPERATOR_T_FE()
    PHP_CAIRO_PATH_DATA_TYPE_T_FE()
    PHP_CAIRO_EXTEND_T_FE()
    PHP_CAIRO_FILTER_T_FE()
    PHP_CAIRO_PATTERN_TYPE_T_FE()
    PHP_CAIRO_REGION_OVERLAP_T_FE()
    PHP_CAIRO_FONT_SLANT_T_FE()
    PHP_CAIRO_FONT_WEIGHT_T_FE()
    PHP_CAIRO_TEXT_CLUSTER_FLAGS_T_FE()
    PHP_CAIRO_FONT_TYPE_T_FE()
    PHP_CAIRO_SUBPIXEL_ORDER_T_FE()
    PHP_CAIRO_HINT_STYLE_T_FE()
    PHP_CAIRO_HINT_METRICS_T_FE()
    PHP_CAIRO_DEVICE_TYPE_T_FE()
    PHP_CAIRO_CONTENT_T_FE()
    PHP_CAIRO_SURFACE_TYPE_T_FE()
    PHP_CAIRO_FORMAT_T_FE()
    PHP_CAIRO_STATUS_T_FE()
    PHP_CAIRO_RECTANGLE_T_FE()
    PHP_CAIRO_PATH_DATA_T_FE()
    PHP_CAIRO_PATH_T_FE()
    PHP_CAIRO_MATRIX_T_FE()
    PHP_CAIRO_SURFACE_T_FE()
#if CAIRO_HAS_IMAGE_SURFACE
    //PHP_CAIRO_FORMAT_T_FE()
    PHP_CAIRO_IMAGE_SURFACE_FE()
#endif
    PHP_CAIRO_PNG_T_FE()
#if CAIRO_VERSION >= 11600
    //PHP_CAIRO_PDF_METADATA_T_FE(NULL, NULL);
#endif

    PHP_FE_END	/* Must be the last line in cairo_functions[] */
};
/* }}} */



/* {{{ cairo_module_entry
 */
zend_module_entry cairo_module_entry = {
	STANDARD_MODULE_HEADER,
	"cairo",
	cairo_functions,
        PHP_MINIT(cairo),// zm_startup_cairo callback
	PHP_MSHUTDOWN(cairo),
	PHP_RINIT(cairo),	/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(cairo),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(cairo),
	PHP_CAIRO_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/*}}} */



#ifdef COMPILE_DL_CAIRO
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(cairo)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */


