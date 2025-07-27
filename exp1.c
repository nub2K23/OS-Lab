#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pid, ret, status;
    pid = fork();

    if (pid == 0)
    {
        // exevp("./child",NULL); // same program different code
        execl("./", "parent", NULL); // same program same code
    }

    else if (pid > 0)
    {
        ret = waitpid(pid, &status, 0);
        printf("\n I am in parent \n");
        if (ret == -1)
            printf("\nError in wait ID \n");
        else if (ret == pid)
            printf("I am waiting in parent \n");
    }

    else
    {
        printf("Error in fork command \n");
    }
    return 0;
}
