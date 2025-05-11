# Basic Heater Control System – Embedded Systems Intern Assignment

This project simulates a simple heater control system using an **Arduino Uno**, a **DHT22** temperature sensor, a **buzzer**, a **16x2 I2C LCD**, and an **LED** as the heater. It includes real-time temperature monitoring, a state-based control system, and overheat protection, all managed using **Timer1 interrupt**.

---

## 📑 Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Hardware Required](#hardware-required)
- [Software Required](#software-required)
- [System States](#system-states)
- [Libraries Used](#libraries-used)
- [Circuit Diagram](#circuit-diagram)
- [Full Arduino Code](#full-arduino-code)
- [Links](#links)

---

##  Overview

The **Heater Control System** monitors ambient temperature using the DHT22 sensor. Based on predefined temperature ranges, it changes system states such as *Idle*, *Heating*, *Target Reached*, and *Overheat*. It controls an LED (heater), a buzzer (overheat alert), and displays live data on an I2C LCD. Timer1 is used to interrupt every second to ensure periodic sensor readings without using `delay()`.

---

##  Features

- Real-time temperature monitoring
- Simulated heater control (LED)
- Overheat alert using buzzer
- Live status display on I2C LCD
- Periodic sampling using **Timer1 interrupt**
- Serial logging for debugging

---

##  Hardware Required

| Component            | Purpose                              | Arduino Pin           |
|----------------------|--------------------------------------|------------------------|
| Arduino Uno          | Microcontroller                      | —                      |
| DHT22 Sensor         | Temperature input                    | D2                     |
| LED (Heater)         | Simulated heater                     | D3                     |
| Buzzer               | Overheat alert                       | D4                     |
| 16x2 I2C LCD Display | Display temperature and state        | SDA → A4, SCL → A5     |
| 220Ω Resistor        | Current limiting for LED             | —                      |
| Breadboard & Wires   | Connections                          | —                      |

---

## Software Required
- **Arduino IDE** (latest version)
- **DHT sensor library** (Adafruit DHT sensor library)
- **LiquidCrystal_I2C library**
- **TimerOne library**
- **Wokwi Simulation Environment** (https://wokwi.com/)
---

##  System States

| State           | Temperature Range (°C) | Heater (LED) | Buzzer |
|------------------|------------------------|--------------|--------|
| Idle             | < 25                   | ON           | OFF    |
| Heating          | 25 – 34.9              | ON           | OFF    |
| Target Reached   | 35 – 44.9              | OFF          | OFF    |
| Overheat         | ≥ 45                   | OFF          | ON     |

---

##  Libraries Used


#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TimerOne.h>

---

## Circuit Diagram
DHT22 → D2

Heater LED → D3 (with 220Ω resistor)

Buzzer → D4

LCD (I2C) → SDA (A4), SCL (A5)

VCC → 5V

GND → GND

---

## Full Arduino Code

https://github.com/Sachin10036/Basic-Heater-Control-System-/blob/main/Code

---

## Links

🔗 GitHub Repository: https://github.com/Sachin10036/Basic-Heater-Control-System

🔗 Wokwi Simulation: https://wokwi.com/projects/430686060274520065
