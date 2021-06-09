/*
+----------------------------------------------------------------------+
| PHP Version 8                                                        |
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
| Author: No Name                                                      |
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

#include "php_cairo/rectangle.h"


extern HashTable         classes;
extern zend_module_entry cairo_module_entry;


zend_class_entry     *php_cairo_rectangle_t_class_entry;// struct
zend_object_handlers  php_cairo_rectangle_t_handlers;




enum _php_cairo_rectangle_t_properties {
    PHP_CAIRO_RECTANGLE_T_X = 1,
    PHP_CAIRO_RECTANGLE_T_Y = 2,
    PHP_CAIRO_RECTANGLE_T_WIDTH = 3,
    PHP_CAIRO_RECTANGLE_T_HEIGHT = 4
};
//typedef enum php_cairo_rectangle_t_properties php_cairo_rectangle_t_properties;



/*----------------------------------------------------------------------+
 | Internal                                                             |
 +----------------------------------------------------------------------*/

static const zend_function_entry
php_cairo_rectangle_t_methods[] = {
    PHP_ME(cairo_rectangle_t, __construct, arginfo_cairo_rectangle_t___construct, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

/*----------------------------------------------------------------------+
 | Zend Handler                                                         |
 +----------------------------------------------------------------------*/

/* {{{ php_cairo_rectangle_t_create_object */
static zend_object*
php_cairo_rectangle_t_create_object(zend_class_entry *class_type)
{
    php_cairo_rectangle_t *intern = ecalloc(1, sizeof(php_cairo_rectangle_t) + zend_object_properties_size(class_type));

    zend_object_std_init(&intern->std, class_type);
    object_properties_init(&intern->std, class_type);


    ZVAL_DOUBLE(&intern->x, 0.0);
    ZVAL_DOUBLE(&intern->y, 0.0);
    ZVAL_DOUBLE(&intern->width, 0.0);
    ZVAL_DOUBLE(&intern->height, 0.0);

    intern->std.handlers = &php_cairo_rectangle_t_handlers;

    return &intern->std;
}
/* }}} php_cairo_rectangle_t_create_object */


static void
php_cairo_rectangle_t_dtor_object(zend_object *obj) {
    //php_cairo_rectangle_t *intern = ZOBJ_TO_PHP_CAIRO_RECTANGLE_T(obj);

}

/* {{{ php_cairo_rectangle_t_free_object */
static void
php_cairo_rectangle_t_free_object(zend_object *object)
{
    php_cairo_rectangle_t *intern = ZOBJ_TO_PHP_CAIRO_RECTANGLE_T(object);

    Z_TRY_DELREF(intern->x);
    Z_TRY_DELREF(intern->y);
    Z_TRY_DELREF(intern->width);
    Z_TRY_DELREF(intern->height);

    zend_object_std_dtor(&intern->std);
}
/* }}} php_cairo_rectangle_t_free_object */








static zend_object_handlers*
php_cairo_rectangle_t_get_handlers()
{
    memcpy(&php_cairo_rectangle_t_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    php_cairo_rectangle_t_handlers.offset = PHP_CAIRO_RECTANGLE_T_OFFSET;
    php_cairo_rectangle_t_handlers.dtor_obj = php_cairo_rectangle_t_dtor_object;
    php_cairo_rectangle_t_handlers.free_obj = php_cairo_rectangle_t_free_object;

    /*
    php_cairo_rectangle_t_handlers.read_property = php_cairo_rectangle_t_read_property;
    php_cairo_rectangle_t_handlers.write_property = php_cairo_rectangle_t_write_property;
    php_cairo_rectangle_t_handlers.get_property_ptr_ptr = php_cairo_rectangle_t_get_property_ptr_ptr;

    php_cairo_rectangle_t_handlers.get_debug_info = php_cairo_rectangle_t_get_debug_info;
    */


    return &php_cairo_rectangle_t_handlers;
}

/*----------------------------------------------------------------------+
 | PHP_MINIT                                                            |
 +----------------------------------------------------------------------*/

 /*{{{ php_cairo_rectangle_t_class_init */
zend_class_entry*
php_cairo_rectangle_t_class_init(zend_class_entry *container_ce, zend_class_entry *parent_ce) {
    php_cairo_rectangle_t_get_handlers();

    INIT_CLASS_ENTRY((*container_ce), "cairo_rectangle_t", php_cairo_rectangle_t_methods);
    php_cairo_rectangle_t_class_entry = zend_register_internal_class_ex(container_ce, parent_ce);
    php_cairo_rectangle_t_class_entry->create_object = php_cairo_rectangle_t_create_object;


    /*
    zval property_intProp_default_value;
    ZVAL_LONG(&property_intProp_default_value, 123);
    zend_string *property_intProp_name = zend_string_init("intProp", sizeof("intProp") - 1, 1);
    zend_declare_typed_property(php_cairo_rectangle_t_class_entry,
                                property_intProp_name,
                                &property_intProp_default_value,
                                ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
    zend_string_release(property_intProp_name);
    */
    zend_declare_property_long(php_cairo_rectangle_t_class_entry, "intProp", sizeof("intProp")-1, 0, ZEND_ACC_PUBLIC);
    /**
    zend_hash_init(&dom_xpath_prop_handlers, 0, NULL, dom_dtor_prop_handler, 1);
    dom_register_prop_handler(&dom_xpath_prop_handlers, "document", dom_xpath_document_read, NULL);
    //zend_hash_str_add_mem(prop_handler, name, strlen(name), &hnd, 
    zend_hash_add_ptr(&classes, ce.name, &dom_xpath_prop_handlers);
    */


    //zend_std_write_property()



    return php_cairo_rectangle_t_class_entry;
}/*}}} */

/*----------------------------------------------------------------------+
 | Zend-User utils                                                      |
 +----------------------------------------------------------------------*/

/*----------------------------------------------------------------------+
 | Zend-User API                                                        |
 +----------------------------------------------------------------------*/

/*----------------------------------------------------------------------+
 | PHP_METHOD                                                           |
 +----------------------------------------------------------------------*/

 /* {{{ cairo_rectangle_t::__construct() */
PHP_METHOD(cairo_rectangle_t, __construct)
{
    //zend_object *zobj = Z_OBJ_P(getThis());
    //php_cairo_rectangle_t *self = ZOBJ_TO_PHP_CAIRO_RECTANGLE_T(zobj);


}
/* }}} */

/*----------------------------------------------------------------------+
 | PHP_FUNCTION                                                         |
 +----------------------------------------------------------------------*/


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
