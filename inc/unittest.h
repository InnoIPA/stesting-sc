// Copyright (c) 2022 Innodisk crop.
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef _UT_
#define _UT_
#include "common.h"

int UNITTEST_run(bool github);
bool UT_SD_Card(int *pass, int *fail, bool github);
bool UT_HDMI(int *pass, int *fail, bool github);
bool UT_GPIO(int *pass, int *fail, bool github);
bool UT_USB(int *pass, int *fail, bool github);
bool UT_ETH(int *pass, int *fail, bool github);
bool UT_I2C(int *pass, int *fail, bool github);
bool UT_CAN(int *pass, int *fail, bool github);
bool UT_UART(int *pass, int *fail, bool github);
bool UT_MKEY(int *pass, int *fail, bool github);
bool UT_EEPROM(int *pass, int *fail, bool github);
bool UT_AKEY(int *pass, int *fail, bool github);

#endif /* _UT_ */