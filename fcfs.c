#include <stdio.h>
#include "color.h"

struct ProcessFCFS {
    int pid;
    int arrival;
    int burst;
    int waiting;
    int turnaround;
};

void fcfs() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct ProcessFCFS p[n];
    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        printf("Enter Arrival Time and Burst Time for P%d: ", i+1);
        scanf("%d %d",&p[i].arrival,&p[i].burst);
        p[i].waiting=0;
        p[i].turnaround=0;
    }

    // Sort by arrival time
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(p[i].arrival>p[j].arrival){
                struct ProcessFCFS temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }

    int time=0;
    int colors[]={11,12,14,10,13};
    typedef struct{
        int start,end,pid;
    }Segment;
    Segment gantt[1000];
    int segCount=0;

    for(int i=0;i<n;i++){
        if(time<p[i].arrival){
            gantt[segCount].start=time;
            gantt[segCount].end=p[i].arrival;
            gantt[segCount].pid=-1;
            segCount++;
            time=p[i].arrival;
        }
        gantt[segCount].start=time;
        gantt[segCount].end=time+p[i].burst;
        gantt[segCount].pid=p[i].pid;
        segCount++;

        p[i].waiting=time-p[i].arrival;
        time+=p[i].burst;
        p[i].turnaround=p[i].waiting+p[i].burst;
    }

    // Print Gantt chart
    printf("\nGantt Chart:\n");
    for(int i=0;i<segCount;i++){
        if(gantt[i].pid==-1){
            setColor(8);
            printf("| idle ");
        } else{
            setColor(colors[(gantt[i].pid-1)%5]);
            printf("| P%d ",gantt[i].pid);
        }
    }
    setColor(15);
    printf("|\nTime: ");
    for(int i=0;i<segCount;i++) printf("%d\t",gantt[i].start);
    printf("%d\n\n",gantt[segCount-1].end);

    // Table
    printf("+-----+--------+-------+---------+------------+\n");
    printf("| PID | Arrival | Burst | Waiting | Turnaround |\n");
    printf("+-----+--------+-------+---------+------------+\n");
    float total_wait=0,total_tat=0;
    for(int i=0;i<n;i++){
        printf("| P%-3d| %-7d| %-6d| %-8d| %-10d|\n",p[i].pid,p[i].arrival,p[i].burst,p[i].waiting,p[i].turnaround);
        total_wait+=p[i].waiting;
        total_tat+=p[i].turnaround;
    }
    printf("+-----+--------+-------+---------+------------+\n");
    printf("\nAverage Waiting Time = %.2f\n",total_wait/n);
    printf("Average Turnaround Time = %.2f\n",total_tat/n);
}
