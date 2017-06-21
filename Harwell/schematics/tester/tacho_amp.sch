EESchema Schematic File Version 2
LIBS:overview-rescue
LIBS:4000_3V3
LIBS:4000_5.0
LIBS:74xx
LIBS:power
LIBS:device
LIBS:transistors
LIBS:linear
LIBS:regul
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
LIBS:conn_general
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
LIBS:interface
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
LIBS:onsemi
LIBS:74xgxx
LIBS:ac-dc
LIBS:actel
LIBS:allegro
LIBS:switches
LIBS:Altera
LIBS:analog_devices
LIBS:battery_management
LIBS:bbd
LIBS:brooktre
LIBS:cmos_ieee
LIBS:dc-dc
LIBS:diode
LIBS:elec-unifil
LIBS:ESD_Protection
LIBS:ftdi
LIBS:gennum
LIBS:graphic
LIBS:hc11
LIBS:ir
LIBS:Lattice
LIBS:logo
LIBS:mechanical
LIBS:microchip_dspic33dsc
LIBS:microchip_pic10mcu
LIBS:microchip_pic12mcu
LIBS:microchip_pic16mcu
LIBS:microchip_pic18mcu
LIBS:microchip_pic32mcu
LIBS:motor_drivers
LIBS:motors
LIBS:msp430
LIBS:nordicsemi
LIBS:nxp_armmcu
LIBS:Oscillators
LIBS:powerint
LIBS:Power_Management
LIBS:pspice
LIBS:references
LIBS:relays
LIBS:rfcom
LIBS:sensors
LIBS:silabs
LIBS:stm8
LIBS:stm32
LIBS:supertex
LIBS:transf
LIBS:ttl_ieee
LIBS:video
LIBS:wiznet
LIBS:Worldsemi
LIBS:Xicor
LIBS:zetex
LIBS:Zilog
LIBS:4000
LIBS:overview-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 17 20
Title "Tacometer Amplifier"
Date "2017-04-25"
Rev "000"
Comp "Complete Ions"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel 3800 2250 0    60   Input ~ 0
VDD15.0
Text GLabel 3850 4050 0    60   Input ~ 0
GND
$Comp
L R R375
U 1 1 58FFE858
P 4250 3300
F 0 "R375" V 4330 3300 50  0000 C CNN
F 1 "5K6" V 4250 3300 50  0000 C CNN
F 2 "" V 4180 3300 50  0000 C CNN
F 3 "" H 4250 3300 50  0000 C CNN
	1    4250 3300
	1    0    0    -1  
$EndComp
$Comp
L C C15
U 1 1 58FFE8A5
P 4250 2750
F 0 "C15" H 4275 2850 50  0000 L CNN
F 1 "0.01uF" H 4275 2650 50  0000 L CNN
F 2 "" H 4288 2600 50  0000 C CNN
F 3 "" H 4250 2750 50  0000 C CNN
	1    4250 2750
	1    0    0    -1  
$EndComp
$Comp
L R R378
U 1 1 58FFE8E2
P 4500 3550
F 0 "R378" V 4580 3550 50  0000 C CNN
F 1 "1K" V 4500 3550 50  0000 C CNN
F 2 "" V 4430 3550 50  0000 C CNN
F 3 "" H 4500 3550 50  0000 C CNN
	1    4500 3550
	-1   0    0    1   
$EndComp
Wire Wire Line
	4000 3050 5450 3050
Wire Wire Line
	4250 2900 4250 3150
Connection ~ 4250 3050
Wire Wire Line
	4500 3050 4500 3400
Connection ~ 4500 3050
Wire Wire Line
	4250 3450 4250 4050
Wire Wire Line
	3850 4050 7350 4050
Wire Wire Line
	3800 2250 7050 2250
Wire Wire Line
	4250 2250 4250 2600
Connection ~ 4250 2250
Connection ~ 4250 4050
Wire Wire Line
	4500 3700 4500 4300
