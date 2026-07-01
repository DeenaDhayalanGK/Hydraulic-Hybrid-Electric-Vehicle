# Hydraulic Hybrid Electric Vehicle

An embedded control system for a Hydraulic Hybrid Electric Vehicle (HHEV) that intelligently switches between hydraulic and electric propulsion modes using pressure-based energy management. The project focuses on regenerative braking, efficient power utilization, and real-time control of the Directional Control Valve (DCV).

---

## 📖 Overview

The Hydraulic Hybrid Electric Vehicle (HHEV) project was developed as part of the **CEG Tech Forum** to improve vehicle efficiency by integrating hydraulic energy storage with electric propulsion.

The system captures braking energy through regenerative braking and stores it in a hydraulic accumulator. An embedded controller continuously monitors the accumulator pressure and automatically switches between hydraulic and electric drive modes using a Directional Control Valve (DCV), ensuring efficient energy utilization.

---

## 🎯 Objectives

- Develop an intelligent control system for a Hydraulic Hybrid Electric Vehicle.
- Recover braking energy using regenerative braking.
- Monitor accumulator pressure using a pressure sensor.
- Automatically switch between hydraulic and electric propulsion modes.
- Improve overall vehicle energy efficiency through embedded control.

---

## 🔧 Hardware Used

- Arduino
- Pressure Sensor
- Directional Control Valve (DCV)
- Solenoid Valve
- Hydraulic Accumulator
- BLDC Motor
- Battery Pack
- Hydraulic Motor

---

## 💻 Software Used

- Embedded C
- Arduino IDE

---

## ⚙️ Working Principle

1. During braking, the hydraulic accumulator stores the recovered energy.
2. A pressure sensor continuously monitors the accumulator pressure.
3. The embedded controller evaluates the pressure level.
4. If the accumulator pressure is sufficient, the DCV switches to hydraulic propulsion.
5. Otherwise, the system switches to electric propulsion powered by the battery.
6. The switching process is performed automatically to optimize vehicle efficiency.

---

## 👨‍💻 My Contributions

- Studied the operating principles of the Hydraulic Hybrid Electric Vehicle.
- Designed the control logic for the Directional Control Valve (DCV).
- Developed Embedded C firmware for automatic mode switching.
- Interfaced the pressure sensor to monitor accumulator pressure.
- Implemented control logic for regenerative braking energy management.
- Worked on BLDC motor control, battery management, and solenoid valve interfacing.

---

## 📂 Repository Structure

```
Hydraulic-Hybrid-Electric-Vehicle
│
├── README.md
├── Code/
├── Documentation/
├── Circuit_Diagram/
├── Images/
└── Videos/
```

---

## 📊 Results

The project successfully demonstrates:

- Automatic switching between hydraulic and electric drive modes
- Pressure-based energy management
- Regenerative braking implementation
- Embedded real-time control of the Directional Control Valve (DCV)

> **Project Images**

*(Add prototype images here)*

> **Working Video**

*(Add demonstration video here)*

---

## 🚀 Future Improvements

- Implement CAN communication for automotive integration.
- Migrate the controller to STM32 or ESP32.
- Add real-time telemetry and wireless monitoring.
- Integrate battery State of Charge (SOC) estimation.
- Develop a graphical monitoring dashboard.

---

## 👤 Author

**Deena Dhayalan G K**

B.E. Electronics and Communication Engineering  
College of Engineering Guindy (Anna University)

📧 Email: **dhayalandeena811@gmail.com**

🔗 LinkedIn: **https://www.linkedin.com/in/deenadhayalangk**

💻 GitHub: **https://github.com/DeenaDhayalanGK**
