#include <stdio.h>

int main() {
    int n, i, j;
    int at[20], bt[20], ct[20], tat[20], wt[20], p[20];
    int completed[20] = {0}, time = 0, min_bt, idx;
    float avg_tat = 0, avg_wt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter Arrival Time and Burst Time for P%d: ", p[i]);
        scanf("%d%d", &at[i], &bt[i]);
    }

    int completed_count = 0;
    while(completed_count < n) {
        min_bt = 9999;
        idx = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && !completed[i] && bt[i] < min_bt) {
                min_bt = bt[i];
                idx = i;
            }
        }

        if(idx != -1) {
            time += bt[idx];
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            completed[idx] = 1;
            completed_count++;

            avg_tat += tat[idx];
            avg_wt += wt[idx];
        } else {
            time++; // No process is ready, move time forward
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT");
    for(i = 0; i < n; i++) {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\n\nAverage Turnaround Time: %.2f", avg_tat / n);
    printf("\nAverage Waiting Time: %.2f\n", avg_wt / n);

    return 0;
}
