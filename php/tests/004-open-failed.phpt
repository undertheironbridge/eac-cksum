--TEST--
Check if verifying a file which doesn't exist produces -1
--SKIPIF--
<?php if (!extension_loaded("eaccksum")) print "skip"; ?>
--FILE--
<?php 
echo \eaccksum\verify("iamnothere.log");
?>
--EXPECT--
-1
