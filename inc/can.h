// Copyright (c) 2022 Innodisk crop.
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef _CAN_
#define _CAN_
#include "common.h"


/****************************************
 *
 * CAN struct
 *
 ****************************************/
typedef struct _CAN_IN
{
	char TX[MAX_PATH]; // device name
	char RX[MAX_PATH]; // can bus only
	char ID[MAX_PATH];
	char Data[MAX_PATH];
	int Speed[MAX_PATH];
} CAN_IN;

typedef struct _CAN_OUT
{
	int ErrorCode;
} CAN_OUT;

/****************************************
 *
 * CAN function
 *
 ****************************************/
void CAN_result(const CAN_OUT *output);
char *CAN_send(const char *TX, const char *ID, const char *Data);
char *CAN_dump(const char *RX);
char *CAN_up(const char *Name, const int Speed);
char *CAN_down(const char *Name);
bool CAN_cfg(CAN_IN *input, char *cfgfile);
void *CAN_pthread_dump(void *arg);
void CAN_init(CAN_OUT *output);
bool CAN_speed(const CAN_IN *input, const int bitrate);
int CAN_run(char *cfgfile);

#endif /* _CAN_ */