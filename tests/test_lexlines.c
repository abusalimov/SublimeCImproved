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
comment
#endif

#if 0 // comment
comment
#endif

#if /*1*/0
comment
#endif

#if 0+1
REGULAR LINE
#endif

#if 0
comment
#if 0
#if 0
#define COMMENT
#endif
#define COMMENT
comment
#endif
#endif

#if 0
comment
#endif_comment
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

// === Task tags examples ===

/*
 * My awesome structure.
 * More docs TBD -- Eldar */
struct aww {}; // NOTE really awesome, but still empty
               // new comment line      \
               // and TODO continuation \
               // still the same comment line
               // simple multiline comment   \
                  Hey you! FIXME -- PF       \
                  Just another brick in the wall

// XXX move to a header
extern int barf(void);

#pragma mark MAIN

int main(int argc, char const *argv[])
{
	mode_t mode;
	mode = S_IFBLK; // XXX this should be an argument
	mode |= S_IRALL | S_IWALL; // TODO umask. -- Eldar
	return 0;
}
