#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pid, ret, status;
    pid = fork();

    if (pid == 0) {
        // execvp expects (char *file, char *const argv[])
        // Your original call execvp("./", "parent", NULL) is invalid.

        // Since you want to execute the same program, let's exec the current program again
        // with some argument (or just the program itself):
        char *args[] = {"./parent", NULL};  // Replace "./parent" with your actual executable name
        execvp(args[0], args);

        // If execvp fails:
        perror("execvp failed");
        _exit(1);
    } else if (pid > 0) {
        ret = waitpid(pid, &status, 0);
        printf("\n I am in parent \n");
        if (ret == -1) {
            printf("\nError in wait ID \n");
        } else if (ret == pid) {
            printf("I am waiting in parent \n");
        } else {
            printf("Error in fork command \n");
        }
    }

    return 0;
}
