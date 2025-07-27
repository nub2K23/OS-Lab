#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\n The Configured  Memory is:\n");
    system("cat /proc/meminfo | awk 'NR==1{print $2}'\n");
    printf("\n Amount of Free Memory:\n");
    system("cat /proc/meminfo | awk 'NR==2{print $2}'\n ");
    printf("\n Amount of used Memory:\n");
    system("cat /proc/meminfo | awk '{if(NR==1) a=$2;if(NR==2) b=$2} END{print ab}'\n");
}
