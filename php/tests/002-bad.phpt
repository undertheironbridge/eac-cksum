--TEST--
Check if verifying an invalid log produces 0
--SKIPIF--
<?php if (!extension_loaded("eaccksum")) print "skip"; ?>
--FILE--
<?php 
echo \eaccksum\verify("../test/bad.log");
?>
--EXPECT--
0
