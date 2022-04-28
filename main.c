/**
 * Copyright (c) 2022 Innodisk crop.
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h> /* getopt */

#include "parson.h"
#include "unittest.h"
#include "ll.h"

#include "gpio.h"
#include "hdmi.h"
#include "mkey.h"
#include "akey.h"
#include "sdcard.h"
#include "usb.h"
#include "eth.h"
#include "i2c.h"
#include "can.h"
#include "uart.h"
#include "dna.h"
#include "eeprom.h"

#define AUG_HELP		'h' // help
#define AUG_DEBUGMODE	'd'
#define AUG_UNITTEST	'u'
#define AUG_GITHUBCI	'g' // for github action runner, because its not allow fopen(), popen(), system()
#define AUG_SETCONFIG	'c' // select specific config file
#define AUG_SETLOGFIG	'l' // select specific log file

void help()
{
	LOG("stesting [-h] [-u] [-d MODES] [-c CONFIG] [-l LOG]");
	LOG("");
	LOG("optional arguments:");
	LOG("  -h, show this help message and exit");
	LOG("  -u, run unit-test (need dummy config file)");
	LOG("  -g, run unit-test without config file");
	LOG("  -c, config file path, default is /opt/innodisk/stesting/cfg.json");
	LOG("  -l, log file path, default is /opt/innodisk/stesting/log.json");
	LOG("  -d, debug mode, add MODES for pipline test if in need ");
	LOG("available debug MODES");
	LOG("  [0] GPIO      [1] ETH     [2] USB     [3] HDMI");
	LOG("  [4] SD_Card   [5] I2C     [6] CAN     [7] UART");
	LOG("  [8] MKEY      [9] EEPROM  [A] AKEY    [q] Quit");
	LOG("");
	LOG("");
}

bool production(char *cfgfile)
{
	char msg[MAX_PATH] = {0};
	struct timeval startT = {0};
	struct timeval endT = {0};
	unsigned long long starttime = 0;
	unsigned long long endtime = 0;
	unsigned long long totaltime = 0;
	int result = 0;

	log_add("TESTMODE", "production");
	DNA_run();

	gettimeofday(&startT, NULL);
	starttime = (unsigned long long)(startT.tv_sec) * 1000 + (unsigned long long)(startT.tv_usec) / 1000;

	result += GPIO_run(cfgfile);
	result += SD_Card_run(cfgfile);
	result += HDMI_run(cfgfile);
	result += USB_run(cfgfile);
	result += ETH_run(cfgfile);
	result += I2C_run(cfgfile);
	result += CAN_run(cfgfile);
	result += UART_run(cfgfile);
	result += MKEY_run(cfgfile);
	result += EEPROM_run(cfgfile);
	result += AKEY_run(cfgfile);

	gettimeofday(&endT, NULL);
	endtime = (unsigned long long)(endT.tv_sec) * 1000 + (unsigned long long)(endT.tv_usec) / 1000;
	totaltime = endtime - starttime;

	sprintf(msg, "=   Total Test time: %5lld ms   =", totaltime);
	LOG("=================================");
	LOG(msg);
	(result == 0) ? green() : red();
	LOG("=================================");
	(result == 0) ? LOG("=             PASS              =") : LOG("=             FAIL              =");
	LOG("=================================");
	reset_color();

	if (result == 0)
		return true;
	return false;
}

void debug_ui(char* cfgfile)
{
	bool IStop = false;
	bool MenuShow = false;

	log_add("TESTMODE", "debug_bycase");
	DNA_run();

	while (!IStop)
	{
		if (!MenuShow)
		{
			yellow();
			help();
			reset_color();
			MenuShow = true;
		}

		switch (getchar())
		{
			case '0': { GPIO_run(cfgfile); MenuShow = false; } break;
			case '1': { ETH_run(cfgfile); MenuShow = false; } break;
			case '2': { USB_run(cfgfile); MenuShow = false; } break;
			case '3': { HDMI_run(cfgfile); MenuShow = false; } break;
			case '4': { SD_Card_run(cfgfile); MenuShow = false; } break;
			case '5': { I2C_run(cfgfile); MenuShow = false; } break;
			case '6': { CAN_run(cfgfile); MenuShow = false; } break;
			case '7': { UART_run(cfgfile); MenuShow = false; } break;
			case '8': { MKEY_run(cfgfile); MenuShow = false; } break;
			case '9': { EEPROM_run(cfgfile); MenuShow = false; } break;
			case 'A': { AKEY_run(cfgfile); MenuShow = false; } break;
			case 'q': { IStop = true; } break;
		}
	}
}

