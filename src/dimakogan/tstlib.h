#pragma once

struct tree
{
	int x;
	struct tree* left;
	struct tree* right;
};

struct tree treetest(struct tree* t);

struct loop_a;
struct loop_b;

typedef struct loop_a {struct loop_b* b; int x;}loop_a_t;
struct loop_b{loop_a_t* a; int x;};

void looptest(loop_a_t* a);

enum E{A, B, C};
typedef enum E E_t;

int enumtest(enum E a, E_t b);

struct witharray
{
	double x[5];
};

double arraytest(struct witharray* s);
