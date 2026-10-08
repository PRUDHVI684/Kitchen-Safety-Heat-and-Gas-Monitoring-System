# Kitchen Safety Heat and Gas Monitoring System

## 📌 Project Overview

The Kitchen Safety Heat and Gas Monitoring System is an embedded safety
system developed using the LPC2148 microcontroller.

The system continuously monitors kitchen temperature and gas levels,
detects hazardous conditions, provides buzzer and LED alerts, records
the most recent safety event with RTC timestamp information, and
provides a password-protected Edit Mode for modifying system parameters.

## 🎯 Objectives

- Continuously monitor kitchen temperature using the LM35 sensor.
- Detect gas leakage using the MQ2 sensor.
- Generate alerts when unsafe conditions are detected.
- Display sensor readings and RTC information on a 16x2 LCD.
- Record the most recent safety event with timestamp information.
- Provide password-protected Edit Mode.
- Allow modification of threshold values and RTC settings.
- Provide a low-cost embedded safety solution for kitchen environments.

## 🧰 Hardware Requirements

- LPC2148 Microcontroller
- 16x2 LCD
- 4x4 Matrix Keypad
- LM35 Temperature Sensor
- MQ2 Gas Sensor
- Switches
- LEDs
- Buzzer
- USB-UART Converter / DB9 Cable

## 💻 Software Requirements

- Embedded C
- Keil MDK
- Flash Magic
- Proteus (if used for simulation)

## ⚙️ System Working

The LPC2148 continuously monitors temperature and gas levels using its
on-chip ADC.

### Temperature Monitoring

The LM35 sensor is used to measure the kitchen temperature. The measured
temperature is compared with the configured temperature threshold.

### Gas Monitoring

The MQ2 sensor is used to detect combustible gases such as LPG, methane
and smoke. The sensor value is compared with the configured gas threshold.

### Alert Mechanism

When an unsafe condition is detected:

- The buzzer is activated.
- LED indication is provided.
- The safety event is recorded.

### RTC Event Logging

When temperature or gas crosses its configured set point from a safe
condition to an unsafe condition, the system records the:

- Sensor name
- Measured value
- RTC time
- Date
