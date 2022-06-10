// Copyright (c) 2022 Innodisk crop.
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef _USB_
#define _USB_
#include "common.h"

/****************************************
 *
 * USB struct
 *
 ****************************************/
typedef struct _USB_IN
{
	char DevicePath[MAX_PATH];
	char WritePath[MAX_PATH];
	char FileName[MAX_PATH];
	char DDbs[MAX_PATH];
	char DDcount[MAX_PATH];
	char WriteCap2[MAX_PATH]; // MB
	char WriteCap3[MAX_PATH]; // MB
	int DeviceCnt;
} USB_IN;

typedef struct _USB_OUT
{
	int ErrorCode;
	char Type[MAX_PATH];	   // USB_3_0 or USB_2_0 or SD_Card
	char Path[MAX_PATH];	   // UP or DOWN 
	char WriteTime[MAX_PATH];
	char WriteSpeed[MAX_PATH];
} USB_OUT;

/****************************************
 *
 * USB struct
 *
 ****************************************/
void USB_result(const USB_OUT *output, int devnum);
void USB_rm(const USB_IN *input);
bool USB_chk_speed(const USB_IN *input, const USB_OUT *output);
void USB_get_dd_info(USB_OUT *output, char *msg);
char *USB_write(const USB_IN *input);
void USB_get_write_path(USB_IN *input, USB_OUT *output, char *msg);
bool USB_chk_type(const char *port, USB_OUT *output);
char *USB_chk_port(const char *msg, USB_IN *input);
bool USB_chk_fs(const char *msg);
FILE *USB_blkid();
bool USB_cfg(USB_IN *input, char *cfgfile);
void USB_init(USB_OUT *output);
int USB_run(char *cfgfile);

#endif /* _USB_ */