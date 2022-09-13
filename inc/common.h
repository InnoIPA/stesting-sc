/**
 * Copyright (c) 2022 Innodisk crop.
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#ifndef _COMMON_
#define _COMMON_

#define STESTING_VERSION "v0.0.3"
#define STESTING_HASH "2286779319449f747d31e93b68d01c03ba9a80ab"

#define MAX_CMD 4096
#define MAX_PATH 256
#define LOGFILE "/opt/innodisk/stesting/log.json"
#define CFGFILE "/opt/innodisk/stesting/cfg.json"

#define LOG(Msg) printf("%s\n", Msg)
#define DLOG(Msg) printf("[%s][%s][%d] %s\n", __FILE__, __FUNCTION__, __LINE__, Msg)

/****************************************
 *
 * Error Code
 *
 ****************************************/
enum ERROR_CODE
{
	OK,
	MISSING_CFG,
	FAILED,
	NOT_FOUND_DEVICE,
	INVALID,
	TIMEOUT,
};

/****************************************
 *
 * Modes
 *
 ****************************************/
enum MODES
{
	PRODUCTION,
	DEBUGMODE,
	DEBUGMODELINKLIST,
	UNITTEST,
	UNITTESTCI,
};

/****************************************
 *
 * log Function
 *
 ****************************************/
void log_init();
void log_add(const char *name, const char *string);
void log_save(char *logfile, char *pretty);
void log_case_init(const char *name, const int result);
void log_case_detail(const char *detail);
void log_case_save();

/****************************************
 *
 * log upload Function
 *
 ****************************************/
_Bool log_upload(const char *cfgfile, const char *logfile);

/****************************************
 *
 * log.json viewer
 *
 ****************************************/
void log_show(char *logfile);

/****************************************
 *
 * stesting function
 *
 ****************************************/
void stesting_finish(char *logfile);
_Bool stesting_init(char *cfgfile);

/****************************************
 *
 * color Function
 *
 ****************************************/
void reset_color();
void blue();
void red();
void green();
void yellow();

/****************************************
 *
 * other Function
 *
 ****************************************/
char *pwd();
void str2hexStr(const char *input, char *output);
char *strbetween(char* input, char* niddle_L, char* niddle_R);
#endif /* _COMMON_ */