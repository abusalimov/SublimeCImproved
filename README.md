Sublime C Improved
================

This package provides better support of C/C++/Objective-C languages in Sublime Text.

It is primarily focused on pure C overriding a standard syntax definition shipped with Sublime Text, though once installed it affects other C-family languages as well. Note that C Improved per se provides only the syntax definition among with some symbol indexing settings, nothing more. That is, it is not a self-sustained package, but only an addition (improvement) to the standard C++ package.

What is improved?
---
Most of C Improved features tend to facilitate everyday C development experience. This varies from enabling highlighting of operators to more complex enhancements listed below.

### Preprocessor issues
C preprocessor directives are relatively simple to parse (even with regular expressions, to some extent). And so related issues were addressed first of all.

#### Macro highlighting and error handling
Macro parameters (including variadic arguments) and argument stringification now have proper highlighting with handling of some common syntax errors.

Here is an example of two more or less complex multi-line macros.

Standard C | C Improved
---------- | ----------
![Standard C macros](http://habrastorage.org/files/197/00b/a8d/19700ba8de834a08bd49775445e8233c.png) | ![C Improved macros](http://habrastorage.org/files/887/6fd/a09/8876fda0950b438883a694dc08a04b94.png)

And below is a result of commenting out a `msg...` vararg (but missing a preceding comma outside the comment) and accidentally putting tabs after some line continuation backslashes.

Standard C | C Improved
---------- | ----------
![Standard C macros](http://habrastorage.org/files/bf3/7ca/649/bf37ca6495ab46cb932b1116561c941b.png) | ![C Improved macros](http://habrastorage.org/files/d89/d63/582/d89d63582d344b8891e712026417707f.png)

Both errors are ignored by the standard package, while C Improved highlights a premature closing paren in the first case as an error, and warns about trailing whitespaces after the backslashes (the second one is immediately followed by an error complaining about an unexpected EOL within macro parameters). See an [issue](//github.com/abusalimov/SublimeCImproved/issues/7) about `space-after-continuation` highlighting.

#### Macro innards
A macro body (with proper line continuations, if needed) is not able to contribute to the symbol index anymore, nor it can interfere with a code surrounding the macro, or anyhow break syntax highlighting.

Standard C | C Improved
---------- | ----------
![Standard C macro symbols](http://habrastorage.org/storage3/9ab/a6c/99c/9aba6c99c480b90e7cfb1a841f550787.png) | ![C Improved macro symbols](http://habrastorage.org/storage3/46a/476/c85/46a476c85af7ff8feb6395d4dfdb96ba.png)

In this example the standard C package recognizes `check_range(...)` inside a macro as a function definition though it is actually a function call.
This leads to incorrect highlighting and also adds a bogus symbol into the symbol list.
Moreover, a function declaration which follows the macro (`int irq_attach(...)`) is not recognized at all.

#### Scopes for preprocessor directives
All preprocessor directives provide a proper *scope* now (`meta.preprocessor`), which means that you can select a whole macro with <kbd>ctrl</kbd>+<kbd>shift</kbd>+<kbd>space</kbd> or <kbd>⌘</kbd>+<kbd>⇧</kbd>+<kbd>space</kbd>. It also allows, for instance, the whole macro body to be styled differently (this is up to a color scheme though).


### Support for significant projects
The standard C package provides a special support for functions from C standard library and POSIX. For example, a `printf` function is highlighted differently.

However, most of major software projects implemented in C have their own internal libraries/frameworks and use some established patterns and idioms all across their sources. This includes not only a set of commonly used functions and types; there could be a handful macro for defining some object, a special kind of function attribute/annotation, etc.

If you use Sublime Text for developing some of the following projects, you should find these improvements rather useful.

#### Linux kernel source
This adds a special handling of some common macros widely used across the kernel source code, like `EXPORT_SYMBOL`, `LIST_HEAD` or `DEFINE_XXX`,
which would otherwise be recognized as functions thus polluting a symbol index and an outline.

Standard C | C Improved
---------- | ----------
![Standard C linux support](http://habrastorage.org/storage3/c7b/b01/316/c7bb01316e29e0994ec32aa212911a37.png) | ![C Improved linux support](http://habrastorage.org/storage3/024/daa/2ac/024daa2acbc19b9d6060faf59b23d12b.png)

#### Windows drivers
Provides special highlighting for SAL function annotations listed [here](http://msdn.microsoft.com/en-us/library/windows/hardware/hh454237.aspx) (related [issue](//github.com/abusalimov/SublimeCImproved/issues/2)).

#### CPython interpreter source
This includes:

  - Highlighing of Python-related constants (like `PyTrue` or `PyFalse`) and main data structures (`PyObject`, `PyTypeObject`, `PyListObject`, etc.)
  - Widely used `PyMODINIT_FUNC`, `PyAPI_FUNC(...)` and `Py_LOCAL(...)` function annotation. This sanitizes higlighting of annotated functions and the symbol index
  - Special highlighting of `PyId_xxx` interned static string literals defined with `_Py_IDENTIFIER(...)` macro
  - Well-marked highlighting of macros involving transfer of control (like `Py_RETURN_NONE`).


Standard C | C Improved
---------- | ----------
![Standard C CPython support](http://habrastorage.org/files/e6b/717/906/e6b71790670e4500b24de764db1bf7dd.png) | ![C Improved CPython support](http://habrastorage.org/files/1e0/1f1/f5e/1e01f1f5e7fd4e14a1fc3bc504896744.png)

### Customizable indexing of types/functions/macros
You can adjust which symbols are available for navigation and visible in a symbol index or in an outline.

The following scopes and default preferences are provided:

Scope name | Description | Outline<br/><kbd>ctrl</kbd>+<kbd>R</kbd> | Index (ST3) <kbd>F12</kbd><br/><kbd>ctrl</kbd>+<kbd>shift</kbd>+<kbd>R</kbd>
----------------------------------- | ----------------------------- | ------- | -------
`entity.name.type`                  | compound type                 | visible | visible
`entity.name.type.declaration`      | forward declaration of a type | visible | **hidden**
`entity.name.type.typedef`          | type alias (`typedef`)        | visible | visible
`entity.name.function`              | function definition           | visible | visible
`entity.name.function.declaration`  | function declaration          | visible | **hidden**
`entity.name.function.preprocessor` | function-like macro           | visible | visible
`entity.name.constant.preprocessor` | object-like macro             | visible | visible

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

Installation
---
### Package Control
With [Package Control](https://sublime.wbond.net/installation) installed:

  - Open Command Palette (<kbd>ctrl</kbd>+<kbd>shift</kbd>+<kbd>P</kbd> or <kbd>⌘</kbd>+<kbd>⇧</kbd>+<kbd>P</kbd>)
  - Select *Package Control: Install Package* (`pkginst`)
  - Search for ***C Improved*** (`cimp`) package and install it

### Manual
Locate Sublime Text `Packages` directory (*Preferences → Browse Packages...*)
and clone this repository into `C Improved`:

    git clone https://github.com/abusalimov/SublimeCImproved.git "C Improved"

Usage
---

Once installed C Improved will be used instead of the standard C syntax when opening `.c` and `.h` files, unless you have forcibly bound these extensions to something else.
In the latter case you can rebind them to be handled by C Improved through *View → Syntax → Open all with current extension as… → C Improved*.

Other languages derived from C (like C++ and Objective C) don't need their syntaxes to be changed to something special:
they usually extend `source.c` under the hood, which is now provided by C Improved syntax.

