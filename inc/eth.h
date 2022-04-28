// Copyright (c) 2022 Innodisk crop.
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef _ETH_
#define _ETH_
#include "common.h"

/****************************************
 *
 * ETH struct
 *
 ****************************************/
typedef struct _ETH_IN
{
	char IP[MAX_PATH];
	char Name[MAX_PATH];
} ETH_IN;

typedef struct _ETH_OUT
{
	char IP[MAX_PATH];
	char MAC[MAX_PATH];
	int ErrorCode;
} ETH_OUT;

/****************************************
 *
 * ETH function
 *
 ****************************************/
void ETH_result(const ETH_OUT *output);
bool ETH_ping(const ETH_IN *input, ETH_OUT *output);
void ETH_get_mac(char *msg, ETH_OUT *output);
void ETH_get_ip(char *msg, ETH_OUT *output);
bool ETH_ifconfig(const ETH_IN *input, ETH_OUT *output);
bool ETH_cfg(ETH_IN *input, char *cfgfile);
void ETH_init(ETH_OUT *output);
int ETH_run(char *cfgfile);

#endif /* _ETH_ */