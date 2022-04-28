<!--
 Copyright (c) 2022 Innodisk crop.
 
 This software is released under the MIT License.
 https://opensource.org/licenses/MIT
-->

![workflow](https://github.com/aiotads/stesting-sc/actions/workflows/cmake.yml/badge.svg)

# Table of contents
- [Table of contents](#table-of-contents)
- [Overview](#overview)
- [Requirement](#requirement)
- [Usage](#usage)
- [How to install](#how-to-install)
- [How to run](#how-to-run)
- [How to test](#how-to-test)
- [FAQ](#faq)
- [Contribution](#contribution)
- [License](#license)

# Overview
Stesting provide the board io self testing.

# Requirement
Must use `xmutil` to load app before running `stesting`, because some of the IO pinout through PL. 

# Usage
```bash
stesting [-h] [-u] [-d MODES] [-c CONFIG] [-l LOG]

optional arguments:
  -h, show this help message and exit
  -u, run unit-test (need dummy config file)
  -g, run unit-test without config file
  -c, config file path, default is /opt/innodisk/stesting/cfg.json
  -l, log file path, default is /opt/innodisk/stesting/log.json
  -d, debug mode, add MODES for pipline test if in need 
available MODES
  [0] GPIO      [1] ETH     [2] USB     [3] HDMI
  [4] SD_Card   [5] I2C     [6] CAN     [7] UART
  [8] MKEY      [9] EEPROM  [A] AKEY    [q] QUIT 
```

# How to install
Examples of supported combinations of compile are outlined below.
- Compile bin file for x86 with static library  
    `./installSC x86`
- Compile bin file for arm with static library  
    `./installSC arm`
- Compile bin file for x86 with shared library  
    `./installSC x86 shared`
- Compile bin file for arm with shared library  
    `./installSC arm  shared`

# How to run
Examples of supported combinations sorted by input are outlined below.
- Production mode  
    Only production mode will upload the log.json to server after testing.  
    `./stesting`
- Debug mode  
    This mode can select specific IO to test from a simple UI.  
    `./stesting -d`
- Debug mode with pipline debug  
    This mode can test multiple IO in one cmd, for example below cmd will test ethernet, usb, hdmi, uart.  
    `./stesting -d1237`
- Unit-test
    This mode required the folder "unit-test" which contain the dummy data for it.  
     `./stesting -u`
- Select specific config file  
     `./stesting -c/home/root/cfg.json`
- Custiomize output log file  
     `./stesting -l/home/root/custom_log.json`

# How to test
Run the unit-test to test stesting.
- Unit-test mode with dummy cfg.json  
    `./stesting -u`
- Unit-test mode without cfg.json  
    `./stesting -g`

# FAQ

# Contribution
[Contributing](CONTRIBUTING.md)

# License
[MIT](LICENSE)