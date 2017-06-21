EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:analogswitch
LIBS:battery
LIBS:capacitor
LIBS:capacitor-kemet
LIBS:capacitor-trim
LIBS:con-amphenol
LIBS:con-cambdenboss
LIBS:con-external
LIBS:con-jst
LIBS:con-molex
LIBS:conn-3m
LIBS:conn-te
LIBS:con-weidmuller
LIBS:crystal
LIBS:header
LIBS:holes
LIBS:inductor
LIBS:maxim
LIBS:mosfet
LIBS:opamp
LIBS:opto-coupler
LIBS:packages
LIBS:photoswitch
LIBS:potentiometer
LIBS:regulator
LIBS:schottky
LIBS:smelectronics
LIBS:solomon-systech
LIBS:stmicroelectronics
LIBS:transistor
LIBS:trimpot
LIBS:usb
LIBS:zener
LIBS:processor_control_unit-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 11 11
Title "Can Connector"
Date "2017-04-11"
Rev "000"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_01X02 P?
U 1 1 58F054C6
P 3600 3650
F 0 "P?" H 3600 3800 50  0000 C CNN
F 1 "CONN_01X02" V 3700 3650 50  0000 C CNN
F 2 "" H 3600 3650 50  0000 C CNN
F 3 "" H 3600 3650 50  0000 C CNN
	1    3600 3650
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3800 3600 5100 3600
Wire Wire Line
	3800 3700 5100 3700
Text HLabel 5100 3600 2    60   Input ~ 0
RX
Text HLabel 5100 3700 2    60   Output ~ 0
TX
$EndSCHEMATC
