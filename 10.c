#include <stdio.h>

int main()
{
    int i, j, time, sum_wait = 0, sum_turnaround = 0, smallest, n;
    int at[20], bt[20], pt[20], rt[20], remain;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    remain = n;

    for (i = 0; i < n; i++)
    {
        printf("Enter Arrival Time, Burst Time and Priority for Process P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pt[i]);
        rt[i] = bt[i];
    }

    printf("\nProcess\t|\tTurnaround Time\t|\tWaiting Time\n");

    for (time = 0; remain != 0; time++)
    {
        int highest_priority = 9999;
        smallest = -1;

        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && rt[i] > 0 && pt[i] < highest_priority)
            {
                highest_priority = pt[i];
                smallest = i;
            }
        }

        if (smallest == -1)
            continue;

        rt[smallest]--;

        if (rt[smallest] == 0)
        {
            remain--;
            int turnaround = time + 1 - at[smallest];
            int waiting = turnaround - bt[smallest];
            sum_turnaround += turnaround;
            sum_wait += waiting;

            printf("P%d\t|\t%d\t\t|\t%d\n", smallest + 1, turnaround, waiting);
        }
    }

    printf("\nAverage Waiting Time = %.2f\n", sum_wait * 1.0 / n);
    printf("Average Turnaround Time = %.2f\n", sum_turnaround * 1.0 / n);

    return 0;
}