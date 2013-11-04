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
![Standard C macro symbols](http://habrastorage.org/storage3/9ab/a6c/99c/9aba6c99c480b90e7cfb1a841f550787.png) | ![C Improved macro symbols](http://habrastorage.org/storage3/46a/476/c85/46a476c85af7ff8feb6395d4dfdb96ba.png)

### Macro parameters highlighting

Standard C | C Improved
---------- | ----------
![Standard C macro parameters](http://habrastorage.org/storage3/1f8/118/fda/1f8118fda926989ac597a36ab0466473.png) | ![C Improved macro parameters](http://habrastorage.org/storage3/f31/11a/004/f3111a004bb12c613e909eb16886f101.png)

### Linux kernel support macros

Standard C | C Improved
---------- | ----------
![Standard C macro parameters](http://habrastorage.org/storage3/c7b/b01/316/c7bb01316e29e0994ec32aa212911a37.png) | ![C Improved macro parameters](http://habrastorage.org/storage3/024/daa/2ac/024daa2acbc19b9d6060faf59b23d12b.png)
