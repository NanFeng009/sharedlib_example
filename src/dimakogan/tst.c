#include "tstlib.h"
#include <unistd.h>

void main(void)
{
	struct tree d = {.x = 4};
	struct tree c = {.x = 3, .right = &d};
	struct tree b = {.x = 2};
	struct tree a = {.x = 1, .left = &b, .right = &c};
	treetest( &a );

	struct loop_a la = {.x = 5};
	struct loop_b lb = {.x = 6};
	la.b = &lb;
	lb.a = &la;
	looptest(&la);

	enum E ea = A, eb = B;
	enumtest(ea, eb);

	struct witharray s = {.x = {1.0, 2.0, 1.0, 2.0, 1.0}};
	arraytest( &s );
}


