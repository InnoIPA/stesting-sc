<!--
 Copyright (c) 2022 Innodisk crop.
 
 This software is released under the MIT License.
 https://opensource.org/licenses/MIT
-->

![workflow](https://github.com/aiotads/stesting-sc/actions/workflows/cmake.yml/badge.svg)

- [Overview](#overview)
- [Requirement](#requirement)
  - [HW requirement](#hw-requirement)
  - [FW requirement](#fw-requirement)
  - [SW requirement](#sw-requirement)
- [Usage](#usage)
- [How to install](#how-to-install)
  - [Build from source code](#build-from-source-code)
  - [Install by rpm](#install-by-rpm)
- [How to run](#how-to-run)
- [How to test](#how-to-test)
- [Config file setting](#config-file-setting)
  - [Basic setting](#basic-setting)
    - [Board name](#board-name)
    - [Show result](#show-result)
    - [Pretty log.json](#pretty-logjson)
  - [Test Case setting](#test-case-setting)
    - [SDCard](#sdcard)
    - [USB](#usb)
    - [ETH](#eth)
    - [I2C](#i2c)
    - [CAN](#can)
    - [MKEY](#mkey)
    - [AKEY](#akey)
    - [UART](#uart)

# Overview
Stesting provide the board io self testing, some of the io test required jigs.

# Requirement
## HW requirement
- EXMU-X261
- Debug board for EXMU-X261
- Jigs for EXMU-X261  
  There needs a 120 ohm resistor connect between CAN-L and CAN-H, user can turn on one of switch from `sw7` on EXMU-X261 or add resistor on the jig to make it work.
  ![stesting_jig](doc/stesting_jig.png)
## FW requirement
Must use `xmutil` of `xlnx-config.xmutil` to load the firmware of progarmmable logic before running `stesting`, because some of the IO (PCIE, GPIO, I2C, CAN) are pinout through PL. 
## SW requirement
Utility | Suggest Version
---|---
dd | 8.30
fio | 3.16
lspci | 3.6.4
ifconfig | 2.10
i2c-tools | 4.1-2build2 arm64
can-utils | 2018.02.0-1ubuntu1 arm64

# Usage
```bash
stesting [-h] [-u] [-d MODES] [-c CONFIG] [-l LOG]

optional arguments:
  -h, show this help message and exit
  -v, show version of stesting
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
## Build from source code
Examples of supported combinations of compile are outlined below.
The cross compiler could download from [here](https://releases.linaro.org/components/toolchain/binaries/latest-7/aarch64-linux-gnu/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu.tar.xz).
- Download and setup the cross compiler with cmd below.  
    `./installSC cc`
- Compile binary file at host with static library.  
    `./installSC build host static`
- Compile binary file at host with shared library.  
    `./installSC build host shared`
- Compile binary file by cross complier for arm with static library.  
    `./installSC build arm static`
- Compile binary file by cross complier for arm with shared library.  
    `./installSC build arm shared`

Below shows the install success log of console.
![stesting_install](doc/stesting_install.gif)

## Install by rpm
1. Copy the rpm file into the platfrom which is going to install stesting.
2. Install the rpm file by rpm utility
    ```
    sudo rpm -ivh --replacefiles stesting-<type-you-need>.rpm
    ```
    ![stesting_rpm](doc/stesting_rpm.gif)
# How to run
Examples of supported combinations sorted by input are outlined below.
- Production mode (Test all IO).  
    Only production mode will upload the log.json to server after testing.  
    `sudo ./stesting`
- Debug mode.  
    This mode can select specific IO to test from a simple UI.  
    `sudo ./stesting -d`
- Debug mode with pipline debug.  
    This mode can test multiple IO in one cmd, for example below cmd will test ethernet, usb, hdmi, uart.  
    `sudo ./stesting -d1237`
- Select specific config file.  
     `sudo ./stesting -c /home/root/cfg.json`
- Custiomize output log file path.  
     `sudo ./stesting -l /home/root/custom_log.json`  

The test result will show in console as below, follow [this section](#show-result) to modify the cfg.json if result not showing.     
    ![stesting_pass](doc/stesting_pass.png) | ![stesting_fail](doc/stesting_fail.png)

# How to test
Run the unit-test to test stesting, for making sure this utility is correct.
- Unit-test mode with dummy cfg.json  
    `sudo ./stesting -u`
- Unit-test mode without dummy cfg.json  
    `sudo ./stesting -g`

The test result of unit-test should show the pass result in console as below.  
![stesting_pass](doc/stesting_ut.png)

# Config file setting
This section introduced how to customise the config file.
## Basic setting
### Board name
Board name will be record into log.json.
```
"BOARDNAME": "EXMU-X261"
```
### Show result
Switch for showing test result, set `true` to show result from log.json on console.
```
"SHOWRESULT": "false"
```
### Pretty log.json

Switch for makeing log.json pretty, set `true` to show pretty log.json.
```
"PRETTYLOG": "false"
```
## Test Case setting
### SDCard
Parameters of dd and write speed spec.
```
"SDCard": {
    "DEVICEPATH": "/dev/mmcblk1p2",
    "FILENAME": "/SDCard.dd",
    "WRITEPATH": "/mnt",
    "DDBS": "10M",
    "DDCOUNT": "10",
    "WRITECAP": "30"
}
```
### USB
Parameters of dd, write speed spec of usb2.0 3.0 and numbers of usb should be detect.
```
"USB": {
    "FILENAME": "/USB.dd",
    "DDBS": "10M",
    "DDCOUNT": "10",
    "WRITECAP2": "5",
    "WRITECAP3": "5",
    "DEVICECNT": "8"
}
```
### ETH
ETH name and ip to ping. Default will ping board it self.
```
"ETH": {
    "IP": "",
    "NAME": "eth0"
}
```
### I2C
I2C parameters and data to write.  
Below shows the I2C structure of EXMU-X261, user can change the ID to test any deivice on terminal block.  
![stesting_i2c](doc/stesting_i2c.png)
```
"I2C": {
    "ID": "0x74",
    "BUSID": "0",
    "ADDRESS": "0x00",
    "DATA": "0x0f"
}
```
### CAN
CAN bus parameters and baud rates going to be test. 
```
"CAN": {
    "ID": "123",
    "DATA": "1122334455667788",
    "TX": "can1",
    "RX": "can0",
    "SPEED": [
        90000,
        100000,
        120000
    ]
}
```
### MKEY
SSD vendor ID, device name, write speed spec and fio parameters.
```
"MKEY": {
    "SLOT": "0001:01:00.0",
    "DEVICE": "nvme0n1",
    "FIOBS": "10M",
    "FIOSIZE": "10M",
    "WRITECAP": "250"
}
```
### AKEY
AKEY modules pcie(wifi) and usb(bluetooth) vendor ID.
```
"AKEY": {
    "PCIE_Slot": "0000:01:00.0",
    "USB2_TEXT": "Bus 001 Device 004"
}
```
### UART
UART device port to test.
```
"UART": {
    "TX": "/dev/ttyPS0"
}
```
