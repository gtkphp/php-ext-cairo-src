--TEST--
cairo_test2() Basic test
--EXTENSIONS--
cairo
--FILE--
<?php
var_dump(cairo_test2());
var_dump(cairo_test2('PHP'));
?>
--EXPECT--
string(11) "Hello World"
string(9) "Hello PHP"
