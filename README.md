# EAC Log Signer in C

This is just a C reimplementation of the original [EAC Log Signer](https://github.com/puddly/eac_logsigner), which is
implemented in Python.

# Usage
It's very simple. You're supposed to pass the names of the logs that you want to
inspect, and the program will output one line per every file specified. The
output varies according to whether the verification passed or not, and whether
the log had a checksum attached to it in the first place :

```
[foo@bar eac-cksum]$ ./eac-cksum test/bad.log test/good.log test/no-checksum.log
test/bad.log : NOK, computed F4C01D8CECBE2EE0C942EA7F8E8E937B24369680F70B221F9B681BC84E400638
test/good.log : OK
test/no-checksum.log : F4C01D8CECBE2EE0C942EA7F8E8E937B24369680F70B221F9B681BC84E400638
```

# Legal
This code contains parts of the [EAC Log Signer](https://github.com/puddly/eac_logsigner),
licensed as follows :

```
MIT License

Copyright (c) 2017 puddly

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
