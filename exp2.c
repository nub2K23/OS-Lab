#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("\nKernel version: ");
    system("cat /proc/sys/kernel/osrelease");

    printf("\nCPU specifications: \n");
    system("cat /proc/cpuinfo");

    printf("\nSystem uptime: ");
    system("cat /proc/uptime");
    printf("\n");  // add newline for neat output

    return 0;
}
