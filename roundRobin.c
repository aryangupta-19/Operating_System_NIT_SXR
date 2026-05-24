#include<stdio.h>

void calculateRoundRobin(int n, int q, int bt[]){
    int wt[n], tat[n], t = 0, remBt[n];

    for(int i = 0; i<n; i++){
        remBt[i] = bt[i];
        wt[i] = 0;
    }

    while(1){
        int done = 1; 
        for(int i = 0; i<n; i++){
            if(remBt[i] > 0){
                done = 0; 
                if(remBt[i] > q){
                    t += q;
                    remBt[i] -= q;
                }else{
                    t += remBt[i];
                    wt[i] = t - bt[i];      // current time - burst time 
                    remBt[i]  = 0;
                }
            }
        }

        if(done == 1) break;
    }

    printf("\n--- Round Robin (Quantum: %d) ---\n", q);
    printf("Process\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }
}

int main(){
    int n = 3;
    int bt[] = {10, 9, 8};
    int q = 2;
    calculateRoundRobin(n, q, bt);
    return 0;
}