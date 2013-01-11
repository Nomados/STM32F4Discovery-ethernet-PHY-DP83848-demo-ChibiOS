*****************************************************************************
** ChibiOS/RT port for ARM-Cortex-M4 STM32F407.                            **
*****************************************************************************

** TARGET **

The demo runs on an STM32F4DISCOVERY board + DP83848 ETHERNET PHY. Wires 
connections described in board.h file. This demo use Chibios 2.5.0 from git 
repository.

** The Demo **

The demo currently flashes a LED using a thread and serves HTTP requests
at address 192.168.0.136 on port 80. Webserver is a port of ST appnote from 
FreeRTOS to ChibiOS.
The button activates the ChibiOS/RT test suite, output on SD3.

** Build Procedure **

The demo has been tested by using the free Codesourcery GCC-based toolchain
and YAGARTO.
Just modify the TRGT line in the makefile in order to use different GCC ports.

** Notes **

Some files used by the demo are not part of ChibiOS/RT but are copyright of
ST Microelectronics and are licensed under a different license.
Also note that not all the files present in the ST library are distributed
with ChibiOS/RT, you can find the whole library on the ST web site:

                             http://www.st.com

Demo was provided by DeusExMachina aka Nomados
ganeev.arthur@gmail.com
https://github.com/Nomados/STM32F4Discovery-ethernet-PHY-DP83848-demo--ChibiOS-
