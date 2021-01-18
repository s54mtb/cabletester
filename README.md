# cabletester, simple cable testing tool

This is simple cable testing tool for checking your cables (e.g. ethernet cpatch cables or house installation).  Complete tester consists of two modules and tested cable. Master (left) module is on the left. It is connected to the power supply (battery or wall adapter). Slave (right) is passive and has only LEDs. 
![Cable tester](https://raw.githubusercontent.com/s54mtb/cabletester/main/img/sys.JPG)

If cable is OK, the leds should run in ordered sequence: 
![LED Sequence](https://raw.githubusercontent.com/s54mtb/cabletester/main/img/8_channel_cable_tester.gif)

Youtube video: https://youtu.be/-cTYe7WnijU

## Hardware

### Schematic
![Cable tester schematic](https://raw.githubusercontent.com/s54mtb/cabletester/main/img/KabelTester-shema_final.JPG)

### PCB
![Cable tester single sided PCB](https://raw.githubusercontent.com/s54mtb/cabletester/main/img/protopcb.JPG)

### Artwork for toner transfer PCB
PDF for home made PCB with toner transfer (multiple and single PCB) is available [here](https://github.com/s54mtb/cabletester/blob/main/img/Lantester-tonertransfer.pdf).

## Software
Initial project is prepared with free keil uVision for stm32f0 family.

## Housing
Work in progress.