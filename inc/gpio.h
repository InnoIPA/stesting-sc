// Copyright (c) 2022 Innodisk crop.
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef _GPIO_
#define _GPIO_
#include "common.h"

/****************************************
 *
 * GPIO struct
 *
 ****************************************/
typedef struct _GPIO_IN
{
	int Pins[MAX_PATH];
	int PinCnt;
} GPIO_IN;

typedef struct _GPIO_OUT
{
	int ErrorCode;
} GPIO_OUT;

/****************************************
 *
 * GPIO function
 *
 ****************************************/
char *GPIO_export(const int index);
char *GPIO_direction(const int index, const char *direction);
char *GPIO_value_set(const int index, const int value);
char *GPIO_unexport(const int index);
char *GPIO_value_get(const int index);
bool GPIO_judge(const char *cmd, const int value);
void GPIO_init(GPIO_OUT *output);
void GPIO_result(const GPIO_OUT *output);
int GPIO_get_number();
int GPIO_get_start_index();
int GPIO_run(char *cfgfile); // GPIO_run wont read the cfgfile

#endif /* _GPIO_ */