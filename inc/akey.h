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
	char USB2_TEXT[MAX_PATH];
	char PCIE_Slot[MAX_PATH];
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
char *AKEY_lspci_id(AKEY_IN *input);
char *AKEY_lspci(char *vendorid);
void AKEY_init(AKEY_OUT *output);
bool AKEY_cfg(AKEY_IN *input, char *cfgfile);
void AKEY_result(const AKEY_OUT *output);
int AKEY_run(char *cfgfile);

#endif /* _AKEY_ */