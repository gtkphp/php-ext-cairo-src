--TEST--
test1() Basic test
--EXTENSIONS--
cairo
--FILE--
<?php
$ret = test1();

var_dump($ret);
?>
--EXPECT--
The extension cairo is loaded and working!
NULL
