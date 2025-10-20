#include <stdio.h>
#include "color.h"

void fcfs();
void sjf();
void roundRobin();
void priorityScheduling();

int main() {
    int choice;
    while(1){
        setColor(11);
        printf("\n+----------------------------------------+\n");
        printf("|           PROCESS SCHEDULER            |\n");
        printf("+----------------------------------------+\n");
        setColor(15);
        printf("| 1. FCFS (First Come First Serve)       |\n");
        printf("| 2. SJF (Shortest Job First)            |\n");
        printf("| 3. Round Robin (RR)                    |\n");
        printf("| 4. Priority Scheduling                 |\n");
        printf("| 5. Exit                                |\n");
        printf("+----------------------------------------+\n");
        setColor(15);
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: fcfs(); break;
            case 2: sjf(); break;
            case 3: roundRobin(); break;
            case 4: priorityScheduling(); break;
            case 5: return 0;
            default: printf("Invalid Choice!\n");
        }
    }
}
