# IoT-Based Ambulatory Vital Signs Data Transfer System

## Problem Description
In emergency medical situations, delays in monitoring and treating patients can cause their condition to worsen rapidly. Such delays may lead to severe complications, increased pain, and potentially life-threatening consequences. In ambulatory environments like ambulances, the lack of continuous and real-time monitoring of vital signs reduces the chances of timely medical intervention. Therefore, a reliable system is required to continuously monitor a patient’s vital parameters and provide immediate alerts during critical conditions.

## Aim and Objectives

### Aim
The aim of this project is to develop an **IoT-based ambulatory vital signs data transfer system** for seamless monitoring of a patient’s health and to provide timely alerts in case of medical emergencies.

### Objectives
- To continuously monitor vital signs of patients inside an ambulance.
- To measure critical parameters such as **heart rate, ECG, and SpO₂ levels** in real time.
- To transmit patient health data wirelessly for remote monitoring.
- To generate alerts when abnormal vital signs are detected.
- To improve response time and increase the chances of saving lives during emergency situations.

## Components Used
- ESP8266 NodeMCU Board
- AD8232 ECG Sensor
- MAX30100 Pulse Oximeter Sensor
- Arduino IDE
- MATLAB Online
- ThingSpeak IoT Platform

## Libraries Used
- Wire.h – Used for I²C communication with the MAX30100 sensor
- MAX30100_PulseOximeter.h – Used to measure heart rate and SpO₂ levels
- ThingSpeak.h – Used for transmitting sensor data to the ThingSpeak IoT platform
- ESP8266WiFi.h – Used to enable Wi-Fi connectivity on the ESP8266 NodeMCU

## System Workflow
The IoT-based ambulatory vital signs data transfer system integrates the **MAX30100 pulse oximeter sensor** and **AD8232 ECG sensor** with the **ESP8266 NodeMCU** to continuously monitor SpO₂ levels, heart rate, and ECG parameters.

Using the Arduino IDE, the NodeMCU transmits the acquired sensor data to a **ThingSpeak IoT channel**, enabling real-time visualization and remote access. The incoming data stream is further analyzed using **MATLAB Online**, where predefined threshold values are applied. Whenever abnormal vital signs are detected, alerts are generated to notify healthcare professionals.

This remote monitoring capability allows caregivers and medical personnel to intervene promptly, potentially preventing adverse health events. By combining efficient hardware integration with powerful software analytics, the system ensures accurate data processing, reliable transmission, and continuous patient monitoring.

## Description of the Proposed Method
- The system enables **early detection of health abnormalities**, supporting proactive medical intervention.
- Continuous remote monitoring enhances **patient safety and quality of care** while reducing the workload on healthcare professionals.
- Integration with widely accessible platforms such as **ThingSpeak** and **MATLAB Online** ensures scalability, flexibility, and ease of adoption.
- The solution is suitable for diverse healthcare environments, including **ambulances, hospitals, clinics, and home healthcare settings**.

## Applications
- Ambulance-based patient monitoring
- Emergency healthcare services
- Postoperative patient care
- Chronic disease monitoring
- Elderly healthcare support

## Significance of the Project
This project addresses a critical requirement in modern healthcare by enabling real-time, remote patient monitoring during emergency transport. By ensuring timely alerts and continuous observation of vital signs, the system improves healthcare outcomes, enhances patient safety, and contributes to efficient medical decision-making in the digital age.
