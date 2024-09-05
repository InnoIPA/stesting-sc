<!--
 Copyright (c) 2023 innodisk Crop.
 
 This software is released under the MIT License.
 https://opensource.org/licenses/MIT
-->
- [Overview](#overview)
- [GPIO](#gpio)
- [ETH](#eth)
- [USB](#usb)
- [HDMI](#hdmi)
- [SD\_Card](#sd_card)
- [I2C](#i2c)
- [CAN](#can)
- [UART](#uart)
- [MKEY](#mkey)
- [EEPROM](#eeprom)
- [AKEY](#akey)

# Overview
This page shows the meaning of error code for each test case.
# GPIO
- Error code 1  
  `Missing config setting, check the cfg.json.`
- Error code 2  
  `Cannot setting output value, check the voltage of gpio.`
- Error code 3  
  `Read the wrong value, check the voltage of gpio.`
- Error code 4  
  `There are no gpio avalible, check the fpga fw.`

# ETH
- Error code 1  
  `Missing config setting, check the cfg.json.`
- Error code 2  
  `Cannot get IP address, check the LAN connection.`
- Error code 3  
  `Cannot reach specific IP, check the LAN connection.`

# USB
- Error code 1  
  `Missing config setting, check the cfg.json.`
- Error code 2  
  `USB writing speed too low.`
- Error code 3  
  `Cannot detected correct numbers of USB storage.`

# HDMI
- Error code 1  
  `Missing config setting, check the cfg.json.`
- Error code 2  
  `Cannot get the screen information through HDMI.`
- Error code 3  
  `Cannot detected the screen through HDMI.`

# SD_Card
- Error code 1  
  `Missing config setting, check the cfg.json.`
- Error code 2  
  `SD card writing speed too low.`
- Error code 3  
  `Cannot detected the SD card.`

# I2C
- Error code 1  
  `Missing config setting, check the cfg.json.`
- Error code 2  
  `Cannot access I2C device.`
- Error code 3  
  `Cannot detected the I2C device.`

# CAN
- Error code 1  
  `Missing config setting, check the cfg.json.`
- Error code 2  
  `Cannot get the data from tx to rx.`

# UART
- Error code 1  
  `Missing config setting, check the cfg.json.`
- Error code 3  
  `Cannot detected the UART device.`
- Error code 5  
  `UART timeout while receiving data from tx to rx.`

# MKEY
- Error code 1  
  `Missing config setting, check the cfg.json.`
- Error code 3  
  `Cannot detected the MKEY storage.`

# EEPROM
- Error code 1  
  `Missing config setting, check the cfg.json.`
- Error code 3  
  `Cannot access the eeprom.`

# AKEY
- Error code 1  
  `Missing config setting, check the cfg.json.`
- Error code 3  
  `Cannot detected the pcie protocol of AKEY device.`
- Error code 4  
  `Cannot detected the usb2.0 protocol of AKEY device.`

