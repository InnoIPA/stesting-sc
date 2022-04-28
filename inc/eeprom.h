// Copyright (c) 2022 Innodisk crop.
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef _EEPROM_
#define _EEPROM_
#include "common.h"
#include "i2c.h"

/****************************************
 *
 * eeprom function
 *
 ****************************************/
void EEPROM_result(const I2C_OUT *output);
char *EEPROM_read(const I2C_IN *input, const size_t length);
void EEPROM_write(const I2C_IN *input, const char *hexstr);
bool EEPROM_cfg(I2C_IN *input, char *cfgfile);
void EEPROM_init(I2C_OUT *output);
int EEPROM_run(char *cfgfile);

#endif /* _EEPROM_ */