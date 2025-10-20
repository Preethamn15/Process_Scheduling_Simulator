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

## Project Structure
Process_Scheduling_Simulator/
│
├── main.c # Main menu and program entry
├── fcfs.c # First Come First Serve scheduling implementation
├── sjf.c # Shortest Job First scheduling implementation
├── rr.c # Round Robin scheduling implementation
├── priority.c # Priority Scheduling implementation
├── color.c # Console color functions

---

## **Compilation & Execution** 
1. Open "VS Code" **Command Prompt** or **PowerShell** in project directory. 
2. Compile all files: In Terminal type: 
   1) gcc main.c fcfs.c sjf.c rr.c priority.c color.c -o scheduler.exe 
   2) .\scheduler.exe

## Sample Interaction
+----------------------------------------+
| 1. FCFS (First Come First Serve)       |
| 2. SJF (Shortest Job First)            |
| 3. Round Robin (RR)                    |
| 4. Priority Scheduling                 |
| 5. Exit                                |
+----------------------------------------+
Enter your choice: 3
Enter number of processes: 3
Enter Time Quantum: 3
Enter Arrival Time and Burst Time for P1: 2 5
Enter Arrival Time and Burst Time for P2: 0 3
Enter Arrival Time and Burst Time for P3: 1 4

Gantt Chart:
| idle |===P2===|==P3==|===P1===|
Time: 0 1       4       7       12

+-----+--------+-------+---------+------------+
| PID | Arrival| Burst | Waiting | Turnaround |
+-----+--------+-------+---------+------------+
| P1  | 2      | 5     | 5       | 10         |
| P2  | 0      | 3     | 0       | 3          |
| P3  | 1      | 4     | 3       | 7          |
+-----+--------+-------+---------+------------+

Average Waiting Time = 2.67
Average Turnaround Time = 6.67


License

This project is open source. Feel free to use, modify, or share for educational purposes.

Author
Preetham N
GitHub: https://github.com/Preethamn15
Email: preethamn2004@gmail.com

