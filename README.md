Sublime C Improved
================

This package provides better support of C/C++/Objective-C languages in Sublime Text.
It addresses some issues with macro syntax highlighting and symbol list being populated incorrectly.

Issues addressed
--

### Function call inside macro recognized as a symbol definition
In the following example ST recognizes `check_range(...)` inside a macro as a function definition though it is actually a function call.
This leads to incorrect highlighting (green instead of blue) and also adds a bogus symbol into a symbol list.
Moreover a function declaration which follows the macro (`int irq_attach(...)`) is not recognized at all.

Standard C | C Improved
---------- | ----------
![Standard C macro symbols](http://habrastorage.org/storage3/3dc/b35/687/3dcb356871830161a5f4c01c8a762287.png) | ![C Improved macro symbols](http://habrastorage.org/storage3/903/10c/4bb/90310c4bb046fd14b6b928772e6a034e.png)

### Macro parameters highlighting

Standard C | C Improved
---------- | ----------
![Standard C macro parameters](http://habrastorage.org/storage3/0f2/5d8/dbe/0f25d8dbedde773b611b3c50c0662416.png) | ![C Improved macro parameters](http://habrastorage.org/storage3/3c4/6e4/3cd/3c46e43cd104dd7ae58cc42e65ad7176.png)
