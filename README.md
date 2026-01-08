# HC-SR04

C library for the **HC-SR04 ultrasonic sensor** designed for use with an Arduino Nano (ATmega328P).

This project reads distance measurements from the sensor and displays the results on a **20×4 LCD display**. After each measurement, the processor enters **sleep mode for 4 seconds** to conserve power.

---

## Overview

The HC-SR04 library provides a **simple and modular interface** to:

- Trigger the ultrasonic sensor
- Measure the echo pulse duration
- Convert the pulse to distance in centimeters
- Display the result on a connected 20×4 LCD
- Enter a low-power sleep mode between measurements

The project demonstrates **sensor interfacing, power management, and LCD integration** in embedded systems.

---

## Features

- Trigger and read distance from HC-SR04 ultrasonic sensor
- Display distance on a 20×4 LCD (HD44780-compatible)
- Automatic low-power sleep for 4 seconds after each measurement
- Modular code for easy reuse in other projects
- Tested with Arduino Nano / ATmega328P

---

## Hardware / Environment

- **Microcontroller:** ATmega328P (Arduino Nano)  
- **Development environment:** Atmel Studio  
- **Sensor:** HC-SR04 ultrasonic distance sensor  
- **Display:** LCD 20×4 (HD44780-compatible)

---

## Usage

1. Connect the HC-SR04 sensor to the Arduino Nano (VCC, GND, Trigger, Echo pins).  
2. Connect the 20×4 LCD to the microcontroller using the LCD library.  
3. Initialize the sensor and LCD in your code.  
4. Call the library function to measure distance and display it.  
5. After each measurement, the microcontroller sleeps for 4 seconds to save power.

---

## Status

✔️ **Stable** — tested on Arduino Nano with 20×4 LCD.

---

## License

This project is open-source and intended for **educational and embedded development use**.


---

## Schematics

![Schematic](https://user-images.githubusercontent.com/75970114/150694194-451f47a7-7965-4128-a69a-b9317f4d5747.png)
