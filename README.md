# ARM Bare-Metal Firmware Engine & CPU Status Flag Monitor

A bare-metal C and Assembly firmware implementation for the **ARM7TDMI / LPC2138** architecture built without vendor Hardware Abstraction Layers (HAL) or Real-Time Operating Systems (RTOS).

This project demonstrates low-level startup configuration, vector table initialization, direct memory-mapped register manipulation (`IODIR0`, `IOSET0`, `IOCLR0`), and real-time CPU condition flag decoding ($N, Z, C, V$) via assembly interfaces.

---

## 📌 Key Features
* **Bare-Metal Boot Sequence:** Vector table initialization, stack allocation, and CPU execution mode configuration in ARM Assembly.
* **Low-Level Register Interface:** CPSR status register access using ARM `MRS` instructions.
* **Direct I/O Driver:** Direct bitwise manipulation of Legacy GPIO registers (`IODIR0`, `IOSET0`, `IOCLR0`).
* **Simulation Validated:** Tested and verified in Proteus ISIS using standard 3.3V power rails and active-LOW reset configuration.

---

## 🛠️ System Architecture

```
+-------------------------------------------------------+
|               Startup Code (Startup.s)                |
|  1. Vector Table -> 2. Stack Init -> 3. Branch to main|
+---------------------------+---------------------------+
                            |
                            v
+-------------------------------------------------------+
|               Main Firmware (main.c)                  |
+---------------------------+---------------------------+
                            |
     +----------------------+----------------------+
     |                                             |
     v                                             v
+-----------------------+                     +-----------------------+
| Hardware Drivers      |                     | CPU State Monitor     |
| - Legacy GPIO Driver  |                     | - Assembly Interface  |
| - Software Delays     |                     | - CPSR Flag Parser    |
+-----------------------+                     +-----------------------+
```

---

## 📂 Repository Structure
```text
├── Startup.s           # Vector table & boot logic
├── arm_utils.s         # CPSR status register interface
├── main.c              # Application logic & GPIO drivers
└── Project.pdsprj      # Proteus VSM circuit schematic
```

---

## 🔧 Building & Simulation
1. Clone the repository:
   ```bash
   git clone [https://github.com/Thrisha-M-ECE/ARM-BareMetal-Firmware-Engine.git](https://github.com/Thrisha-M-ECE/ARM-BareMetal-Firmware-Engine.git)
   ```
2. Compile `main.c`, `Startup.s`, and `arm_utils.s` in Keil µVision (`F7`).
3. Open `Project.pdsprj` in Proteus, link the compiled `.hex` file, and run the simulation.
