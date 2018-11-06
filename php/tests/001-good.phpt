--TEST--
Check if verifying a valid log produces 1
--SKIPIF--
<?php if (!extension_loaded("eaccksum")) print "skip"; ?>
--FILE--
<?php 
echo \eaccksum\verify("../test/good.log");
?>
--EXPECT--
1
