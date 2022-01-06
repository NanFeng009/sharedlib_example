#include "tstlib.h"
#include <unistd.h>

struct tree treetest(struct tree* t)
{
	if(t->left != NULL) treetest(t->left);
	if(t->right != NULL) treetest(t->right);

	t->x++;

	return *t;
}

void looptest(loop_a_t* a)
{
	a->x++;
	a->b->x++;
}

int enumtest(enum E a, E_t b)
{
	return a == b;
}

double arraytest(struct witharray* s)
{
	return s->x[0];
}
