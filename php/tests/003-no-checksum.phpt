--TEST--
Check if verifying a log without a checksum produces 2
--SKIPIF--
<?php if (!extension_loaded("eaccksum")) print "skip"; ?>
--FILE--
<?php 
echo \eaccksum\verify("../test/no-checksum.log");
?>
--EXPECT--
2
