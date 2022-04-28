// Copyright (c) 2022 Innodisk crop.
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef _UART_
#define _UART_
#include "common.h"

/****************************************
 *
 * UART struct
 *
 ****************************************/
typedef struct _UART_IN
{
	char TX[MAX_PATH];
} UART_IN;

typedef struct _UART_OUT
{
	int ErrorCode;
} UART_OUT;

/****************************************
 *
 * UART function
 *
 ****************************************/
void UART_result(const UART_OUT *output);
int UART_set_attr(int fd, int speed);
void UART_set_blk(int fd, int should_block);
bool UART_cfg(UART_IN *input, char *cfgfile);
void UART_init(UART_OUT *output);
int UART_run(char *cfgfile);

#endif /* _UART_ */