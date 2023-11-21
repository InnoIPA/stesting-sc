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
bool HDMI_connect(HDMI_OUT *output, char *msg);
void HDMI_screen(HDMI_OUT *output, char *msg);
void HDMI_init(HDMI_OUT *output);
int HDMI_run(char *cfgfile);

#endif /* _HDMI_ */