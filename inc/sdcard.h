// Copyright (c) 2022 Innodisk crop.
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef _SD_CARD_
#define _SD_CARD_
#include "common.h"

/****************************************
 *
 * SDCard struct
 *
 ****************************************/
typedef struct _SDCARD_IN
{
	char DevicePath[MAX_PATH];
	char WritePath[MAX_PATH];
	char FileName[MAX_PATH];
	char DDbs[MAX_PATH];
	char DDcount[MAX_PATH];
} SDCARD_IN;

typedef struct _SDCARD_OUT
{
	int ErrorCode;
	char Type[MAX_PATH];	   // USB_3_0 or USB_2_0 or SD_Card
	char Path[MAX_PATH];	   // UP or DOWN 
	char WriteTime[MAX_PATH];
	char WriteSpeed[MAX_PATH];
} SDCARD_OUT;

/****************************************
 *
 * SDCard function 
 *
 ****************************************/
bool SD_Card_cfg(SDCARD_IN *input, char *cfgfile);
bool SD_Card_chk_device(const SDCARD_IN *input);
void SD_Card_get_dd_info(SDCARD_OUT *output, char *msg);
char *SD_Card_write(const SDCARD_IN *input);
char *SD_Card_rm(const SDCARD_IN *input);
void SD_Card_init(SDCARD_OUT *output);
void SD_Card_result(const SDCARD_OUT *output);
int SD_Card_run(char *cfgfile);

#endif /* _SD_CARD_ */