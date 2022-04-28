// Copyright (c) 2022 Innodisk crop.
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef _LL_
#define _LL_
#include "common.h"

/****************************************
 *
 * Test case struct
 *
 ****************************************/
//typedef int (*INIT)(void);
typedef int (*RUN)(char *);
//typedef int (*RESULT)(void);

typedef struct _testcases
{
	//	INIT init;
	RUN run;
	//	RESULT result;
} TESTCASES;

typedef struct _node NODE;

typedef struct _node
{
	TESTCASES *test;
	NODE *next;
} NODE;

typedef struct _list
{
	NODE *head;
	NODE *first;
} LIST;

//NODE *create_node(TESTCASES *test, INIT i, RUN r, RESULT ret);
NODE *create_node(TESTCASES *test, RUN r);
LIST *create_ll(void);
int add_ll(LIST *l, NODE *n);
int free_ll(LIST *ll);

#endif /* _LL_ */