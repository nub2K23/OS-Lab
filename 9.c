#include <stdio.h>

int main()
{
    int i, j, n, temp;
    int p[10], bt[10], at[10], wt[10], tat[10], completed[10];
    float wsum = 0, tsum = 0;
    printf("------- SHORTEST JOB FIRST (NP) --------\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Enter Arrival Time for P%d: ", i + 1);
        scanf("%d", &at[i]);
        p[i] = i + 1;
        completed[i] = 0;
    }
    int time = 0, count = 0;
    while (count < n)
    {
        int min = 9999, idx = -1;
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && !completed[i] && bt[i] < min)
            {
                min = bt[i];
                idx = i;
            }
        }
        if (idx != -1)
        {
            wt[idx] = time - at[idx];
            if (wt[idx] < 0)
                wt[idx] = 0;

            time += bt[idx];
            tat[idx] = time - at[idx];
            completed[idx] = 1;
            wsum += wt[idx];
            tsum += tat[idx];
            count++;
        }
        else
        {
            time++; // CPU idle
        }
    }
    printf("\nProcess\tBurst\tArrival\tWaiting\tTurnaround");
    for (i = 0; i < n; i++)
    {
        printf("\nP%d\t%d\t%d\t%d\t%d", p[i], bt[i], at[i], wt[i], tat[i]);
    }
    printf("\n\nAverage Waiting Time: %.2f", wsum / n);
    printf("\nAverage Turnaround Time: %.2f", tsum / n);
    return 0;
}