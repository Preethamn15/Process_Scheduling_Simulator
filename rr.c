#include <stdio.h>
#include "color.h"

struct ProcessRR {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int waiting;
    int turnaround;
    int completed;
};

void roundRobin() {
    int n, q;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Time Quantum: ");
    scanf("%d", &q);

    struct ProcessRR p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d %d", &p[i].arrival, &p[i].burst);
        p[i].remaining = p[i].burst;
        p[i].waiting = 0;
        p[i].turnaround = 0;
        p[i].completed = 0;
    }

    int time = 0, done = 0;
    int colors[] = {11, 12, 14, 10, 13};
    printf("\nGantt Chart:\n");

    // Array to store segments for timeline
    typedef struct {
        int start;
        int end;
        int pid; // -1 for idle
    } Segment;

    Segment gantt[1000];
    int segCount = 0;

    while (done < n) {
        int executed = 0;
        for (int i = 0; i < n; i++) {
            if (p[i].remaining > 0 && p[i].arrival <= time) {
                // Determine execution time
                int exec_time = (p[i].remaining < q) ? p[i].remaining : q;

                // Add segment
                gantt[segCount].start = time;
                gantt[segCount].end = time + exec_time;
                gantt[segCount].pid = p[i].pid;
                segCount++;

                time += exec_time;
                p[i].remaining -= exec_time;

                if (p[i].remaining == 0) {
                    p[i].completed = 1;
                    p[i].turnaround = time - p[i].arrival;
                    p[i].waiting = p[i].turnaround - p[i].burst;
                    done++;
                }
                executed = 1;
            }
        }
        if (!executed) {
            // CPU idle until next process arrives
            int nextArrival = 1e9;
            for (int i = 0; i < n; i++)
                if (!p[i].completed && p[i].arrival > time && p[i].arrival < nextArrival)
                    nextArrival = p[i].arrival;

            gantt[segCount].start = time;
            gantt[segCount].end = nextArrival;
            gantt[segCount].pid = -1; // idle
            segCount++;

            time = nextArrival;
        }
    }

    // Print Gantt chart
    for (int i = 0; i < segCount; i++) {
        if (gantt[i].pid == -1) {
            setColor(8); // Gray for idle
            printf("|");
            for (int j = gantt[i].start; j < gantt[i].end; j++)
                printf(" idle ");
        } else {
            setColor(colors[(gantt[i].pid - 1) % 5]);
            printf("|");
            for (int j = gantt[i].start; j < gantt[i].end; j++)
                printf("=");
            printf("P%d", gantt[i].pid);
            for (int j = gantt[i].start; j < gantt[i].end; j++)
                printf("=");
        }
    }
    setColor(15);
    printf("|\n");

    // Print timeline
    printf("Time: ");
    for (int i = 0; i < segCount; i++)
        printf("%d\t", gantt[i].start);
    printf("%d\n\n", gantt[segCount - 1].end);

    // Display process table
    printf("+-----+--------+-------+---------+------------+\n");
    printf("| PID | Arrival | Burst | Waiting | Turnaround |\n");
    printf("+-----+--------+-------+---------+------------+\n");
    float total_wait = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        printf("| P%-3d| %-7d| %-6d| %-8d| %-10d|\n", p[i].pid, p[i].arrival, p[i].burst, p[i].waiting, p[i].turnaround);
        total_wait += p[i].waiting;
        total_tat += p[i].turnaround;
    }
    printf("+-----+--------+-------+---------+------------+\n");

    printf("\nAverage Waiting Time = %.2f\n", total_wait / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);
}
