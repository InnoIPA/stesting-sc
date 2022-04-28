// Copyright (c) 2022 Innodisk crop.
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef _AKEY_
#define _AKEY_
#include "common.h"

/****************************************
 *
 * AKEY struct
 *
 ****************************************/
typedef struct _AKEY_IN
{
	char USB2_VENDOR[MAX_PATH];
	char PCIE_VENDOR[MAX_PATH];
} AKEY_IN;

typedef struct _AKEY_OUT
{
	char Status[MAX_PATH];
	int ErrorCode;
} AKEY_OUT;

/****************************************
 *
 * AKEY function
 *
 ****************************************/
void AKEY_link_state(char *lspci, AKEY_OUT *output);
char *AKEY_lspci(AKEY_IN *input);
void AKEY_init(AKEY_OUT *output);
bool AKEY_cfg(AKEY_IN *input, char *cfgfile);
void AKEY_result(const AKEY_OUT *output);
int AKEY_run(char *cfgfile);

#endif /* _AKEY_ */