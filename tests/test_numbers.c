/**
 * Test numeric literals: both integers and floats.
 */

int main(int argc, char const *argv[])
{
	GOOD = {
		/* zeroes */
		0,
		0.0l,
		.0,
		0.f,
		0UL,
		0x0ull,

		/* decimal integers */
		42,
		-123,

		/* GNU C binary literals */
		0b100110,
		0b100110ul,

		/* hexadecimal integers */
		0xFF,
		0xcf400000ul,
		0xFull,
		0xC0FFEE,
		0xdeadbeef,

		/* octal integers */
		0777,
		0123l,  // long

		089e3l,  // but: decimal float

		/* decimal floats */
		3.1415926,
		.015625,
		7e5,  // 7.0 * 10^5
		7.3,
		7.3E+5,
		7.E+5,
		.3E+5f,
		7.3e5l,  // long double

		7.3+E,  // a sum, i.e. 7.3 + E
		7.3+5,  // also a sum

		/* hexadecimal floats */
		0x7.0p5,  // 7.0 * 2^5
		0xcf7p5,
		0xcc.dp-11,
		0x13p-10,
	};

	BAD = {
		0x7A.3,
		0x7A.3E-.5,
		0x7A.3E-5.,
		0x7A.3E-5.0,
		0x7A.,
		0x7s.,
		0x7A.p,
		0x7.3df,
		0x7.3dl,
		0x7.3sdsdsdf,
		0x7.3e1sdf,
		0x7.3p,
		0x7.3ppl,
		0x7s7s7d3.3dsdfsdp1.2df3l,
		0x7.3,
		0x7.3p-5u,
		0x7.3p-5.0,
		0x7.3p5.0,
		0x7.3p,
		0x7.3pe,
		0x7p,
		0xp,
		0x.,
		0x.p,
		0x.p1,
		07.3p5,
		07.3p+5,
		07.3e+Du,
		07.3e+Eu,
		07.3p+Eu,
		07.3p1,
		7e5fu,
		7.3uf,
		7f.3u,
		7f.3f,
		7f.3fu,
		7.3uf,
		0293ull,
		029e3ull,
		029f3ull,
		029g3ull,
		0293ulql,
		0xA293sull,
		0xA29g3ull,
		0xA293q2ll,
		0xA293uqll,
		0xA293ulqlq,
		29e3ull,
		29f3ull,
		29g3ull,
		293ulql,
		293ulqlq,
		0x,
		0xl,
		0b,
		0b1210ul,
		0b1a10,
		0b1z10,
	};
}
