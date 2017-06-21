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
Sheet 9 11
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	6600 2850 3550 2850
Wire Wire Line
	6600 2950 3550 2950
Wire Wire Line
	3550 3050 6600 3050
Wire Wire Line
	3550 2750 6600 2750
Text HLabel 6600 2750 2    60   Input ~ 0
VDD3.3
Text HLabel 6600 2850 2    60   BiDi ~ 0
D+
Text HLabel 6600 2950 2    60   BiDi ~ 0
D-
Text HLabel 6600 3050 2    60   Input ~ 0
GND
$Comp
L CONN_01X04 P?
U 1 1 58F9528D
P 3350 2900
F 0 "P?" H 3350 3150 50  0000 C CNN
F 1 "CONN_01X04" V 3450 2900 50  0000 C CNN
F 2 "con-amphenol:MUSBRA11130" H 3350 2900 50  0000 C CNN
F 3 "" H 3350 2900 50  0000 C CNN
	1    3350 2900
	-1   0    0    -1  
$EndComp
$EndSCHEMATC
