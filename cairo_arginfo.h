/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: efdd79c2c8ccff694699c86fdd6248a13839c744 */

ZEND_BEGIN_ARG_INFO(arginfo_test1, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_test2, 0)
        ZEND_ARG_TYPE_INFO(0, str, IS_STRING, 0)
ZEND_END_ARG_INFO()


ZEND_FUNCTION(test1);
ZEND_FUNCTION(test2);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(test1, arginfo_test1)
	ZEND_FE(test2, arginfo_test2)
	ZEND_FE_END
};
