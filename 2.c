#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\n The kernel version:\n");
    system("cat /proc/sys/kernel/osrelease");
    printf("\n The CPU space:\n");
    system("cat /proc/cpuinfo");
    printf("\n Amount of CPU time since system was last booted is:\n");
    system("cat /proc/uptime\n");
}
