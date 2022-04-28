// Copyright (c) 2022 Innodisk crop.
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef _MKEY_
#define _MKEY_
#include "common.h"

/****************************************
 *
 * MKEY struct
 *
 ****************************************/
typedef struct _MKEY_IN
{
	char VendorID[MAX_PATH];
	char Device[MAX_PATH];
	//char ReadCap[MAX_PATH];
	char WriteCap[MAX_PATH]; // MB
	char Fio_BS[MAX_PATH];
	char Fio_Size[MAX_PATH];
} MKEY_IN;

typedef struct _MKEY_OUT
{
	//char ReadSpeed[MAX_PATH];
	char WriteSpeed[MAX_PATH];
	char Status[MAX_PATH];
	int ErrorCode;
} MKEY_OUT;

/****************************************
 *
 * MKEY function
 *
 ****************************************/
void MKEY_result(const MKEY_OUT *output);
bool MKEY_cfg(MKEY_IN *input, char *cfgfile);
void MKEY_init(MKEY_OUT *output);
char *MKEY_lspci(MKEY_IN *input);
void MKEY_link_state(char *lspci, MKEY_OUT *output);
char *MKEY_fio(char *rw, MKEY_IN *input);
void MKEY_fio_result(char *lspci, MKEY_OUT *output);
bool MKEY_speed_check(const MKEY_OUT *output, double gap_MBps);
int MKEY_run(char *cfgfile);

#endif /* _MKEY_ */