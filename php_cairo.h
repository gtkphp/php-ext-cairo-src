/* cairo extension for PHP */

#ifndef PHP_CAIRO_H
# define PHP_CAIRO_H

extern zend_module_entry cairo_module_entry;
# define phpext_cairo_ptr &cairo_module_entry

# define PHP_CAIRO_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_CAIRO)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_CAIRO_H */
