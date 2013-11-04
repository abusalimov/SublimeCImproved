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

| Standard C | C Improved |
| --- | --- |
| ![Standard C macro symbols](http://habrastorage.org/storage3/446/d49/0db/446d490db58b1c6d1e314ce04da53c7f.png) | ![C Improved macro symbols](http://habrastorage.org/storage3/db6/aa2/b2e/db6aa2b2e46cb485ad75975c10f4826e.png) |

### Macro parameters highlighting

| Standard C | C Improved |
| --- | --- |
| ![Standard C macro parameters](http://habrastorage.org/storage3/887/708/83b/88770883bb8110bc92add0a5cba3e65f.png) | ![C Improved macro parameters](http://habrastorage.org/storage3/9b8/abf/4fe/9b8abf4fe1a989afa25a5afe194c9f99.png) |
