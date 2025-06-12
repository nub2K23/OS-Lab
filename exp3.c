#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("\nConfigured Memory: ");
    system("cat /proc/meminfo | awk 'NR==1{print $2}'\n");

    printf("\nFree memory availabe: ");
    system("cat /proc/meminfo | awk 'NR==2{print $2}'\n");

    printf("\nMemory used: ");
    system("cat /proc/meminfo | awk '{if(NR==1) a =$2;if(NR==2) b=$2} END{print a-b}'\n");
    
}
