struct name { };

struct name {
};
struct /* comment */ name /* comment */ { };

struct name
{ };
struct name \
{ };
struct /* comment */ name // comment
{ };

/* type-definition inside parens and block. */
void function(struct name {} arg);
void function(struct /* comment */ name /* comment */ { } arg) {
	struct name { };
	struct name
	{ };
	struct name \
	{ };
	struct /* comment */ name // comment
	{ };
}

struct name *
create_struct(void) { }


/* FALSE POSITIVES */

struct name
create_struct(void);

struct name
create_struct(void) { }

struct name  // the compound meta block shouldn't span
create_struct(void) { }

struct __packed __aligned(16) name { };  // function __aligned
