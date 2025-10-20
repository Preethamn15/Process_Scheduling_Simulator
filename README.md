# Process Scheduling Simulator

## Project Overview

The **Process Scheduling Simulator** is a console-based C program that simulates **CPU scheduling algorithms** commonly used in Operating Systems. It helps users:

- Understand different scheduling techniques.
- Visualize **Gantt charts** of process execution.
- Calculate **Waiting Time** and **Turnaround Time**.
- Demonstrate **idle CPU handling** and time quantum in Round Robin scheduling.

This project is designed to help students learn **Process Control** concepts and **Unix/Windows system calls**.

---

## Implemented Scheduling Algorithms

1. **FCFS (First Come First Serve)**
   - Executes processes in the order they arrive.
   - Non-preemptive and simple to understand.

2. **SJF (Shortest Job First)**
   - Executes the process with the shortest burst time first.
   - Non-preemptive implementation in this project.

3. **Round Robin (RR)**
   - Each process is assigned CPU for a fixed **time quantum**.
   - Preemptive and fair scheduling for all processes.
   - Shows idle CPU time when no process is ready.

4. **Priority Scheduling**
   - Processes are scheduled based on **priority value**.
   - Lower number = higher priority (modifiable in code).

---

## Features

- **Interactive Main Menu**
  - Users can select the scheduling algorithm.
  - Easy-to-read, visually appealing layout with colored text.
  
- **Gantt Chart Visualization**
  - Displays execution order of processes.
  - Shows idle CPU time clearly.
  - Enhanced with colored blocks for each process.

- **Detailed Process Table**
  - Columns: PID, Arrival Time, Burst Time, Waiting Time, Turnaround Time.
  - Computes **Average Waiting Time** and **Average Turnaround Time**.

- **Cross-Platform Console Colors**
  - Uses `windows.h` for colored output (adjustable).

---

## Prerequisites

- **Operating System:** Windows (console program uses Windows API for colors)
- **Compiler:** GCC (MinGW or similar)
- **Knowledge:** Basic understanding of C programming

---


---

## **Compilation & Execution** 
1. Open Command Prompt or PowerShell in the project directory.
2. Compile all files:
   ```bash
   gcc main.c fcfs.c sjf.c rr.c priority.c color.c -o scheduler.exe
3. Run the program:
   ```bash
   .\scheduler.exe




## License

This project is open source. Feel free to use, modify, or share for educational purposes.

Author
Preetham N
GitHub: https://github.com/Preethamn15
Email: preethamn2004@gmail.com






