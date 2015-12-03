/* Tests for preprocessor rules, comments, line continuations, etc.*/

#include <sys/neutrino.h>   // comment
#include <sys/mman.h>       // comment

#include <xxx.h> // comment \
	comment
REGULAR LINE

#include <xxx.h> // comment \

REGULAR LINE

#include \
<xxx.h>
<REGULAR LINE>

#define macro // comment \
	comment
#define macro() /* block comment \
	comment */ body \
#define NOT_A_NAME, still the body \
	void not_a_function(void) {}

#define exprintf(expr,         \
		/* optional */ msg...) \
	__exprintf(#expr,  \
		(int) (expr),  \
		"%s: %d\n" msg)
#define __exprintf(str_expr, \
		expr, fmt, args...)  \
	printf(fmt, \
		str_expr, expr, ##args)

#if 0
#define COMMENT
comment
#endif

// comment \
// comment \
still a comment
REGULAR LINE

// comment /* block */ comment

#assert <- DEPRECATED
#sdfasd <- INVALID
#line
