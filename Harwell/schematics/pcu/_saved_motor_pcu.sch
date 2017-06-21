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
LIBS:maxim
LIBS:microchip_pic18mcu
LIBS:microchip_pic24mcu
LIBS:microchip_pic32mcu
LIBS:crystal
LIBS:motor_speed_controller-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_01X06 J?
U 1 1 593653DD
P 9000 5400
F 0 "J?" H 9000 5750 50  0000 C CNN
F 1 "CONN_01X06" V 9100 5400 50  0000 C CNN
F 2 "" H 9000 5400 50  0001 C CNN
F 3 "" H 9000 5400 50  0001 C CNN
	1    9000 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 4750 8250 4750
Wire Wire Line
	8250 4750 8250 5150
Wire Wire Line
	8250 5150 8800 5150
Wire Wire Line
	8800 5250 8350 5250
Wire Wire Line
	8350 5250 8350 1400
Wire Wire Line
	8350 1400 5750 1400
Wire Wire Line
	5750 1400 5650 1400
Wire Wire Line
	5650 1400 3800 1400
Wire Wire Line
	3750 5350 5650 5350
Wire Wire Line
	5650 5350 5750 5350
Wire Wire Line
	5750 5350 8800 5350
Wire Wire Line
	5650 5050 5650 5350
Connection ~ 5650 5350
Wire Wire Line
	5750 5050 5750 5350
Connection ~ 5750 5350
$Comp
L PIC18F4550-I/P U?
U 1 1 5936563D
P 5750 3650
F 0 "U?" H 4850 4950 50  0000 C CNN
F 1 "PIC18F4550-I/P" H 6300 2350 50  0000 C CNN
F 2 "Housings_DIP:DIP-40_W15.24mm" H 5750 3850 50  0001 C CIN
F 3 "" H 5750 3400 50  0001 C CNN
	1    5750 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 2250 5650 1400
Connection ~ 5650 1400
Wire Wire Line
	5750 2250 5750 1400
Connection ~ 5750 1400
Wire Wire Line
	4650 4250 4550 4250
Wire Wire Line
	4550 4250 4550 5450
Wire Wire Line
	4550 5450 8800 5450
Wire Wire Line
	4650 4150 4450 4150
Wire Wire Line
	4450 4150 4450 5550
Wire Wire Line
	4450 5550 8800 5550
$Comp
L Crystal_Small XT1
U 1 1 593659EE
P 3750 3350
F 0 "XT1" H 3750 3450 50  0000 C CNN
F 1 "4MHz" H 3750 3250 50  0000 C CNN
F 2 "Crystals:Crystal_IQD_HC49-4HSMX" H 3750 3350 50  0001 C CNN
F 3 "" H 3750 3350 50  0001 C CNN
	1    3750 3350
	1    0    0    -1  
$EndComp
$Comp
L C_Small C?
U 1 1 59365ACC
P 3500 3600
F 0 "C?" H 3510 3670 50  0000 L CNN
F 1 "16pF" H 3510 3520 50  0000 L CNN
F 2 "" H 3500 3600 50  0001 C CNN
F 3 "" H 3500 3600 50  0001 C CNN
	1    3500 3600
	1    0    0    -1  
$EndComp
$Comp
L C_Small C?
U 1 1 59365B25
P 3950 3600
F 0 "C?" H 3960 3670 50  0000 L CNN
F 1 "16pF" H 3960 3520 50  0000 L CNN
F 2 "" H 3950 3600 50  0001 C CNN
F 3 "" H 3950 3600 50  0001 C CNN
	1    3950 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 3500 3500 3350
Wire Wire Line
	3500 3350 3650 3350
Wire Wire Line
	3850 3350 3950 3350
Wire Wire Line
	3950 3350 4650 3350
Wire Wire Line
	3950 3500 3950 3350
Connection ~ 3950 3350
Wire Wire Line
	3500 3700 3500 3800
Wire Wire Line
	3500 3800 3750 3800
Wire Wire Line
	3750 3800 3950 3800
Wire Wire Line
	3950 3800 3950 3700
Wire Wire Line
	3750 5350 3750 3800
Connection ~ 3750 3800
$EndSCHEMATC
