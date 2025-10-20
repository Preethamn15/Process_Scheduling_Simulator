#include <stdio.h>
#include "color.h"

struct ProcessSJF {
    int pid;
    int arrival;
    int burst;
    int waiting;
    int turnaround;
    int completed;
};

void sjf() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    struct ProcessSJF p[n];
    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        printf("Enter Arrival Time and Burst Time for P%d: ",i+1);
        scanf("%d %d",&p[i].arrival,&p[i].burst);
        p[i].waiting=0;
        p[i].turnaround=0;
        p[i].completed=0;
    }

    int time=0,done=0;
    int colors[]={11,12,14,10,13};
    typedef struct{int start,end,pid;}Segment;
    Segment gantt[1000]; int segCount=0;

    while(done<n){
        int idx=-1,minBurst=1e9;
        for(int i=0;i<n;i++){
            if(!p[i].completed && p[i].arrival<=time){
                if(p[i].burst<minBurst){
                    minBurst=p[i].burst;
                    idx=i;
                }
            }
        }
        if(idx==-1){
            int nextArrival=1e9;
            for(int i=0;i<n;i++)
                if(!p[i].completed && p[i].arrival>time && p[i].arrival<nextArrival)
                    nextArrival=p[i].arrival;
            gantt[segCount].start=time; gantt[segCount].end=nextArrival; gantt[segCount].pid=-1; segCount++;
            time=nextArrival;
        }else{
            gantt[segCount].start=time; gantt[segCount].end=time+p[idx].burst; gantt[segCount].pid=p[idx].pid; segCount++;
            p[idx].waiting=time-p[idx].arrival;
            time+=p[idx].burst;
            p[idx].turnaround=p[idx].waiting+p[idx].burst;
            p[idx].completed=1;
            done++;
        }
    }

    // Print Gantt
    printf("\nGantt Chart:\n");
    for(int i=0;i<segCount;i++){
        if(gantt[i].pid==-1){ setColor(8); printf("| idle "); }
        else{ setColor(colors[(gantt[i].pid-1)%5]); printf("| P%d ",gantt[i].pid); }
    }
    setColor(15); printf("|\nTime: ");
    for(int i=0;i<segCount;i++) printf("%d\t",gantt[i].start);
    printf("%d\n\n",gantt[segCount-1].end);

    // Table
    printf("+-----+--------+-------+---------+------------+\n");
    printf("| PID | Arrival | Burst | Waiting | Turnaround |\n");
    printf("+-----+--------+-------+---------+------------+\n");
    float total_wait=0,total_tat=0;
    for(int i=0;i<n;i++){
        printf("| P%-3d| %-7d| %-6d| %-8d| %-10d|\n",p[i].pid,p[i].arrival,p[i].burst,p[i].waiting,p[i].turnaround);
        total_wait+=p[i].waiting; total_tat+=p[i].turnaround;
    }
    printf("+-----+--------+-------+---------+------------+\n");
    printf("\nAverage Waiting Time = %.2f\n",total_wait/n);
    printf("Average Turnaround Time = %.2f\n",total_tat/n);
}