$Comp
L ADA4661-2 U23
U 1 1 58FFECE1
P 6050 3100
F 0 "U23" H 6050 2800 60  0000 C CNN
F 1 "ADA4661-2" H 6050 3400 60  0000 C CNN
F 2 "" H 5950 3150 60  0001 C CNN
F 3 "" H 5950 3150 60  0001 C CNN
	1    6050 3100
	1    0    0    -1  
$EndComp
$Comp
L R R377
U 1 1 58FFF88B
P 5100 3450
F 0 "R377" V 5180 3450 50  0000 C CNN
F 1 "15K" V 5100 3450 50  0000 C CNN
F 2 "" V 5030 3450 50  0000 C CNN
F 3 "" H 5100 3450 50  0000 C CNN
	1    5100 3450
	1    0    0    -1  
$EndComp
$Comp
L R R379
U 1 1 58FFF8CC
P 5100 3850
F 0 "R379" V 5180 3850 50  0000 C CNN
F 1 "15K" V 5100 3850 50  0000 C CNN
F 2 "" V 5030 3850 50  0000 C CNN
F 3 "" H 5100 3850 50  0000 C CNN
	1    5100 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 3600 5100 3700
Connection ~ 4850 2250
Wire Wire Line
	5100 4050 5100 4000
Connection ~ 4850 4050
Wire Wire Line
	5450 4050 5450 3250
Connection ~ 5100 4050
Wire Wire Line
	6750 2250 6750 2950
Wire Wire Line
	6750 2950 6700 2950
$Comp
L D D6
U 1 1 58FFFA76
P 4850 2700
F 0 "D6" H 4850 2800 50  0000 C CNN
F 1 "D" H 4850 2600 50  0000 C CNN
F 2 "" H 4850 2700 50  0000 C CNN
F 3 "" H 4850 2700 50  0000 C CNN
F 4 "1N914BWT" H 4850 2700 60  0001 C CNN "Part Number"
	1    4850 2700
	0    1    1    0   
$EndComp
$Comp
L D D8
U 1 1 58FFFAC9
P 4850 3400
F 0 "D8" H 4850 3500 50  0000 C CNN
F 1 "D" H 4850 3300 50  0000 C CNN
F 2 "" H 4850 3400 50  0000 C CNN
F 3 "" H 4850 3400 50  0000 C CNN
F 4 "1N914BWT" H 4850 3400 60  0001 C CNN "Part Number"
	1    4850 3400
	0    1    1    0   
$EndComp
Wire Wire Line
	4850 2250 4850 2550
Wire Wire Line
	4850 2850 4850 3250
Connection ~ 4850 3050
Wire Wire Line
	4850 3550 4850 4050
Wire Wire Line
	5100 3650 5300 3650
Wire Wire Line
	5300 3150 5300 3700
Wire Wire Line
	5300 3150 5450 3150
Connection ~ 5100 3650
$Comp
L D D7
U 1 1 58FFFC0B
P 7050 2700
F 0 "D7" H 7050 2800 50  0000 C CNN
F 1 "D" H 7050 2600 50  0000 C CNN
F 2 "" H 7050 2700 50  0000 C CNN
F 3 "" H 7050 2700 50  0000 C CNN
F 4 "1N914BWT" H 7050 2700 60  0001 C CNN "Part Number"
	1    7050 2700
	0    1    1    0   
$EndComp
$Comp
L D D9
U 1 1 58FFFC4A
P 7050 3500
F 0 "D9" H 7050 3600 50  0000 C CNN
F 1 "D" H 7050 3400 50  0000 C CNN
F 2 "" H 7050 3500 50  0000 C CNN
F 3 "" H 7050 3500 50  0000 C CNN
F 4 "1N914BWT" H 7050 3500 60  0001 C CNN "Part Number"
	1    7050 3500
	0    1    1    0   
$EndComp
Wire Wire Line
	7050 2850 7050 3350
