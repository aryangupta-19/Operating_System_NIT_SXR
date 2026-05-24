// rocess ID
// Arrival Time
// Burst Time
// Completion Time
// Turnaround Time
// Waiting Time

// instead of arrays  // cleaner approach
#include<stdio.h>
void calculateFcfs(int n, int bt[]){
    int wt[n], tat[n];
    float totalWt = 0, totalTat = 0;

    wt[0] = 0;
    for(int i = 1; i<n; i++){       // note initialised with i = 1
        wt[i] = wt[i-1] + bt[i-1];
    }

    for(int i = 0; i<n; i++){
        tat[i] = wt[i] + bt[i];
        totalWt += wt[i];
        totalTat += tat[i];
    }

    printf("\n        FCFS Scheduling         \n");
    printf("Process, tBurst, tWaitting, tTurnArround \n");
    for(int i =0; i<n; i++){
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    printf("Average Waiting Time: %.2f\n", totalWt / n);
    printf("Average Turnaround Time: %.2f\n", totalTat / n);
}

int main(){
    int n = 3;
    int bt[] = {10, 5, 9} ;
    calculateFcfs(n, bt);
    return 0;
}