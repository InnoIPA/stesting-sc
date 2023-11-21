<!--
 Copyright (c) 2023 innodisk Crop.
 
 This software is released under the MIT License.
 https://opensource.org/licenses/MIT
-->

# Config file setting
This section introduced how to customise the config file.
## Basic setting
### Board name
Board name will be record into log.json.
```json
"BOARDNAME": "EXMU-X261"
```
### Show result
Switch for showing test result, set `true` to show result from log.json on console.
```json
"SHOWRESULT": "false"
```
### Pretty log.json

Switch for makeing log.json pretty, set `true` to show pretty log.json.
```json
"PRETTYLOG": "false"
```
## Test Case setting
### SDCard
Parameters of dd and write speed spec.
```json
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
Parameters of dd, write speed spec of usb2.0 3.0 and usb devices which should be test. The path of usb port could be get from `udevadm`.
```json
"USB": {
    "FILENAME": "/USB.dd",
    "DDBS": "10M",
    "DDCOUNT": "10",
    "WRITECAP2": "5",
    "WRITECAP3": "5",
    "DEVICES": {
        "USB0" : "/devices/platform/axi/ff9d0000.usb0/fe200000.usb/xhci-hcd.1.auto/usb2/2-1/2-1.2/2-1.2:1.0/host0",
        "USB1" : "/devices/platform/axi/ff9d0000.usb0/fe200000.usb/xhci-hcd.1.auto/usb2/2-1/2-1.1/2-1.1:1.0/host0",
        "USB2" : "/devices/platform/axi/ff9d0000.usb0/fe200000.usb/xhci-hcd.1.auto/usb2/2-1/2-1.4/2-1.4:1.0/host0",
        "USB3" : "/devices/platform/axi/ff9d0000.usb0/fe200000.usb/xhci-hcd.1.auto/usb2/2-1/2-1.3/2-1.3:1.0/host0"
    }
}
```
### ETH
ETH name and ip to ping. Default will ping board it self.
```json
"ETH": {
    "IP": "",
    "NAME": "eth0"
}
```
### I2C
I2C parameters and data to write.  
Below shows the I2C structure of EXMU-X261, user can change the ID to test any deivice on terminal block.  
![stesting_i2c](doc/stesting_i2c.png)
```json
"I2C": {
    "ID": "0x74",
    "BUSID": "0",
    "ADDRESS": "0x00",
    "DATA": "0x0f"
}
```
### CAN
CAN bus parameters and baud rates going to be test. 
```json
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
```json
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
```json
"AKEY": {
    "PCIE_Slot": "0000:01:00.0",
    "USB2_TEXT": "Bus 001 Device 004"
}
```
### UART
UART device port to test.
```json
"UART": {
    "TX": "/dev/ttyPS0"
}
```
