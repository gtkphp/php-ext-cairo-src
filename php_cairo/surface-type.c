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
#include "php_cairo/surface-type.h"


extern HashTable         classes;
extern zend_module_entry cairo_module_entry;



/*----------------------------------------------------------------------+
 | PHP_MINIT                                                            |
 +----------------------------------------------------------------------*/

 /*{{{ php_cairo_surface_type_t_class_init */
zend_class_entry*
php_cairo_surface_type_t_class_init(zend_class_entry *container_ce, zend_class_entry *parent_ce) {

    zend_register_long_constant("CAIRO_SURFACE_TYPE_IMAGE", sizeof("CAIRO_SURFACE_TYPE_IMAGE")-1,
        CAIRO_SURFACE_TYPE_IMAGE, CONST_CS | CONST_PERSISTENT, cairo_module_entry.module_number);
    zend_register_long_constant("CAIRO_SURFACE_TYPE_PDF", sizeof("CAIRO_SURFACE_TYPE_PDF")-1,
        CAIRO_SURFACE_TYPE_PDF, CONST_CS | CONST_PERSISTENT, cairo_module_entry.module_number);
    zend_register_long_constant("CAIRO_SURFACE_TYPE_PS", sizeof("CAIRO_SURFACE_TYPE_PS")-1,
        CAIRO_SURFACE_TYPE_PS, CONST_CS | CONST_PERSISTENT, cairo_module_entry.module_number);
    zend_register_long_constant("CAIRO_SURFACE_TYPE_XLIB", sizeof("CAIRO_SURFACE_TYPE_XLIB")-1,
        CAIRO_SURFACE_TYPE_XLIB, CONST_CS | CONST_PERSISTENT, cairo_module_entry.module_number);
    zend_register_long_constant("CAIRO_SURFACE_TYPE_XCB", sizeof("CAIRO_SURFACE_TYPE_XCB")-1,
        CAIRO_SURFACE_TYPE_XCB, CONST_CS | CONST_PERSISTENT, cairo_module_entry.module_number);
    zend_register_long_constant("CAIRO_SURFACE_TYPE_GLITZ", sizeof("CAIRO_SURFACE_TYPE_GLITZ")-1,
        CAIRO_SURFACE_TYPE_GLITZ, CONST_CS | CONST_PERSISTENT, cairo_module_entry.module_number);
    zend_register_long_constant("CAIRO_SURFACE_TYPE_QUARTZ", sizeof("CAIRO_SURFACE_TYPE_QUARTZ")-1,
        CAIRO_SURFACE_TYPE_QUARTZ, CONST_CS | CONST_PERSISTENT, cairo_module_entry.module_number);
    zend_register_long_constant("CAIRO_SURFACE_TYPE_WIN32", sizeof("CAIRO_SURFACE_TYPE_WIN32")-1,
        CAIRO_SURFACE_TYPE_WIN32, CONST_CS | CONST_PERSISTENT, cairo_module_entry.module_number);
    zend_register_long_constant("CAIRO_SURFACE_TYPE_BEOS", sizeof("CAIRO_SURFACE_TYPE_BEOS")-1,
        CAIRO_SURFACE_TYPE_BEOS, CONST_CS | CONST_PERSISTENT, cairo_module_entry.module_number);
    zend_register_long_constant("CAIRO_SURFACE_TYPE_DIRECTFB", sizeof("CAIRO_SURFACE_TYPE_DIRECTFB")-1,
        CAIRO_SURFACE_TYPE_DIRECTFB, CONST_CS | CONST_PERSISTENT, cairo_module_entry.module_number);
    zend_register_long_constant("CAIRO_SURFACE_TYPE_SVG", sizeof("CAIRO_SURFACE_TYPE_SVG")-1,
        CAIRO_SURFACE_TYPE_SVG, CONST_CS | CONST_PERSISTENT, cairo_module_entry.module_number);
    zend_register_long_constant("CAIRO_SURFACE_TYPE_OS2", sizeof("CAIRO_SURFACE_TYPE_OS2")-1,
        CAIRO_SURFACE_TYPE_OS2, CONST_CS | CONST_PERSISTENT, cairo_module_entry.module_number);
    zend_register_long_constant("CAIRO_SURFACE_TYPE_WIN32_PRINTING", sizeof("CAIRO_SURFACE_TYPE_WIN32_PRINTING")-1,
        CAIRO_SURFACE_TYPE_WIN32_PRINTING, CONST_CS | CONST_PERSISTENT, cairo_module_entry.module_number);
    zend_register_long_constant("CAIRO_SURFACE_TYPE_QUARTZ_IMAGE", sizeof("CAIRO_SURFACE_TYPE_QUARTZ_IMAGE")-1,
        CAIRO_SURFACE_TYPE_QUARTZ_IMAGE, CONST_CS | CONST_PERSISTENT, cairo_module_entry.module_number);
    zend_register_long_constant("CAIRO_SURFACE_TYPE_SCRIPT", sizeof("CAIRO_SURFACE_TYPE_SCRIPT")-1,
        CAIRO_SURFACE_TYPE_SCRIPT, CONST_CS | CONST_PERSISTENT, cairo_module_entry.module_number);
    zend_register_long_constant("CAIRO_SURFACE_TYPE_QT", sizeof("CAIRO_SURFACE_TYPE_QT")-1,
        CAIRO_SURFACE_TYPE_QT, CONST_CS | CONST_PERSISTENT, cairo_module_entry.module_number);
    zend_register_long_constant("CAIRO_SURFACE_TYPE_RECORDING", sizeof("CAIRO_SURFACE_TYPE_RECORDING")-1,
        CAIRO_SURFACE_TYPE_RECORDING, CONST_CS | CONST_PERSISTENT, cairo_module_entry.module_number);
    zend_register_long_constant("CAIRO_SURFACE_TYPE_VG", sizeof("CAIRO_SURFACE_TYPE_VG")-1,
        CAIRO_SURFACE_TYPE_VG, CONST_CS | CONST_PERSISTENT, cairo_module_entry.module_number);
    zend_register_long_constant("CAIRO_SURFACE_TYPE_GL", sizeof("CAIRO_SURFACE_TYPE_GL")-1,
        CAIRO_SURFACE_TYPE_GL, CONST_CS | CONST_PERSISTENT, cairo_module_entry.module_number);
    zend_register_long_constant("CAIRO_SURFACE_TYPE_DRM", sizeof("CAIRO_SURFACE_TYPE_DRM")-1,
        CAIRO_SURFACE_TYPE_DRM, CONST_CS | CONST_PERSISTENT, cairo_module_entry.module_number);
    zend_register_long_constant("CAIRO_SURFACE_TYPE_TEE", sizeof("CAIRO_SURFACE_TYPE_TEE")-1,
        CAIRO_SURFACE_TYPE_TEE, CONST_CS | CONST_PERSISTENT, cairo_module_entry.module_number);
    zend_register_long_constant("CAIRO_SURFACE_TYPE_XML", sizeof("CAIRO_SURFACE_TYPE_XML")-1,
        CAIRO_SURFACE_TYPE_XML, CONST_CS | CONST_PERSISTENT, cairo_module_entry.module_number);
    zend_register_long_constant("CAIRO_SURFACE_TYPE_SKIA", sizeof("CAIRO_SURFACE_TYPE_SKIA")-1,
        CAIRO_SURFACE_TYPE_SKIA, CONST_CS | CONST_PERSISTENT, cairo_module_entry.module_number);
    zend_register_long_constant("CAIRO_SURFACE_TYPE_SUBSURFACE", sizeof("CAIRO_SURFACE_TYPE_SUBSURFACE")-1,
        CAIRO_SURFACE_TYPE_SUBSURFACE, CONST_CS | CONST_PERSISTENT, cairo_module_entry.module_number);
    zend_register_long_constant("CAIRO_SURFACE_TYPE_COGL", sizeof("CAIRO_SURFACE_TYPE_COGL")-1,
        CAIRO_SURFACE_TYPE_COGL, CONST_CS | CONST_PERSISTENT, cairo_module_entry.module_number);

    return NULL;
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
