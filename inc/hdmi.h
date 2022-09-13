// Copyright (c) 2022 Innodisk crop.
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef _HDMI_
#define _HDMI_
#include "common.h"

/****************************************
 *
 * HDMI struct
 *
 ****************************************/
typedef struct _HDMI_IN
{
	char Kernel[MAX_PATH];
} HDMI_IN;

typedef struct _HDMI_OUT
{
	int ErrorCode;
	char Address[MAX_PATH];
	char ScreenSize[MAX_PATH];
} HDMI_OUT;

/****************************************
 *
 * HDMI function
 *
 ****************************************/
void HDMI_result(const HDMI_OUT *output);
void HDMI_addr(const HDMI_IN *input, HDMI_OUT *output, char *msg);
bool HDMI_connect(HDMI_OUT *output, char *msg);
void HDMI_screen(HDMI_OUT *output, char *msg);
bool HDMI_cfg(HDMI_IN *input, char *cfgfile);
void HDMI_init(HDMI_OUT *output);
int HDMI_run(char *cfgfile);

#endif /* _HDMI_ */