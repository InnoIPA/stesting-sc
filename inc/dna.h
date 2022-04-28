// Copyright (c) 2022 Innodisk crop.
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef _DNA_
#define _DNA_
#include "common.h"


char *DNA_memread(const int address);
char *DNA_read(const int address);
bool DNA_get_address(int *address);
int DNA_run();

#endif /* _DNA_ */