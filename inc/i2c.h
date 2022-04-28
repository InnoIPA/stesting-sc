// Copyright (c) 2022 Innodisk crop.
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef _I2C_
#define _I2C_
#include "common.h"

/****************************************
 *
 * I2C struct
 *
 ****************************************/
typedef struct _I2C_IN
{
	char BUSID[MAX_PATH];
	char ID[MAX_PATH];
	char Address[MAX_PATH];
	char Data[MAX_PATH];
} I2C_IN;

typedef struct _I2C_OUT
{
	int ErrorCode;
} I2C_OUT;

/****************************************
 *
 * I2C function
 *
 ****************************************/
void I2C_result(const I2C_OUT *output);
char *I2C_read(const char* BUSID, const char *ID, const char *Address);
char *I2C_set(const char* BUSID, const char *ID, const char *Address, const char *Data);
bool I2C_chk_reg(const char *msg);
char *I2C_dump(const char *ID, const char *Address);
bool I2C_cfg(I2C_IN *input, char *cfgfile);
void I2C_init(I2C_OUT *output);
int I2C_run(char *cfgfile);

#endif /* _I2C_ */