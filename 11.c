#include <stdio.h>

int main()
{
    int a[20], b[20], rt[20], i, smallest, count = 0, time, n;
    float total_wait = 0, total_tat = 0;
    int finish_time, wt[20], tat[20];
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Arrival Times:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter Burst Times:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
        rt[i] = b[i];
    }
    while (count != n)
    {
        int min_time = 9999;
        smallest = -1;
        for (i = 0; i < n; i++)
        {
            if (a[i] <= time && rt[i] > 0 && rt[i] < min_time)
            {
                min_time = rt[i];
                smallest = i;
            }
        }
        if (smallest == -1)
        {
            time++;
            continue;
        }
        rt[smallest]--;
        time++;
        if (rt[smallest] == 0)
        {
            count++;
            finish_time = time;
            tat[smallest] = finish_time - a[smallest];
            wt[smallest] = tat[smallest] - b[smallest];
            total_wait += wt[smallest];
            total_tat += tat[smallest];
        }
    }
    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, a[i], b[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time = %.2f\n", total_wait / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);
    return 0;
}