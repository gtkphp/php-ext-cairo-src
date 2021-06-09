--TEST--
Check if cairo is loaded
--EXTENSIONS--
cairo
--FILE--
<?php
echo 'The extension "cairo" is available';
?>
--EXPECT--
The extension "cairo" is available
