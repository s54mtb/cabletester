# Downloading firmware
Cable tester has jumpers to enable the bootloader. There is no on-board hardware for downloading the firmware (like arduino) to keep the cost of the device down. 

## Required tools

### Hardware
USB to UART interface is required tool for downloading the firmware. Just make surte it has 3,3V levels. Something like this works fine:

![USB to UART interface](https://raw.githubusercontent.com/s54mtb/cabletester/main/img/usbuart.jpg)


### Software
Install STM flash loader demonstrator:  https://www.st.com/en/development-tools/flasher-stm32.html

## Procedure

Remove power supply. Remove all jumpers if placed. 

### Enable bootloader
Place only JB jumper to enable bootloader. 

![JB jumper](https://raw.githubusercontent.com/s54mtb/cabletester/main/img/JB.JPG)

### Connect serial interface
Three connections are required between USB/UART interface and cable tester: 

* Blue wire: GND
* Green wire (Rx un USB/UART interface), connect to JS2 (PA9/PA11)
* Yellow wire (Tx on USB/UART interface), connect to JS1 (PA10/PA12)

![serial connection](https://raw.githubusercontent.com/s54mtb/cabletester/main/img/bootloadinterface.jpg)

Now power-up the circuit and connect serial interface to USB port. 

### Load the software
Run the installed STM32 flasher demonstrator. Select the UART interface: 

![Select uart](https://raw.githubusercontent.com/s54mtb/cabletester/main/img/bootloader/55-selectuart.JPG)

If all is connected and powered up correctly, the application should notice "Target readable": 

![Target readable](https://raw.githubusercontent.com/s54mtb/cabletester/main/img/bootloader/66-targetisreadable.JPG)

Now select the target device: 

![Target device](https://raw.githubusercontent.com/s54mtb/cabletester/main/img/bootloader/77-sELECTDEVICE.JPG)

Select the option "Download to device". Next, select [the hex file](https://raw.githubusercontent.com/s54mtb/cabletester/main/SW/Objects/cabltestr10.hex): 

![Select hex](https://raw.githubusercontent.com/s54mtb/cabletester/main/img/bootloader/88-selectHEX.JPG)

Hit button "Next". The programming should finish successfully with the notice: 

![Finished](https://raw.githubusercontent.com/s54mtb/cabletester/main/img/bootloader/99%20-%20finished.JPG)


## Finalize

Remove power from the device. 

Remove jumper JB and UART interface. Place jumper to select the number of channels. 

Power the device, connect the cable and test the operation. 


# Alternative

Use ST-link (integrated on nucleo or discovery board or stand-alone) or any other SWD interface to program via SWD interface. The pinout is shown above. I tested with ST-link, nucleo and U-Link interface with success. 