Wire Wire Line
	6700 3050 6750 3050
Wire Wire Line
	6850 3050 8100 3050
Connection ~ 7050 3050
Wire Wire Line
	7050 2250 7050 2550
Connection ~ 6750 2250
$Comp
L R R376
U 1 1 58FFFDD3
P 7700 3300
F 0 "R376" V 7780 3300 50  0000 C CNN
F 1 "22K" V 7700 3300 50  0000 C CNN
F 2 "" V 7630 3300 50  0000 C CNN
F 3 "" H 7700 3300 50  0000 C CNN
	1    7700 3300
	1    0    0    -1  
$EndComp
$Comp
L R R374
U 1 1 58FFFE18
P 8250 3050
F 0 "R374" V 8330 3050 50  0000 C CNN
F 1 "2K2" V 8250 3050 50  0000 C CNN
F 2 "" V 8180 3050 50  0000 C CNN
F 3 "" H 8250 3050 50  0000 C CNN
F 4 "2K2" H 8250 3050 60  0001 C CNN "Part Number"
	1    8250 3050
	0    1    1    0   
$EndComp
$Comp
L C C16
U 1 1 58FFFE6F
P 7350 3300
F 0 "C16" H 7375 3400 50  0000 L CNN
F 1 "0.1uF" H 7375 3200 50  0000 L CNN
F 2 "" H 7388 3150 50  0000 C CNN
F 3 "" H 7350 3300 50  0000 C CNN
	1    7350 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 3050 7350 3150
Wire Wire Line
	7700 3050 7700 3150
Connection ~ 7350 3050
Connection ~ 7700 3050
Wire Wire Line
	7700 3450 7700 3850
Wire Wire Line
	7700 3850 6850 3850
Wire Wire Line
	6850 3850 6850 3250
Wire Wire Line
	6850 3250 6700 3250
Wire Wire Line
	6700 3150 6750 3150
Wire Wire Line
	6750 3050 6750 4300
Wire Wire Line
	5450 2950 5450 2700
Wire Wire Line
	5450 2700 6850 2700
Wire Wire Line
	6850 2700 6850 3050
Wire Wire Line
	6750 4300 4500 4300
Connection ~ 6750 3150
Wire Wire Line
	8400 3050 8600 3050
Text HLabel 8600 3050 2    60   Input ~ 0
TACHO_OUT
Text HLabel 4000 3050 0    60   Input ~ 0
TACHO_IN
Connection ~ 7050 4050
Connection ~ 5450 4050
Wire Wire Line
	7050 4050 7050 3650
Wire Wire Line
	7350 4050 7350 3450
Wire Wire Line
	5100 3300 5100 2250
Connection ~ 5100 2250
$Comp
L CP C17
U 1 1 590057EC
P 5300 3850
F 0 "C17" H 5325 3950 50  0000 L CNN
F 1 "250uF 16V" H 5325 3750 50  0000 L CNN
F 2 "" H 5338 3700 50  0000 C CNN
F 3 "" H 5300 3850 50  0000 C CNN
	1    5300 3850
	1    0    0    -1  
$EndComp
Connection ~ 5300 3650
Wire Wire Line
	5300 4000 5300 4050
Connection ~ 5300 4050
$Comp
L CP C18
U 1 1 5900592B
P 6550 3850
F 0 "C18" H 6575 3950 50  0000 L CNN
F 1 "150uF 16V" H 6100 3750 50  0000 L CNN
F 2 "" H 6588 3700 50  0000 C CNN
F 3 "" H 6550 3850 50  0000 C CNN
	1    6550 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 4050 6550 4000
Connection ~ 6550 4050
Wire Wire Line
	6550 3700 6550 3450
Wire Wire Line
	6550 3450 6850 3450
Connection ~ 6850 3450
Text Notes 6150 4700 2    60   ~ 0
The tacho amp cleans up the signal and\ninverts the signal.\n
$EndSCHEMATC