bool debug_ll(char *cfgfile, char *debug_ll_modes)
{
	LIST *dblist = create_ll();
	TESTCASES db0, db1, db2, db3, db4, db5, db6, db7, db8, db9, dbA;
	char dmodes[MAX_PATH] = {0};
	int dbresult = 0;

	log_add("TESTMODE", "debug_pipline");
	DNA_run();

	sprintf(dmodes, "%s", debug_ll_modes);
	for (int i = 0; i < strlen(debug_ll_modes); i++) // add to link list
	{
		if (dmodes[i] == '0')
			add_ll(dblist, create_node(&db0, GPIO_run));
		else if (dmodes[i] == '1')
			add_ll(dblist, create_node(&db1, ETH_run));
		else if (dmodes[i] == '2')
			add_ll(dblist, create_node(&db2, USB_run));
		else if (dmodes[i] == '3')
			add_ll(dblist, create_node(&db3, HDMI_run));
		else if (dmodes[i] == '4')
			add_ll(dblist, create_node(&db4, SD_Card_run));
		else if (dmodes[i] == '5')
			add_ll(dblist, create_node(&db5, I2C_run));
		else if (dmodes[i] == '6')
			add_ll(dblist, create_node(&db6, CAN_run));
		else if (dmodes[i] == '7')
			add_ll(dblist, create_node(&db7, UART_run));
		else if (dmodes[i] == '8')
			add_ll(dblist, create_node(&db8, MKEY_run));
		else if (dmodes[i] == '9')
			add_ll(dblist, create_node(&db9, EEPROM_run));
		else if (dmodes[i] == 'A')
			add_ll(dblist, create_node(&dbA, AKEY_run));
	}

	while (1) // run dblist
	{
		dbresult += dblist->head->test->run(cfgfile);
		if (dblist->head->next == NULL)
			break;
		dblist->head = dblist->head->next;
	}

	free_ll(dblist);

	if (dbresult != 0)
		return false;
	return true;
}

void stesting_finish(char *logfile)
{
	time_t timep;
	struct tm *p;
	char msg[MAX_PATH] = {0};
	time(&timep);
	p = localtime(&timep);
	sprintf(msg, "%d %d %d,%d:%d:%2d", (1 + p->tm_mon), (p->tm_mday), (1900 + p->tm_year), p->tm_hour, p->tm_min, p->tm_sec);
	log_add("TESTDATE", msg);
	log_save(logfile);
}

bool stesting_init(char *cfgfile)
{
	if (access(cfgfile, F_OK) != 0) // file exists
		return false;
	log_init();
	JSON_Value *Jcfg = json_parse_file(cfgfile);
	log_add("BOARDNAME", json_object_get_string(json_value_get_object(Jcfg), "BOARDNAME"));
	log_add("BOARDID", json_object_get_string(json_value_get_object(Jcfg), "BOARDID"));
	json_value_free(Jcfg);
	log_add("COMPILETIME", __DATE__ ","__TIME__);
	return true;
}

int main(int argc, char *argv[])
{
	// initial 
	int mode = 0;
	char argument = 0;
	char msg[MAX_CMD] = {0};
	char modelist[MAX_PATH] = {0};
	char debug_ll_modes[MAX_PATH] = {0};
	char cfgfile[MAX_PATH] = {0};
	char logfile[MAX_PATH] = {0};

	strcpy(cfgfile, CFGFILE); // select default config file
	strcpy(logfile, LOGFILE); // select default logfile file

	// parsing augments
	if (argv[1] != NULL)
	{
		sprintf(modelist, "%c%c%c%c::%c:%c:", AUG_HELP, AUG_UNITTEST, AUG_GITHUBCI, AUG_DEBUGMODE, AUG_SETCONFIG, AUG_SETLOGFIG);
		while (argument = getopt(argc, argv, modelist))
		{
			if (argument == -1 || argument == 255)
				break;
			else
			{
				switch (argument)
				{
				case AUG_UNITTEST: 						// unit-test
					mode = UNITTEST;
					break;
				case AUG_GITHUBCI: 						// github ci unit-test
					mode = UNITTESTCI;
					break;
				case AUG_DEBUGMODE:						// debugmode
					if (optarg != NULL) 			
					{
						mode = DEBUGMODELINKLIST;
						strcpy(debug_ll_modes, optarg);
					}
					else
						mode = DEBUGMODE;
					break;
				case AUG_SETCONFIG:					 
					strcpy(cfgfile, optarg);
					break;
				case AUG_SETLOGFIG:					   
					strcpy(logfile, optarg);
					break;
				case AUG_HELP:					   
					help();
					return 0;
					break;
				}
			}
		}
	}

	// stesting initial and check the cfg
	if(mode == UNITTEST || mode == UNITTESTCI)
	{
	}
	else if(stesting_init(cfgfile) == false)
	{
		red();
		LOG("config file not exist:");
		LOG(cfgfile);
		reset_color();				   
		help();
		return -1;
	}

	// select mode and run
	switch (mode)
	{
	case PRODUCTION:
		production(cfgfile);
		break;
	case DEBUGMODE:
		debug_ui(cfgfile);
		break;
	case DEBUGMODELINKLIST:
		debug_ll(cfgfile, debug_ll_modes);
		break;
	case UNITTEST:
		UNITTEST_run(false);
		break;
	case UNITTESTCI:
		UNITTEST_run(true);
		break;
	}

	// save the log file
	if(mode == PRODUCTION || mode == DEBUGMODE || mode == DEBUGMODELINKLIST)
	{
		stesting_finish(logfile);
	}

	// upload the log file
	if(mode == PRODUCTION)
	{
		if(log_upload(cfgfile, logfile) == true)
		{
			green();
			LOG("success upload log file");
		}
		else
		{
			red();
			LOG("fail to upload log file");
		}
		reset_color();
	}

#ifdef DEBUGLOG
	if (argv[1] != NULL)
	{
		sprintf(msg,"cat %s",logfile);
		system(msg);
	}
#endif

	return 0;
}