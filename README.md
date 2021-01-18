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

## Operation
There are several jumpers available to control operation of the tester. 

### JS1 - Speed
JS1 selects the speed of sequence. When jumper is attached, the sequence is slow or fast when removed:
![Fast sequence](https://raw.githubusercontent.com/s54mtb/cabletester/main/img/fast.gif)

### JS2 - Cross/straight
JS2 select sequence: When not present the sequence is "normal": Ch1, Ch2, ... Chn. When Jumper is present, the sequnence is set for cross linked cable (useful for testing crosslink patch cables). 

### JMP2 - Channel selection
The cable tester has 10 channels. The channel sequence can ruun from 2 to maximum 10 channels. Jumper JMP2 defines number of channels. Inserted jumper bridge defines where the sequence will stop. When bridge is inserted between pins 13 and 14 (Channel 8), the sequence will run up to 8th channel. Example of the sequence when jumper is placed on channel 5: 
![5 channels enabled](https://raw.githubusercontent.com/s54mtb/cabletester/main/img/4_channel_cable_tester.gif)

