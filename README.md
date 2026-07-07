# TinyBrake-STM32 🛑⚡
**TinyML Obstacle Detection & Emergency Braking System on STM32F401VE**

[![Platform](https://img.shields.io/badge/platform-STM32F401VE-blue)](https://www.st.com/en/microcontrollers-microprocessors/stm32f401ve.html)
[![Framework](https://img.shields.io/badge/framework-STM32Cube.AI-green)](https://www.st.com/en/embedded-software/x-cube-ai.html)
[![Quantization](https://img.shields.io/badge/quantization-INT8-red)](#)
[![Simulation](https://img.shields.io/badge/simulation-Proteus%208-lightgrey)](https://www.labcenter.com/)
[![License](https://img.shields.io/badge/license-MIT-yellow)](LICENSE)

**Author:** Sobhan Nasiri  
**Project Status:** Completed (Simulation-based Deployment)  

---

## 📖 Overview
This project implements a **real-time obstacle detection and emergency braking decision system** on a resource-constrained STM32F401VE microcontroller (84 MHz Cortex-M4, 96 KB RAM, 512 KB Flash) using TinyML techniques. The entire pipeline—from model conversion to hardware-software co-simulation—was executed without physical hardware, relying on **Proteus for full-system emulation**.

A pre-trained binary classification model (`model.onnx`) is quantized to **INT8** via STM32Cube.AI, leveraging CMSIS-NN kernels. The embedded firmware processes a simulated 96×96 grayscale image, runs inference, calculates Time-to-Collision (TTC), and drives a Finite State Machine (FSM) to output actuator signals (Warning / Brake).

> ⚠️ **Key Constraint:** All inference, preprocessing, and decision logic must fit within **< 80 KB RAM** and meet strict latency budgets on a microcontroller without an FPU.

---

## 🎯 Key Features
- **End-to-end TinyML deployment** on Arm Cortex-M4 (no RTOS, bare-metal C).
- **INT8 post-training quantization** with memory footprint analysis in Cube.AI.
- **Bitwise & fixed-point preprocessing** to avoid floating-point operations.
- **Finite State Machine (FSM)** with four safety-critical states: `NORMAL`, `WARNING`, `BRAKE`, `SAFE_STOP`.
- **TTC-based risk assessment** (distance / velocity) for deterministic braking logic.
- **Simulated sensor input**: Static test image stored in Flash as a `const` array.
- **Full Proteus virtual prototype** including UART terminal for logging and timing metrics.
- **Cycle-accurate latency measurement** using on-chip SysTick timer (avoiding host OS overhead).

---

## 🧱 Hardware & Software Stack

| Component               | Specification / Tool                                |
|-------------------------|-----------------------------------------------------|
| **Target MCU**          | STM32F401VET6 (Cortex-M4, 84 MHz, 96 KB SRAM)       |
| **AI Framework**        | STM32Cube.AI 8.0+ (CMSIS-NN backend)                |
| **Model Format**        | ONNX → INT8 quantized C code                        |
| **IDE**                 | Keil MDK-ARM (uVision 5)                            |
| **Pin Configuration**   | STM32CubeMX (Clock @84 MHz, USART1 active)          |
| **Simulator**           | Proteus 8 Professional (STM32F401VE model)          |
| **Programming Language**| C (modular, no heap allocations)                    |

---

## 🧠 System Architecture

[Simulated Image] → Preprocessing (fixed-point) → ai_input buffer
→ ai_run() (INT8 CNN) → ai_output (0..1)
→ Risk Assessment (TTC calc) → FSM (state machine)
→ Actuator Signals (Virtual Pins)
│
└─── UART Log: RAM, Latency, TTC, State

### 🧩 Software Modules (app/)
| File               | Responsibility                                 |
|--------------------|------------------------------------------------|
| `sensor_sim.c`     | Provides static 96×96 test image from Flash.   |
| `infer_engine.c`   | Wraps Cube.AI generated functions, manages buffers. |
| `risk_calc.c`      | Converts classifier confidence + fixed d,v to TTC. |
| `fsm_controller.c` | Implements the decision state machine.         |

---


## 🧪 Results & Metrics (Proteus Simulation)

| Metric                          | Value          |
|---------------------------------|----------------|
| **Model Input Size**            | 96×96×1 (grayscale) |
| **Quantization**                | INT8           |
| **Total RAM Used (AI + App)**   | ~74 KB (within 80 KB limit) |
| **Flash Occupancy (weights)**   | ~210 KB        |
| **Inference Latency**           | 38.7 ms (avg)  |
| **Frames Per Second (FPS)**     | ~25.8 FPS      |
| **TTC Threshold**               | 1.2 seconds    |
| **System Reaction Time**        | < 50 ms (from input to GPIO toggle) |

> 📌 All metrics were validated in Proteus using SysTick timer values sent over UART.

---

## 🚀 Getting Started (Replication)

1. **Clone this repo** and open the `.ioc` file in STM32CubeMX; regenerate code if needed.
2. Open the Keil project under `firmware/MDK-ARM/`, ensure Cube.AI library is linked.
3. If required, re-import `model.onnx` into Cube.AI plugin, set INT8 quantization, and regenerate the AI library.
4. Build the project (Target: STM32F401VE) → `.hex` file generated.
5. In Proteus, load the provided schematic, double-click the MCU, and set the program file to the generated `.hex`.
6. Start simulation; observe logs in Virtual Terminal and monitor the state machine via GPIO pins.

---

## ⚡ Challenges & Solutions
- **RAM limitation:** The 96 KB SRAM forced aggressive weight sharing and input buffer reuse. INT8 quantization reduced memory by 4× compared to FP32.
- **Lack of FPU:** All preprocessing math replaced with integer arithmetic and bit shifts.
- **Latency profiling in Proteus:** Used internal SysTick timer to get true inference time, ignoring host OS simulation lag.
- **No camera in simulation:** A static Flash array served as a deterministic test vector.

---

## 📜 License
This project is licensed under the MIT License.

---

## Acknowledgements
- **Sobhan Nasiri** – Embedded AI system design, firmware, and simulation.
- STMicroelectronics for STM32Cube.AI and CMSIS-NN libraries.
- Labcenter Electronics for Proteus simulation environment.

