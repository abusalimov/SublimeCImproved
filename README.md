Sublime C Improved
================

This package provides better support of C/C++/Objective-C languages in Sublime Text.
It addresses some issues with macro syntax highlighting and symbol list being populated incorrectly.

C Improved vs. the standard C bundle
--
In the following example ST recognizes `check_range(...)` inside a macro as a function definition though it is actually a function call.
This leads to incorrect highlighting (green instead of blue) and also adds a bogus symbol into a symbol list.
Moreover a function declaration which follows the macro (`int irq_attach(...)`) is not recognized at all.

![Standard C syntax](http://habrastorage.org/storage3/efc/ae1/08c/efcae108c9dfd854ad70235b9da98881.png)

Syntax definition provided by C Improved makes things work as expected:

![Improved C syntax](http://habrastorage.org/storage3/994/4e7/b57/9944e7b5705d5e41f624964d252263da.png)
