#include<stdio.h>
void calculatePriority(int n, int bt[], int pr[]){
    int wt[n], tat[n], p[n], temp;

    for (int i = 0; i < n; i++) p[i] = i + 1;

    for (int i = 0; i < n; i++) {   // given lower value = highet priority 
        for (int j = i + 1; j < n; j++) {
            if (pr[i] > pr[j]) {
                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for (int i = 1; i < n; i++) wt[i] = bt[i-1] + wt[i-1];
    for(int i = 0; i<n; i++){
        tat[i] = bt[i] + wt[i];
    }

    printf("\n--- Priority Scheduling ---\n");
    printf("Process\tPriority\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++){
        printf("P%d\t%d\t\t%d\t%d\t%d\n", p[i], pr[i], bt[i], wt[i], tat[i]);
    }
}    

int main() {
    int n = 3;
    int bt[] = {10, 5, 8};
    int pr[] = {2, 1, 3};
    calculatePriority(n, bt, pr);
    return 0;
}