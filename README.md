# Health Monitoring System for Pregnant Women

This project is an IoT-based portable health monitoring system designed to continuously track vital parameters for pregnant women, including pulse rate, ECG values, and body temperature. The system ensures the well-being of both the mother and fetus by providing real-time monitoring, emergency alerts, and remote data accessibility for healthcare providers.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Code](#code)
- [Future Improvements](#future-improvements)
- [Contributors](#contributors)

## Overview
The Health Monitoring System for Pregnant Women uses IoT technology to provide continuous monitoring and real-time data transmission of health parameters, accessible to healthcare professionals via a central server or mobile app. The system also includes emergency response capabilities, where pressing a panic button sends an alert to designated contacts.

## Features
- **Continuous Monitoring**: Tracks pulse rate, ECG, and body temperature.
- **Emergency Alert**: Includes a panic button to send email alerts to healthcare providers in critical situations.
- **Data Transmission**: Sends data to a Thingspeak server for logging and visualization in real time.
- **Portability**: Built with portability in mind for convenient use by patients.

## Project Structure
- **Sensors**: Pulse Rate Sensor, ECG Sensor, LM35 Temperature Sensor.
- **Microcontroller**: ESP8266 NodeMCU module for Wi-Fi connectivity and data transmission.
- **Emergency System**: Panic button integrated with email alert functionality.

## Hardware Requirements
1. **ESP8266 NodeMCU Module**
2. **Pulse Rate Sensor**: Measures heartbeat rate.
3. **ECG Sensor (AD8232)**: Tracks heart electrical activity.
4. **LM35 Temperature Sensor**: Measures body temperature.
5. **Slide Switch**
6. **Breadboard and Jumper Wires**: For building the circuit.

## Software Requirements
1. **Arduino IDE**: For programming the ESP8266 module.
2. **Thingspeak IoT Platform**: For data logging and visualization.
3. **Wi-Fi Network**: Required for data transmission.

## Installation
1. Clone this repository to your local machine.
    ```bash
    git clone https://github.com/yourusername/Health-Monitoring-System.git
    cd Health-Monitoring-System
    ```
2. Connect the sensors and ESP8266 NodeMCU module according to the provided circuit diagram.
3. Open `code.cpp` in the Arduino IDE, configure your Wi-Fi credentials and Thingspeak API key in the code, and upload it to the ESP8266.

## Usage
1. Once the setup is complete, the system will continuously monitor health parameters and log the data to Thingspeak.
2. The panic button can be pressed in case of emergency, sending an email alert to healthcare contacts.
3. Data is accessible in real-time on the Thingspeak platform.

## Code
- The main code file for this project is [`code.cpp`](code.cpp), which contains the implementation for:
  - Reading sensor data (pulse rate, ECG, temperature).
  - Transmitting data to Thingspeak.
  - Sending emergency alerts.

## Future Improvements
- Integration with additional sensors for comprehensive health monitoring.
- Enhanced data analysis and alerts based on specific health trends.
- Compatibility with electronic health record (EHR) systems for seamless data sharing with healthcare providers.
