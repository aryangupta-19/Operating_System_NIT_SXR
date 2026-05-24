#include<stdio.h>
void calculateSjf(int n, int bt[]){
    int wt[n], tat[n], p[n], temp;

    for(int i = 0; i<n; i++){   // numbered process accordingly 
        p[i] = i+1;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(bt[i] > bt[j]){
                // swap bt
                temp = bt[i], bt[i] = bt[j], bt[j] = temp;
                // swap process
                temp = p[i], p[i] = p[j], p[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for(int i = 1; i<n; i++){       // note initialised with i = 1
        wt[i] = wt[i-1] + bt[i-1];
    }

    for(int i = 0; i<n; i++){
        tat[i] = wt[i] + bt[i];
    }

    printf("\n        SJF Scheduling         \n");
    printf("Process, tBurst, tWaitting, tTurnArround \n");
    for(int i =0; i<n; i++){
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
}

int main(){
    int n = 3;
    int bt[] = {10, 5, 9} ;
    calculateSjf(n, bt);
    return 0;
}