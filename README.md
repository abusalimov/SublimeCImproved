Sublime C Improved
================

This package provides better support of C/C++/Objective-C languages in Sublime Text.

It is **not** a self-sustained package, but only an addition to the standard *C++* package supplied with Sublime Text.

Installation
---
### Package Control
With [Package Control](https://sublime.wbond.net/installation) installed:
 - Open Command Palette (<kbd>ctrl</kbd> + <kbd>shift</kbd> + <kbd>P</kbd> or <kbd>⌘</kbd> + <kbd>⇧</kbd> + <kbd>P</kbd>)
 - Select *Package Control: Install Package* (`pkginst`)
 - Search for ***C Improved*** (`cimp`) package and install it

### Manual
Locate Sublime Text `Packages` directory (*Preferences → Browse Packages...*)
and clone this repository there:

    git clone https://github.com/abusalimov/SublimeCImproved.git "C Improved"

Usage
---

Once installed *C Improved* will be used instead of the standard *C* syntax when opening `.c` and `.h` files, unless you have forcibly bound these extensions to something else.
In the latter case you can rebind them to be handled by *C Improved* through *View → Syntax → Open all with current extension as… → C Improved*.

Other languages derived from C (like C++ and Objective C) don't need their syntaxes to be changed to something special:
they usually extend `source.c` under the hood, which is now provided by *C Improved* syntax.

Issues addressed
---

### Function calls inside macros
In the following example ST recognizes `check_range(...)` inside a macro as a function definition though it is actually a function call.
This leads to incorrect highlighting (green instead of blue) and also adds a bogus symbol into a symbol list.
Moreover a function declaration which follows the macro (`int irq_attach(...)`) is not recognized at all.

Standard C | C Improved
---------- | ----------
![Standard C macro symbols](http://habrastorage.org/storage3/9ab/a6c/99c/9aba6c99c480b90e7cfb1a841f550787.png) | ![C Improved macro symbols](http://habrastorage.org/storage3/46a/476/c85/46a476c85af7ff8feb6395d4dfdb96ba.png)

### Macro scope and parameters highlighting
Macros (as well as all other preprocessor directives) provide a *scope* now (`meta.preprocessor`), which means that you can select a whole macro with <kbd>ctrl</kbd> + <kbd>shift</kbd> + <kbd>space</kbd> or <kbd>⌘</kbd> + <kbd>⇧</kbd> + <kbd>space</kbd>.
Highlighting of macro parameters (including variable arguments) is added also with handling of some related syntax errors.

Standard C | C Improved
---------- | ----------
![Standard C macro parameters](http://habrastorage.org/storage3/1f8/118/fda/1f8118fda926989ac597a36ab0466473.png) | ![C Improved macro parameters](http://habrastorage.org/storage3/f31/11a/004/f3111a004bb12c613e909eb16886f101.png)

### Linux kernel support
If you use ST for Linux kernel development, then you will probably find this fix rather useful.
It adds a special handling of some common macros widely used across the kernel source code, like `EXPORT_SYMBOL`, `LIST_HEAD` or `DEFINE_XXX`,
which would otherwise be recognized as functions thus polluting a symbol index and an outline.

Standard C | C Improved
---------- | ----------
![Standard C linux support](http://habrastorage.org/storage3/c7b/b01/316/c7bb01316e29e0994ec32aa212911a37.png) | ![C Improved linux support](http://habrastorage.org/storage3/024/daa/2ac/024daa2acbc19b9d6060faf59b23d12b.png)

### CPython interpreter support

Standard C | C Improved
---------- | ----------
![Standard C CPython support](http://habrastorage.org/files/e6b/717/906/e6b71790670e4500b24de764db1bf7dd.png) | ![C Improved CPython support](http://habrastorage.org/files/1e0/1f1/f5e/1e01f1f5e7fd4e14a1fc3bc504896744.png)

### Customizable indexing of types/functions/macros
You can adjust which symbols are available for navigation and visible in a symbol index or in an outline.

The following scopes and default preferences are provided:

Scope name | Description | Outline<br/><kbd>ctrl</kbd>+<kbd>R</kbd> | Index (ST3) <kbd>F12</kbd><br/><kbd>ctrl</kbd>+<kbd>shift</kbd>+<kbd>R</kbd>
---------- | ----------- | ---------------------------------------- | -----
`entity.name.type`                 | type definition (e.g. `struct`)         | visible | visible
`entity.name.type.declaration`     | forward declaration of a type           | visible | **hidden**
`entity.name.type.typedef`         | type alias (`typedef`)                  | visible | visible
`entity.name.function`             | function definition                     | visible | visible
`entity.name.function.declaration` | function declaration                    | visible | **hidden**
`entity.name.function.macro`       | function-like macro                     | visible | visible
`entity.name.variable.macro`       | object-like macro                       | visible | visible

These settings can be changed through `.tmPreferences` files, see `Packages/C Improved/Symbol Index (*).tmPreferences`.

Dropped features
----------------

### `#if 1 ... #else` conditionals
The standard syntax highlights recognizes `#else` part after `#if 1` conditional as a comment. This is a really nice feature, however it is rather fragile and has many issues, e.g. with unterminated blocks (opening/closing brace inside a preprocessor conditional).
So for sake of simplicity it was decided to remove it at all, leaving only a plain `#if 0` handling, which is more or less stable and has pretty straightforward implementation.

You may however checkout a [preprocessor-cond-scopes](//github.com/abusalimov/SublimeCImproved/tree/preprocessor-cond-scopes) branch which doesn't have this limitation.

### Local variable declaration/initialization
C can be quite complicated to parse in some parts, for example related to pointer declarations (what is `t * v`? Is it a simple multiplication, or a declaration of a pointer to type `t` called `v`?). Needless to say, it is just impossible to parse C using regular expressions. Therefore, C Improved doesn't try to recognize variable declarations, so there is no distinct scope/highlighting for them.

Some discussion on this can be found in a related [issue](//github.com/abusalimov/SublimeCImproved/issues/8).

